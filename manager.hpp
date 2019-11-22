#ifndef manager_hpp
#define manager_hpp

#include <iostream>
#include "queue.hpp"
#include "patient.hpp"

Patient* createPatient();
void removeMainQueue(Queue* mainQueue, Queue* xQueue, Queue* yQueue, Queue* zQueue);
void popDoctor(Queue* xQueue, Queue* yQueue, Queue* zQueue);

#endif