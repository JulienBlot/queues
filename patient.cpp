#include <iostream>
#include <sstream>
#include <string>
#include "patient.hpp"

Time* createTime(int newHH, int newMM) {
	Time* newTime;
	newTime = new Time;
	newTime->hh = newHH;
	newTime->mm = newMM;
	return newTime;
}

Patient::Patient(std::string newName, Request newReq, char newPhys, Time* newTime) {
	if (newName.length() > 0) {
		this->name = newName;
	}
	else {
		std::cout << "Error: invalid 'name' input. Set to \"Patient\".\n" << std::endl;
		this->name = "Patient";
	}
	
	if (newReq == TAKE_APP || newReq == COME_APP) {
		this->request = newReq;
	}
	else {
		std::cout << "Error: invalid 'request' input. Set to \"Take an appointment\".\n" << std::endl;
		this->request = TAKE_APP;
	}
	
	if (newPhys == 'X' || newPhys == 'Y' || newPhys == 'Z') {
		this->physician = newPhys;
	}
	else {
		std::cout << "Error: invalid 'physician' input. Set to 'X'.\n" << std::endl;
		this->physician = 'X';
	}
	
	this->arrTime.hh = newTime->hh%24;
	this->arrTime.mm = newTime->mm%60;
	free(newTime);
	
	this->next = NULL;
}

Patient::~Patient() {
	//TODO: free(&(this->arrTime));
}

std::string Patient::getName() const {
	return this->name;
}
void Patient::setName(std::string newName) {
	if (newName.length() > 0) {
		this->name = newName;
	}
	else {
		std::cout << "Error: invalid 'name' input." << std::endl;
	}
}

Request Patient::getRequest() const {
	return this->request;
}
void Patient::setRequest(Request newReq) {
	if (newReq == TAKE_APP || newReq == COME_APP) {
		this->request = newReq;
	}
	else {
		std::cout << "Error: invalid 'request' input." << std::endl;
	}
}

char Patient::getPhysician() const {
	return this->physician;
}
void Patient::setPhysician(char newPhys) {
	if (newPhys == 'X' || newPhys == 'Y' || newPhys == 'Z') {
		this->physician = newPhys;
	}
	else {
		std::cout << "Error: invalid 'physician' input." << std::endl;
	}
}

Time Patient::getArrTime() const {
	return this->arrTime;
}
void Patient::setArrTime(Time* newTime) {
	this->arrTime.hh = newTime->hh%24;
	this->arrTime.mm = newTime->mm%60;
	free(newTime);
}
		
Patient* Patient::getNext() const {
	return this->next;
}
void Patient::setNext(Patient* newNext) {
	this->next = newNext;
}

std::string Patient::trRequest() const {
	std::string strReq;
	if (this->request == COME_APP) {
		strReq = "Come to an appointment";
	}
	else {
		strReq = "Take an appointment";
	}
	return strReq;
}

std::string Patient::trArrTime() const {
	std::string strTime;
	std::ostringstream ossHH, ossMM;
	ossHH << this->arrTime.hh;
	std::string strHH = ossHH.str();
	ossMM << this->arrTime.mm;
	std::string strMM = ossMM.str();
	
	if (strHH.length() == 1) {
		strTime += "0"; strTime += strHH;
	}
	else {
		strTime += strHH;
	}
	strTime += ":";
	if (strMM.length() == 1) {
		strTime += "0"; strTime += strMM;
	}
	else {
		strTime += strMM;
	}
	return strTime;
}

std::ostream& operator<<(std::ostream& os, const Patient& p) {
	os << "Name:\t";
	os << p.getName() << "\n";
	
	os << "Request:\t";
	os << p.trRequest() << "\n";
	
	os << "Physician:\t";
	os << p.getPhysician() << "\n";
	
	os << "Arr. time:\t";
	os << p.trArrTime() << "\n";
		
	return os;
}