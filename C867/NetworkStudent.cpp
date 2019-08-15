#include "Degree.h"
#include "Student.h"
#include "NetworkStudent.h"

#include <string>
#include <iostream>
using namespace std;

NetworkStudent::NetworkStudent() {
	setDegreeProgram(NETWORK);
}

NetworkStudent::NetworkStudent(string i, string f, string l, string e, int a, int NoD[], Degree d) : Student(i, f, l, e, a, NoD) {
	setDegreeProgram(NETWORK);
}

Degree NetworkStudent::getDegreeProgram() {
	return NETWORK;
}

void NetworkStudent::setDegreeProgram(Degree d) {
	this->degreeProgram = NETWORK;
}

void NetworkStudent::print() {
	cout << "Student ID: " << getStudentID() << "\t";
	cout << "First Name: " << getFirstName() << "\t";
	cout << "Last Name: " << getLastName() << "\t";
	cout << "Age: " << getAge() << "\t";
	cout << "Days in course: {";
	for (int j = 0; j < 3; j++) {
		cout << getNumOfDays()[j];
		if (j < 2) {
			cout << ", ";
		}
		else {
			cout << "}\t";
		}
	}
	cout << "Degree Program: Network" << endl;
}

NetworkStudent::~NetworkStudent() {
	//cout << "Network Student destructor for " << getFirstName() << " " << getLastName() << endl;
}
