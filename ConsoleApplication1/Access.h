//Access.h
#pragma once
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>

#include "Patient.h"
#include "dataBase.h"


using namespace std;

class Access {
private:

public:


	DataBase& retrieveData(DataBase& db);

	DataBase& addNewPatient(DataBase& db, Patient patient);

	DataBase& cancelAppoinment(DataBase& db, string patient);

	DataBase& modifyData(DataBase& db);

};