//Access.cpp
#include "Access.h"

//get the data from the database
DataBase& Access::retrieveData(DataBase& db)
{
	std::ifstream inputFile("patients.txt");
	if (!inputFile.is_open()) {
		std::cout << "Unable to open file!" << std::endl;
	}

	std::string line;
	while (std::getline(inputFile, line)) {
		istringstream iss(line);
		string patientId;
		string patientName;
		string patientNumber;
		string doctorName;

		if (iss >> patientId >> patientName >> patientNumber >> doctorName) {
			// Process the variables as needed
			Patient patient = Patient(patientId, patientName, patientNumber, doctorName);//
			db.setPatient(patient);
		}
		else {
			std::cout << "Error reading line: " << line << std::endl;
		}
	}

	inputFile.close();
	return db;
}

DataBase& Access::addNewPatient(DataBase& db, Patient patient)
{
	//open file for writing
	db.setPatient(patient);
	ofstream fw("patients.txt", std::ios::out | std::ios::app);

	//check if file was successfully opened for writing
	if (fw.is_open())
	{
		//store array contents to text file
		fw << patient.getPatientId() << "\t" << patient.getPatientName() << "\t" << patient.getPatientNumber() << "\t" << patient.getPatientDoctor() << "\n";
		return db;
	}
	else return db;

	return db;
}

DataBase& Access::cancelAppoinment(DataBase& db, string patient)
{
	int index = 0;
	bool found = false;
	for (int i = 0; i < db.getPatients().getSize(); i++)
	{
		if (db.getPatients()[i].getPatientId() == patient)
		{
			cout << endl;
			cout << "Patient Id     :" << db.getPatients()[i].getPatientId() << endl;
			cout << "Patient Name   :" << db.getPatients()[i].getPatientName() << endl;
			cout << endl;
			cout << "The appoinment has cancelled...The payment will be refund to your account." << endl;
			cout << endl;
			found = true;
			index = i;
		}
	}
	if (found) {
		db.getPatients().deleteAt(index);
		db = modifyData(db);

	}
	else {
		cout << "The patient that related your ID is not available in the system. Please try again." << endl;
	}
	return db;
}

DataBase& Access::modifyData(DataBase& db) {
	PatientList patients = db.getPatients();
	ofstream fw("patients.txt", std::ofstream::out);
	if (fw.is_open())
	{
		for (int i = 0; i < patients.getSize(); i++)
		{
			fw << patients[i].getPatientId() << "\t" << patients[i].getPatientName() << "\t" << patients[i].getPatientNumber() << "\t" << patients[i].getPatientDoctor() << "\n";
		}
	}
	return db;
}