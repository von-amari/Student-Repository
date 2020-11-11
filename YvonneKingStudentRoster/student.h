
#pragma once
#include <iostream>
#include "degree.h"
using namespace std;
using std::string;

//D. create student class, declare in header file
class Student {
public:

	const static int daysInCourseArray = 4;
private://D.1, D.2.c. declare data members, accessible by getters and setters
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysInCourse[daysInCourseArray];
	DegreeProgram degreeProgram;  //enumeration DegreeProgram from degree.h
public: //D.2 declare member functions

	Student(); 

	//D.2.d. constructor with all input prameters from table, needs to be in same order in definition
	Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram program);
	~Student();//destructor


	//D.2.a. getters for each instance variable from Student class
	string GetStudentID() const;
	string GetFirstName() const;
	string GetLastName() const;
	string GetEmail() const;
	int GetAge() const;
	int* GetDaysInCourse();
	DegreeProgram getDegreeProgram() const;

	//D.2.b. setters for each instance variable from Student class
	void SetStudentID(string studentID);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmail(string email);
	void SetAge(int age);
	void SetDaysInCourse(int daysInCourse[]);
	void SetDegreeProgram(DegreeProgram program);


	void print(); //D.2.e print function to print out student data

};

/*
create student class in student.h and student.cpp
create setter and getter functions for each instance variable in class
	any access to variables have to be done through the getter/setter
constructor using all of the var/input in table
print() function to print specific student data
*/