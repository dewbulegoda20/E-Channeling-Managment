//Display.h
#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "Patient.h"
#include "DataBase.h"

using namespace std;

class Display {
private:
	char selectedOption;
public:
	void startApp();

	void CoutCentered(std::string text);

	char getOption();

	char goBack();

	//=========================================================================
	//=========================================================================

	void patientOpt();

	Patient getPatient(DataBase& db);

	string cancelAppoinment();








	//=========================================================================
	//=========================================================================

	void doctorOpt(DataBase& db);

};