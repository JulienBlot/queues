#ifndef queue_hpp
#define queue_hpp

#include "patient.hpp"

class Queue {
	public:
		Queue(std::string newName);
		~Queue();
		
		std::string getName() const;
		void setName(std::string newName);
		
		Patient* getOut() const;
		void setOut(Patient* newOut);
		
		Patient* getIn() const;
		void setIn(Patient* newIn);
		
		int getSize() const;
		void setSize(int newSize);
		
		void pushPatient(Patient* newPatient);
		Patient* popPatient();
		Patient* removePatient(int pos);
				
		friend std::ostream& operator<<(std::ostream&, const Queue&);

	protected:
		std::string name;
		Patient* out;
		Patient* in;
		int size;
};

#endif