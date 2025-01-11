//DoctorList.cpp
#include "DoctorList.h"

DoctorList::DoctorList() {
	head = NULL;
	tail = NULL;
	size = 0;
}

void DoctorList::insertLast(Doctor doctor) {
	DoctorNode* temp = new DoctorNode(doctor);

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

void DoctorList::deleteFirst() {

	if (head == NULL)
		cout << "List is empty" << endl;
	else {
		DoctorNode* temp = head;

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

void DoctorList::deleteLast() {
	if (head == NULL) {
		cout << "List is empty" << endl;
	}
	else {
		tail->next = NULL;

	}
	size--;
}

void DoctorList::deleteAt(int pos) {
	if (pos < 0 || pos >= size)
		cout << "Invalid position" << endl;
	else if (pos == 0)
		deleteFirst();
	else if (pos == size - 1)
		deleteLast();
	else {

		DoctorNode* current = head;
		for (int i = 0; i < pos; i++) {
			current = current->next;
		}
		DoctorNode* temp = head;
		(current->prev)->next = temp->next;
		(current->next)->prev = temp->prev;
		delete temp;
		size--;

	}
}

Doctor DoctorList::operator[](int index) {
	DoctorNode* current = head;
	if (head == NULL) {
		cout << "The database is empty..." << endl;
	}
	else {
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
	}
	Doctor p;
	if (head != NULL) {
		p = current->doctor;
	}

	return p;

}


int DoctorList::getSize() {
	return size;
}