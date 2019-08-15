#include "Degree.h"
#include "Student.h"

#include <string>
#include <iostream>
using namespace std;


Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	//this->numOfDays = new int[numOfDaysArraySize];
	for (int i = 0; i < 3; i++) {
		this->numOfDays[i] = 0; //sets every value of array initially as zero
	}
}

Student::Student(string i, string f, string l, string e, int a, int NoD[]) {
	this->studentID = i;
	this->firstName = f;
	this->lastName = l;
	this->email = e;
	this->age = a;
	//this->numOfDays[numOfDaysArraySize] = new int tempArray[];
	for (int i = 0; i < 3; i++) {
		this->numOfDays[i] = NoD[i];
	}
}

string Student::getStudentID() {
	return studentID;
}
void Student::setStudentID(string newStudentID) {
	studentID = newStudentID;
}

string Student::getFirstName() {
	return firstName;
}
void Student::setFirstName(string newFirstName) {
	firstName = newFirstName;
}

string Student::getLastName() {
	return lastName;
}
void Student::setLastName(string newLastName) {
	lastName = newLastName;
}

string Student::getEmail() {
	return email;
}
void Student::setEmail(string newEmail) {
	email = newEmail;
}

int Student::getAge() {
	return age;
}
void Student::setAge(int newAge) {
	age = newAge;
}

int* Student::getNumOfDays() {
	return numOfDays;
}
void Student::setNumOfDays(int *nd) {
	for (int i = 0; i < sizeof(numOfDays) / sizeof(numOfDays[0]); i++) {
		numOfDays[i] = nd[i];
	}
}

void Student::print() {

}

//Destructor
Student::~Student() {
	//cout << "Student destructor for " << getFirstName() << " " << getLastName() << endl;
}


/*
D.  For the Student class, do the following:

  1.  Create the base class Student in the files student.h and student.cpp, which includes each  of the following variables:

  •   student ID
  •   first name
  •   last name
  •   email address
  •   age
  •   array of number of days to complete each course
  •   degree program

  Note: Degree type should be populated in subclasses only.


  2.  Create each of the following functions in the Student class:

	a.  an accessor (i.e., getter) for each  instance variable from part D1

	b.  a mutator (i.e., setter) for each  instance variable from part D1

	Note: All access and changes to the instance variables of the Student class should be done through the accessor and mutator functions.


	c.  constructor using all  of the input parameters provided in the table

	d.  virtual print() to print specific student data

	e.  destructor

	f.  virtual getDegreeProgram()

	Note: Leave the implementation of the getDegreeProgram() function empty.


  3.  Create the three following classes as subclasses of Student, using the files created in part B:

  •   SecurityStudent
  •   NetworkStudent
  •   SoftwareStudent

  Each subclass should override the getDegreeProgram() function. Each  subclass should have a data member to hold the enumerated type for the degree program using the types defined in part C.
*/