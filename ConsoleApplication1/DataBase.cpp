//Database.cpp
#include "DataBase.h"

DataBase::DataBase()
{
	this->doctors.insertLast(Doctor("D001", "Doctor1", "Cardiologist"));
	this->doctors.insertLast(Doctor("D002", "Doctor2", "Oncologist"));
	this->doctors.insertLast(Doctor("D003", "Doctor3", "Dermatalogist"));
	this->doctors.insertLast(Doctor("D004", "Doctor4", "Peaditrecian"));
	this->doctors.insertLast(Doctor("D005", "Doctor5", "Cardiologist"));
}

void DataBase::setPatient(Patient item)
{
	this->patients.insertLast(item);
}


PatientList& DataBase::getPatients()
{
	return patients;
}

DoctorList& DataBase::getDoctors() {
	return doctors;
}