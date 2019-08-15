#ifndef ROSTER_H
#define ROSTER_H

#include "Student.h"
#include <iostream>
using namespace std;

const string studentData[] =
{
 "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Brian,Phillips,bphil87@wgu.edu,40,30,20,55,SOFTWARE"
};

const static int numOfColumns = 9;
const static int numOfStudents = sizeof(studentData) / sizeof(studentData[0]);

class Roster {
private:
	string values[numOfColumns];
	Student* classRosterArray[numOfStudents] = { NULL, NULL, NULL, NULL, NULL };

public:
	//Roster(); //constructor
	//Roster(int numOfStudents);

	Student* getClassRosterArray(int size);

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram);
	void remove(string studentID);
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(Degree degreeProgram);
	void printAll();

	~Roster(); //destructor

};

#endif //ROSTER_H