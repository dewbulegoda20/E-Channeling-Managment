#include "Display.h"
#include "DataBase.h"
#include "Access.h"

namespace View {
	class Ui {
	private:
		Display display;

	public:
		void appInit() {
			display.startApp();
		}

		char printGetOptionUi() {
			char opt = display.getOption();
			return opt;
		}

		char printGoBackUi() {
			return display.goBack();
		}

		//===========================================================
		//===================     patient ui      ===================
		//===========================================================

		void showPatientUi() {
			display.patientOpt();
		}

		Patient addNewPatientUi(DataBase& db) {
			return display.getPatient(db);
		}

		string cancelAppoinmentUi() {
			return display.cancelAppoinment();
		}



		//===========================================================
		//====================     doctor ui      ===================
		//===========================================================

		void showDoctorUi(DataBase& db) {
			display.doctorOpt(db);
		}


	};

}

namespace Model {
	class Storage {
	private:
		Access access;

	public:
		DataBase& retrieveDataModal(DataBase& db) {
			return access.retrieveData(db);
		}

		DataBase& addNewPatientModal(DataBase& db, Patient patient) {
			return access.addNewPatient(db, patient);
		}

		DataBase& cancelAppoinmentModal(DataBase& db, string patient) {
			return access.cancelAppoinment(db, patient);
		}



	};

}

namespace Controller {
	class Logic {

	private:
		Model::Storage* s;
		View::Ui* u;
		DataBase db;
	public:

		Logic(Model::Storage* s, View::Ui* u) {
			this->s = s;
			this->u = u;

			doLogic();

		}

		void doLogic() {

			db = s->retrieveDataModal(db);

			while (true)
			{
				u->appInit();
				char opt = u->printGetOptionUi();

				switch (opt)
				{
				case 'p': showPatientUiController(); break;
				case 'd': showDoctorUiController(); break;
				case 'e': exit(-1);

				default:
					cout << "Display a valid input....." << endl;
					break;
				}

				switch (u->printGoBackUi())
				{
				case 'y': continue; break;
				default:
					exit(-1);
				}
				

			}


		}

		void showPatientUiController() {
			bool goMain = false;
			while (!goMain)
			{
				u->showPatientUi();
				char opt = u->printGetOptionUi();

				switch (opt)
				{
				case 'n': addNewPatientController(); break;
				case 'c': cancelPatientController(); break;
				case 'm': goMain = true; break;

				default:
					cout << "Display a valid input....." << endl;
					break;
				}

				if (!goMain) {
					switch (u->printGoBackUi())
					{
					case 'y': continue; break;
					default:
						exit(-1);
					}
				}
			}
		}

		void showDoctorUiController() {
			u->showDoctorUi(db);
		}

		void addNewPatientController() {
			Patient patient = u->addNewPatientUi(db);
			db = s->addNewPatientModal(db, patient);
		}

		void cancelPatientController() {
			string patientId = u->cancelAppoinmentUi();
			db = s->cancelAppoinmentModal(db, patientId);
		}









	};

}



int main()
{

	View::Ui u;
	Model::Storage s;

	Controller::Logic l(&s, &u);

	return 0;
}
