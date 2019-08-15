#include "Degree.h"
#include "Roster.h"
#include "Student.h"
#include "NetworkStudent.h"
#include "SecurityStudent.h"
#include "SoftwareStudent.h"

#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;


void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram) {

	int daysInCourse[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	Student* student = NULL;
	switch (degreeProgram) {

	case NETWORK:
		student = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
		break;
	case SOFTWARE:
		student = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
		break;
	case SECURITY:
		student = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
		break;
	}

	for (int i = 0; i < numOfStudents; i++) {
		if (classRosterArray[i] == NULL) {
			classRosterArray[i] = student;
			break;
		}
	}

}

void Roster::remove(string studentID) {
	bool found = false;
	for (int i = 0; i < numOfStudents; i++) {
		if (classRosterArray[i] == NULL) {
			continue;
		}
		if (classRosterArray[i]->getStudentID() == studentID) {
			delete(classRosterArray[i]);
			classRosterArray[i] = NULL;
			found = true;
		}
	}
	if (!found) {
		cout << "ERROR: " << studentID << " is not a valid Student ID. Cannot remove from roster." << endl;
		cout << endl;
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	bool found = false;
	for (int i = 0; i < numOfStudents; i++) {
		if (classRosterArray[i] == NULL) {
			continue;
		}
		if (classRosterArray[i]->getStudentID() == studentID) {
			double total = 0;
			for (int j = 0; j < 3; j++) {
				total += classRosterArray[i]->getNumOfDays()[j];
			}
			total = total / 3;
			cout << "Average days per course for Student ID " << studentID << ": " << total << "." << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "ERROR: " << studentID << " is not a valid Student ID. Cannot figure average days per course." << endl;
		cout << endl;
	}
}

void Roster::printInvalidEmails() {
	for (int i = 0; i < numOfStudents; i++) {
		bool spaceFound = false;
		bool atFound = false;
		bool dotFound = false;
		string tempStr = classRosterArray[i]->getEmail();
		if (tempStr.rfind('.') == tempStr.length() - 4) {
			dotFound = true;
		}
		if (tempStr.find('@') != string::npos) {
			atFound = true;
		}
		for (int i = 0; i<tempStr.length(); i++) {
			if (tempStr[i] == ' ') {
				spaceFound = true;
				cout << tempStr << endl;
				break;
			}
		}
		if (!atFound || !dotFound) {
			cout << tempStr << endl;
		}
	}
	cout << endl;
}

void Roster::printByDegreeProgram(Degree degree) {
	for (int i = 0; i < numOfStudents; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degree) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}

void Roster::printAll() {
	for (int i = 0; i < numOfStudents; i++) {
		if (classRosterArray[i] == NULL) {
			continue;
		}
		classRosterArray[i]->print();
	}
	cout << endl;
}

Roster::~Roster() {
	cout << "Roster Destructor called." << endl;
}

Student* Roster::getClassRosterArray(int student) {
	return this->classRosterArray[student];
}

int main() {

	cout << endl;
	cout << "Scripting and Programming - Applications – C867" << endl;
	cout << "\t\tProgramming language used: C++" << endl;
	cout << "\tBrian Phillips, Student ID: #000939142" << endl << endl;

	Roster classRoster;
	Degree degree;
	string values[numOfColumns];
	for (int i = 0; i < numOfStudents; i++) {
		string delimValue = studentData[i];
		string delimiter = ",";
		size_t pos = 0;
		string token;
		int counter = 0;
		while ((pos = delimValue.find(delimiter)) != string::npos) {
			token = delimValue.substr(0, pos);
			values[counter] = token;
			delimValue.erase(0, pos + delimiter.length());
			counter++;
		}
		char testDegree = *delimValue.rbegin();
		switch (testDegree) {
		case 'E':
			degree = SOFTWARE; //2
			break;
		case 'Y':
			degree = SECURITY; //0
			break;
		case 'K':
			degree = NETWORK;  //1
			break;
		}
		classRoster.add(values[0], values[1], values[2], values[3], atoi(values[4].c_str()), atoi(values[5].c_str()), atoi(values[6].c_str()), atoi(values[7].c_str()), degree);
	}

	classRoster.printAll();
	classRoster.printInvalidEmails();
	for (int i = 0; i < numOfStudents; i++) {
		Student* tempPointer = classRoster.getClassRosterArray(i);
		string id = tempPointer->getStudentID();
		classRoster.printAverageDaysInCourse(id);
	}
	cout << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.remove("A3");
	for (int i = 0; i < numOfStudents; i++) {
		if (classRoster.getClassRosterArray(i) == NULL) {
			continue;
		}
		delete(classRoster.getClassRosterArray(i));
	}
	classRoster.~Roster();

	system("pause");

	return 0;
}

/*
E.  Create a Roster class (roster.cpp) by doing the following:
  1.  Create an array of pointers, classRosterArray, to hold the data provided in the studentData table.

  2.  Create a student object for each  student in the data table by using the subclasses NetworkStudent, SecurityStudent, and SoftwareStudent, and populate classRosterArray.

	a.  Apply pointer operations when parsing each  set of data identified in the studentData table.

	b.  Add each student object to classRosterArray.

  3.  Define the following functions:

	a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, <degree program>) that sets the instance variables from part D1 and updates the roster

	b.  public void remove(string studentID) that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.


	c.  public void printAll() that prints a complete tab-separated list of student data using accessor functions with the provided format: 1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all  the students in classRosterArray and call the print() function for each student.

	d.  public void printDaysInCourse(string studentID) that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.

	e.  public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user

	Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').


	f.  public void printByDegreeProgram(int degreeProgram) that prints out student information for a degree program specified by an enumerated type

F.  Demonstrate the program’s required functionality by adding a void main() function to roster.cpp, which will contain the required function calls to achieve the following results:

  1.  Print out to the screen, via your application, the course title, the programming language used, your student ID, and your name.

  2.  Create an instance of the Roster class called classRoster.

  3.  Add each student to classRoster.

  4.  Convert the following pseudo code to complete the rest of the main() function:
	classRoster.printAll();
	classRoster.printInvalidEmails();
	//loop through classRosterArray and for each element:
	classRoster.printAverageDaysInCourse(current_object's student id);
	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.remove("A3");
	//expected: the above line should print a message saying such a student with this ID was not found.

  5.  Call the destructor to release the Roster memory.

*/