#include <iostream>
#include "manager.hpp"

Patient* createPatient() {
	std::string name;
	Request request;
	char physician, col;
	int req, hh, mm;
	
	getchar();
	std::cout << "Name: ";
	std::getline(std::cin, name);
	std::cout << "Request (1 or 2): ";
	while (!(std::cin >> req) || (req != 1 && req != 2)) {
		std::cin.clear();
	 	std::cin.ignore(999,'\n');
	 	std::cout << "Error: invalid input. Please try again: ";
	}
	std::cout << "Physician (X, Y or Z): ";
	while (!(std::cin >> physician) || (physician != 'X' && physician != 'Y' && physician != 'Z')) {
		std::cin.clear();
	 	std::cin.ignore(999,'\n');
	 	std::cout << "Error: invalid input. Please try again: ";
	}
	std::cout << "Arrival time (HH:MM): ";
	while (!(std::cin >> hh >> col >> mm)) {
		std::cin.clear();
	 	std::cin.ignore(999,'\n');
	 	std::cout << "Error: invalid input. Please try again: ";
	}
	
	if (req == 1) {
		request = TAKE_APP;
	}
	else if (req == 2) {
		request = COME_APP;
	}
	else {
		request = NONE;
	}
	
	return new Patient(name, request, physician, createTime(hh, mm));
}

void removeMainQueue(Queue* mainQueue, Queue* xQueue, Queue* yQueue, Queue* zQueue) {
	Patient* removed;
	int pos = 0;
	std::cout << "ID of patient to remove: ";
	while (!(std::cin >> pos) || pos < 1) {
		std::cin.clear();
	 	std::cin.ignore(999,'\n');
	 	std::cout << "Error: invalid input. Please try again: ";
	}
	removed = mainQueue->removePatient(pos);
	
	if (removed != NULL) {
		if (removed->getRequest() == COME_APP) {
			switch(removed->getPhysician()) {
				case 'X':
					xQueue->pushPatient(removed);
					break;
				case 'Y':
					yQueue->pushPatient(removed);
					break;
				case 'Z':
					zQueue->pushPatient(removed);
					break;
				default:
					std::cout << "Unexpected error." << std::endl;
					break;
			}
		}
		else {
			std::cout << "\n***Patient removed ***\n" << *removed << std::endl;
		}
	}
}

void popDoctor(Queue* xQueue, Queue* yQueue, Queue* zQueue) {
	char id;
	std::cout << "Doctor ID of queue to alter (X, Y or Z): ";
	while (!(std::cin >> id) || (id != 'X' && id != 'Y' && id != 'Z')) {
		std::cin.clear();
	 	std::cin.ignore(999,'\n');
	 	std::cout << "Error: invalid input. Please try again: ";
	}
	switch(id) {
		case 'X':
			xQueue->popPatient();
			break;
		case 'Y':
			yQueue->popPatient();
			break;
		case 'Z':
			zQueue->popPatient();
			break;
		default:
			std::cout << "Unexpected error." << std::endl;
			break;
	}
}