#ifndef patient_hpp
#define patient_hpp

typedef enum e_request {
	TAKE_APP = 0,
	COME_APP,
	NONE
} Request;

typedef struct s_time {
	int hh;
	int mm;
} Time;

Time* createTime(int newHH, int newMM);

class Patient {
	public:
		Patient(std::string newName, Request newReq, char newPhys, Time* newTime);
		~Patient();
		
		std::string getName() const;
		void setName(std::string newName);
		
		Request getRequest() const;
		void setRequest(Request newReq);
		
		char getPhysician() const;
		void setPhysician(char newPhys);
		
		Time getArrTime() const;
		void setArrTime(Time* newTime);
				
		Patient* getNext() const;
		void setNext(Patient* newNext);
		
		std::string trRequest() const;
		std::string trArrTime() const;
		
		friend std::ostream& operator<<(std::ostream&, const Patient&);

	protected:
		std::string name;
		Request request;
		char physician;
		Time arrTime;
		Patient* next;
};

#endif