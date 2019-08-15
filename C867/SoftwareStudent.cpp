#include "Degree.h"
#include "Student.h"
#include "SoftwareStudent.h"

#include <string>
#include <iostream>
using namespace std;

SoftwareStudent::SoftwareStudent() {
	setDegreeProgram(SOFTWARE);
}

SoftwareStudent::SoftwareStudent(string i, string f, string l, string e, int a, int NoD[], Degree d) : Student(i, f, l, e, a, NoD) {
	setDegreeProgram(d);
}

Degree SoftwareStudent::getDegreeProgram() {
	return SOFTWARE;
}

void SoftwareStudent::setDegreeProgram(Degree d) {
	this->degreeProgram = d;
}

void SoftwareStudent::print() {
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
	cout << "Degree Program: Software" << endl;
}

SoftwareStudent::~SoftwareStudent() {
	//cout << "Software Student destructor " << getFirstName() << " " << getLastName() << endl;
}