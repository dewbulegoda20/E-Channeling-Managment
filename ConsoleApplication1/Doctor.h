//Doctor.h
#pragma once
#include <string>

using namespace std;

class Doctor {
private:
	string doctorName;
	string doctorId;
	string speacilization;

public:
	Doctor();

	Doctor(string doctorId, string doctorName, string speacilization);

	string getDoctorId();

	string getDoctorName();

	string getSpeacilization();


};