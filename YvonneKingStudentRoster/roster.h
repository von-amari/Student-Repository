#pragma once
#include "student.h"

using namespace std;
//E. create roster class--declaration in h file
class Roster {
private:
	int lastIndex = -1;
	const static int numStudents = 5;
	


public:
	Student* classRosterArray[numStudents]; //E.1 create array of pointers
	//E.2parse eash set of data idenfified in the studentData table
	void parse(string row);

	//E.3.a define functions
	void add(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeProgram);

	 void remove(string studentID);
	 void printAll();
	 void printAverageDaysInCourse(string studentID);
	 void printInvalidEmails();
	 void printByDegreeProgram(DegreeProgram degreeProgram);
	

	 ~Roster();

};