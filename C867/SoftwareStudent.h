#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include <iostream>
using namespace std;

class SoftwareStudent : public Student {
private:
	Degree d;

public:
	SoftwareStudent(); //constructor
	SoftwareStudent(string i, string f, string l, string e, int a, int NoD[], Degree d);

	//virtual functions
	Degree getDegreeProgram();
	void setDegreeProgram(Degree d);
	void print();

	~SoftwareStudent(); //destructor
};

#endif