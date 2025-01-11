//Database.h
#pragma once
#include "Patient.h"
#include "PatientList.h"
#include "Doctor.h"
#include "DoctorList.h"

class DataBase {
private:
	PatientList patients;

	DoctorList doctors;

public:
	DataBase();
	void setPatient(Patient item);

	//get only one item
	//Item getItem(this need specific informations to return the value like name or code);

	PatientList& getPatients();

	DoctorList& getDoctors();

};