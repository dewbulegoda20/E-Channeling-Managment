//PatientList.h
#pragma once
#include <cstddef>
#include <iostream>

#include "Patient.h"


using namespace std;



class PatientNode {
public:
	Patient patient;
	PatientNode* next;
	PatientNode* prev;


	PatientNode(Patient patient) { //overloaded constructor
		this->patient = patient;
		next = NULL;
		prev = NULL;
	}
};




class PatientList {

private:
	PatientNode* head;
	PatientNode* tail;
	int size;

public:
	PatientList();

	void insertLast(Patient patient);

	void deleteFirst();

	void deleteLast();

	void deleteAt(int pos);

	Patient operator[](int index);

	int getSize();



};