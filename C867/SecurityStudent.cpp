#include "Degree.h"
#include "Student.h"
#include "SecurityStudent.h"

#include <string>
#include <iostream>
using namespace std;

SecurityStudent::SecurityStudent() {
	setDegreeProgram(SECURITY);
}

SecurityStudent::SecurityStudent(string i, string f, string l, string e, int a, int NoD[], Degree d) : Student(i, f, l, e, a, NoD) {
	setDegreeProgram(SECURITY);
}

Degree SecurityStudent::getDegreeProgram() {
	return SECURITY;
}

void SecurityStudent::setDegreeProgram(Degree d) {
	this->degreeProgram = SECURITY;
}

void SecurityStudent::print() {
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
	cout << "Degree Program: Security" << endl;
}

SecurityStudent::~SecurityStudent() {
	//cout << "Security Student destructor " << getFirstName() << " " << getLastName() << endl;
}