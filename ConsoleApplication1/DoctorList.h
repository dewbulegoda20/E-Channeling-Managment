//DoctorList.h
#pragma once
#include <cstddef>
#include <iostream>

#include "Doctor.h"


using namespace std;



class DoctorNode {
public:
	Doctor doctor;
	DoctorNode* next;
	DoctorNode* prev;

	//Node() {
	//	elem = NULL;
	//	next = NULL;
	//	prev = NULL;
	//}

	DoctorNode(Doctor doctor) { //overloaded constructor
		this->doctor = doctor;
		next = NULL;
		prev = NULL;
	}
};




class DoctorList {

private:
	DoctorNode* head;
	DoctorNode* tail;
	int size;

public:
	DoctorList();

	void insertLast(Doctor doctor);

	void deleteFirst();

	void deleteLast();

	void deleteAt(int pos);


	Doctor operator[](int index);

	int getSize();

};