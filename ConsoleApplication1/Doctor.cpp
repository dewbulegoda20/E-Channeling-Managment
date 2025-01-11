//Doctor.cpp

#include "Doctor.h"

Doctor::Doctor()
{
}

Doctor::Doctor(string DoctorId, string doctorName, string speacilization)
{
	this->doctorId = doctorId;
	this->doctorName = doctorName;
	this->speacilization = speacilization;
}

string Doctor::getDoctorId()
{
	return doctorId;
}

string Doctor::getDoctorName()
{
	return doctorName;
}

string Doctor::getSpeacilization()
{
	return speacilization;
}