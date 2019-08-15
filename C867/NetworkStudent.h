#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include <iostream>
using namespace std;

class NetworkStudent : public Student {
protected:
	Degree d;

public:
	NetworkStudent(); //constructor
	NetworkStudent(string i, string f, string l, string e, int a, int NoD[], Degree d);

	//virtual functions
	Degree getDegreeProgram();
	void setDegreeProgram(Degree d);
	void print();

	~NetworkStudent(); //destructor
};

#endif