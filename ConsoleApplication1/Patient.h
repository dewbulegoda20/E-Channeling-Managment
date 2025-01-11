//Patient.h
#pragma once
#include <string>

using namespace std;

class Patient {
private:
	string patientId;
	string patientName;
	string patientNumber;
	string doctorName;

public:
	Patient();

	Patient(string patientId, string patientName, string patientNumber, string doctorName);

	void setPatientId(string patientId);

	string getPatientId();

	void setPatientName(string patientName);

	string getPatientName();

	void setPatientNumber(double patientNumber);

	string getPatientNumber();

	string getPatientDoctor();

};