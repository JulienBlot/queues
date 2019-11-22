#include <iostream>
#include "queue.hpp"

Queue::Queue(std::string newName) {
	if (newName.length() > 0) {
		this->name = newName;
	}
	else {
		std::cout << "Error: invalid 'name' input. Set to \"Queue\".\n" << std::endl;
		this->name = "Queue";
	}
	
	this->out = NULL;
	this->in = NULL;
	this->size = 0;
}

Queue::~Queue() {}

std::string Queue::getName() const {
	return this->name;
}
void Queue::setName(std::string newName) {
	if (newName.length() > 0) {
		this->name = newName;
	}
	else {
		std::cout << "Error: invalid 'name' input." << std::endl;
	}
}

Patient* Queue::getOut() const {
	return this->out;
}
void Queue::setOut(Patient* newOut) {
	this->out = newOut;
}

Patient* Queue::getIn() const {
	return this->in;
}
void Queue::setIn(Patient* newIn) {
	this->in = newIn;
}

int Queue::getSize() const {
	return this->size;
}
void Queue::setSize(int newSize) {
	if (newSize >= 0) {
		this->size = newSize;
	}
	else {
		std::cout << "Error: invalide 'size' input." << std::endl;
	}
}

void Queue::pushPatient(Patient* newPatient) {
	if (this->in != NULL) {
		Patient* temp;
		temp = this->in;
		temp->setNext(newPatient);
		this->in = newPatient;
	}
	else {
		this->out = newPatient;
		this->in = newPatient;
	}
	newPatient->setNext(NULL);
	this->size++;
}

Patient* Queue::popPatient() {
	Patient* temp = NULL;
	if (this->out != NULL) {
		temp = this->out;
		this->out = this->out->getNext();
		if (this->in == temp) {
			this->in = NULL;
		}
		this->size--;
	}
	else {
		std::cout << "Error: queue is empty." << std::endl;
	}
	return temp;
}

Patient* Queue::removePatient(int pos) {
	Patient* temp2 = NULL;
	if (this->out != NULL && pos <= size) {
		if (pos == 1) {
			temp2 = popPatient();
		}
		else {
			Patient* temp1;
			temp1 = this->out;
			for (int i=1; i<pos-1; i++) {
				temp1 = temp1->getNext();
			}
			temp2 = temp1->getNext();
			temp1->setNext(temp1->getNext()->getNext());
			this->size--;
		}
	}
	else {
		std::cout << "Error: no patient found at position " << pos << "." <<std::endl;
	}
	return temp2;
}

std::ostream& operator<<(std::ostream& os, const Queue& q) {
	os << "***** " << q.getName() << " *****";
	
	int i = 1;
	Patient* temp;
	temp = q.out;
	while (temp != NULL) {
		os << "\n*** Patient " << i << " ***\n" << *temp;
		temp = temp->getNext();
		i++;
	}
	
	return os;
}