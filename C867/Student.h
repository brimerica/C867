#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student {
protected:
	const static int numOfDaysArraySize = 3;
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int numOfDays[numOfDaysArraySize];
	Degree degreeProgram;

public:
	//constructors
	Student();
	Student(string i, string f, string l, string e, int a, int NoD[]);

	//destructor
	virtual ~Student();

	//getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getNumOfDays();

	//setters
	void setStudentID(string newStudentID);
	void setFirstName(string newFirstName);
	void setLastName(string newLastName);
	void setEmail(string newEmail);
	void setAge(int newAge);
	void setNumOfDays(int newNumOfDays[]);

	//functions
	virtual Degree getDegreeProgram() = 0;
	virtual void setDegreeProgram(Degree d) = 0;
	virtual void print();
};

#endif //STUDENT_H