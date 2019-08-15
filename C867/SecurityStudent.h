#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include <iostream>
using namespace std;

class SecurityStudent : public Student {
private:
	Degree d;

public:
	SecurityStudent(); //constructor
	SecurityStudent(string i, string f, string l, string e, int a, int NoD[], Degree d);

	//virtual functions
	Degree getDegreeProgram();
	void setDegreeProgram(Degree d);
	void print();

	~SecurityStudent(); //destructor
};

#endif