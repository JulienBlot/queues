/* Instructions:
 
• program add and delete primitives in the main queue
• do the same for the secondary file model (that of each physician)
• make a menu where the user can choose between:
- add someone to the main queue
- delete someone from the main queue (and thus either display or add the person in a secondary file)
- remove someone from a secondary file by specifying which
- display the contents of the 4 queues
- leave the program
*/



#include <iostream>
#include "queue.hpp"
#include "patient.hpp"
#include "manager.hpp"

int main(int argc, char *argv[]) {
	Queue mainQueue("Main queue"), xQueue("Queue X"), yQueue("Queue Y"), zQueue("Queue Z");
	int choice;
	
	std::cout << "Welcome to this program! You can create patients and add them to queues. Their ID is their position in the queue. Each patient has a request: Take an appointment (1), or Come for an appointment (2).\n" << std::endl;
	do {
		std::cout << "————— MENU —————" << std::endl
				<< "1. Add a patient to main queue." << std::endl
				<< "2. Pop a patient from main queue." << std::endl
				<< "3. Pop a patient from a doctor's queue." << std::endl
				<< "4. Display queues." << std::endl
				<< "5. Quit." << std::endl;
		 while (!(std::cin >> choice) || !(choice >= 1 && choice <= 5)) {
			std::cin.clear();
		 	std::cin.ignore(999,'\n');
		 	std::cout << "Error: invalid input. Please try again: ";
		}
		std::cout << std::endl;
		
		switch (choice) {
			case 1:
				mainQueue.pushPatient(createPatient());
				break;
			case 2:
				removeMainQueue(&mainQueue, &xQueue, &yQueue, &zQueue);
				break;
			case 3:
				popDoctor(&xQueue, &yQueue, &zQueue);
				break;
			case 4:
				std::cout << mainQueue << std::endl;
				std::cout << xQueue << std::endl;
				std::cout << yQueue << std::endl;
				std::cout << zQueue << std::endl;
				break;
			case 5:
				break;
			default:
				std::cout << "Unexpected error." << std::endl;
				break;
		}
		std::cout << std::endl;
	} while (choice != 5);
	
	std::cout << "Bye!" << std::endl;
}
