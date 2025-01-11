//Patient.cpp
#include "Patient.h"

Patient::Patient()
{
}

Patient::Patient(string patientId, string patientName, string patientNumber, string doctorName)
{
	this->patientId = patientId;
	this->patientName = patientName;
	this->patientNumber = patientNumber;
	this->doctorName = doctorName;
}

void Patient::setPatientId(string patientId)
{
	this->patientId = patientId;
}

string Patient::getPatientId()
{
	return this->patientId;
}

void Patient::setPatientName(string patientName)
{
	this->patientName = patientName;
}

string Patient::getPatientName()
{
	return this->patientName;
}

void Patient::setPatientNumber(double patientNumber)
{
	this->patientNumber = patientNumber;
}

string Patient::getPatientNumber()
{
	return this->patientNumber;
}

string Patient::getPatientDoctor()
{
	return this->doctorName;
}