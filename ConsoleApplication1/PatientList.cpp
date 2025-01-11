//PatientList.cpp
#include "PatientList.h"

PatientList::PatientList() {
	head = NULL;
	tail = NULL;
	size = 0;
}

void PatientList::insertLast(Patient patient) {
	PatientNode* temp = new PatientNode(patient);

	if (head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else {
		//tail->next = temp;
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
	size++;
}

void PatientList::deleteFirst() {

	if (head == NULL)
		cout << "List is empty" << endl;
	else {
		PatientNode* temp = head;

		if (size == 1) {
			delete temp;
			head = NULL;
			tail = NULL;
		}
		else {
			head = head->next;
			head->prev = NULL;
			delete temp;
			size--;
		}
	}
}

void PatientList::deleteLast() {
	if (head == NULL) {
		cout << "List is empty" << endl;
	}
	else {
		tail->next = NULL;

	}
	size--;
}

void PatientList::deleteAt(int pos) {
	if (pos < 0 || pos >= size)
		cout << "Invalid position" << endl;
	else if (pos == 0)
		deleteFirst();
	else if (pos == size - 1)
		deleteLast();
	else {

		PatientNode* current = head;
		for (int i = 0; i < pos; i++) {
			current = current->next;
		}
		PatientNode* temp = head;
		(current->prev)->next = temp->next;
		(current->next)->prev = temp->prev;
		delete temp;
		size--;

	}
}

Patient PatientList::operator[](int index) {
	PatientNode* current = head;
	if (head == NULL) {

	}
	else {
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
	}
	Patient p;
	if (head != NULL)
	{
		p = current->patient;
	}

	return p;

}


int PatientList::getSize() {
	return size;
}