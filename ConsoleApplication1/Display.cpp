//Dispaly.cpp
#include "Display.h"



void Display::startApp() {
	system("cls");
	CoutCentered("========================");
	CoutCentered("ONLINE APPOINMENT SYSTEM");
	CoutCentered("========================");

	cout << char(218);      for (int i = 0; i < 21; i++) { cout << char(196); }      cout << char(191) << endl;
	cout << char(179) << "  Select the option  " << char(179) << endl;
	cout << char(179) << "---------------------" << char(179) << endl;
	cout << char(179) << "                     " << char(179) << endl;
	cout << char(179) << "1.Patient         (p)" << char(179) << endl;//this should allow to client to see the current item quantities and what are the requirements
	cout << char(179) << "2.Doctor          (d)" << char(179) << endl;
	cout << char(179) << "2.Exit            (e)" << char(179) << endl;
	cout << char(192);      for (int i = 0; i < 21; i++) { cout << char(196); }      cout << char(217) << endl;
	cout << endl;

}

void Display::CoutCentered(std::string text) {
	// This function will only center the text if it is less than the length of the console!
	// Otherwise it will just display it on the console without centering it.

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Get the console handle.
	PCONSOLE_SCREEN_BUFFER_INFO lpScreenInfo = new CONSOLE_SCREEN_BUFFER_INFO(); // Create a pointer to the Screen Info pointing to a temporal screen info.
	GetConsoleScreenBufferInfo(hConsole, lpScreenInfo); // Saves the console screen info into the lpScreenInfo pointer.
	COORD NewSBSize = lpScreenInfo->dwSize; // Gets the size of the screen
	if (NewSBSize.X > text.size()) {
		int newpos = ((NewSBSize.X - text.size()) / 2); // Calculate the number of spaces to center the specific text.
		for (int i = 0; i < newpos; i++) std::cout << " "; // Prints the spaces
	}
	std::cout << text << std::endl; // Prints the text centered :]
}

char Display::getOption() {
	cout << "- Select your option : ";
	cin >> Display::selectedOption;
	return Display::selectedOption;
}

char Display::goBack() {
	char opt;
	cout << "- Do you want to go back [y/n] : ";
	cin >> opt;
	return opt;
}


//==========================================================================================================================================================================
//=============================                                   Patients UI                                 ==============================================================
//==========================================================================================================================================================================


void Display::patientOpt() {
	system("cls");
	CoutCentered("========================");
	CoutCentered("ONLINE APPOINMENT SYSTEM");
	CoutCentered("========================");

	cout << char(218);      for (int i = 0; i < 27; i++) { cout << char(196); }      cout << char(191) << endl;
	cout << char(179) << "     Select the option     " << char(179) << endl;
	cout << char(179) << "---------------------------" << char(179) << endl;
	cout << char(179) << "                           " << char(179) << endl;
	cout << char(179) << "1.Get a new appoinment  (n)" << char(179) << endl;//this should allow to client to see the current item quantities and what are the requirements
	cout << char(179) << "2.Cancel an appoinment  (c)" << char(179) << endl;
	cout << char(179) << "3.Go back to main page  (m)" << char(179) << endl;
	cout << char(192);      for (int i = 0; i < 27; i++) { cout << char(196); }      cout << char(217) << endl;
	cout << endl;

}

Patient Display::getPatient(DataBase& db) {

	string patientId;
	string patientName;
	string patientNumber;
	string doctorName;

	cout << "- Input your ID           : "; cin >> patientId;
	cout << "- Input your name         : "; cin >> patientName;
	cout << "- Input your Phone number : "; cin >> patientNumber;
	cout << endl;

	cout << "You can select the doctor from the followings." << endl;
	cout << endl;

	int choise;
	for (int i = 0; i < db.getDoctors().getSize(); i++)
	{
		cout << db.getDoctors()[i].getDoctorName() << "-\t" << db.getDoctors()[i].getSpeacilization() << "\t\t [" << i + 1 << "]" << endl;
	}
	cout << endl;
	cout << "- Select your doctor      : ";
	cin >> choise;
	cout << endl;
	switch (choise)
	{
	case 1: doctorName = db.getDoctors()[0].getDoctorName(); break;
	case 2: doctorName = db.getDoctors()[1].getDoctorName(); break;
	case 3: doctorName = db.getDoctors()[2].getDoctorName(); break;
	case 4: doctorName = db.getDoctors()[3].getDoctorName(); break;
	case 5: doctorName = db.getDoctors()[4].getDoctorName(); break;

	default:
		break;
	}


	Patient patient = Patient(patientId, patientName, patientNumber, doctorName);

	cout << endl;
	cout << "--Enter your bank details" << endl;
	cout << endl;

	string s;

	cout << "- Input bank card number           : "; cin >> s;
	cout << "- Input bank card expire date      : "; cin >> s;
	cout << "- Input bank card cvv number       : "; cin >> s;


	cout << endl;
	cout << "- The bank details verified...";

	cout << endl;
	cout << "The appoinment has made successfully..." << endl;
	cout << endl;

	return patient;

}

string Display::cancelAppoinment() {
	cout << "Input your ID number : ";
	string id;
	cin >> id;
	return id;
}



































//==========================================================================================================================================================================
//=============================                                   Doctor UI                                 ==============================================================
//==========================================================================================================================================================================


void Display::doctorOpt(DataBase& db) {
	string doctorName;
	cout << endl;
	cout << "Enter your name     : "; cin >> doctorName;
	cout << endl;
	cout << "Patient Name\t\tPhone Number" << endl;
	cout << endl;
	for (int i = 0; i < db.getPatients().getSize(); i++)
	{
		if (db.getPatients()[i].getPatientDoctor() == doctorName)
		{
			cout << db.getPatients()[i].getPatientName() << "\t\t" << db.getPatients()[i].getPatientNumber() << endl;
		}
	}

}