#pragma once
#include "student.h"
#include <iomanip>
using std::string;

//D.1, D.2, definition of student class from student.h 
Student::Student() { //default- parameterless 
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->age = 0;
	this->email = email;
	for (int i = 0; i < Student::daysInCourseArray; i++) {
		this->daysInCourse[i] = 0;
	}
	this->degreeProgram = DegreeProgram::NETWORK;
}

Student::Student(string studentID, string firstName, string lastName, string email, int age,  int daysInCourse[], DegreeProgram program) {
	this->studentID = studentID;  //the parameter for this constructor is assigned to the/this class member
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < daysInCourseArray; i++) {
		this->daysInCourse[i] = daysInCourse[i];
	}
	this->degreeProgram = program;

}  

Student::~Student() {}; //destructor

//define getters 
string Student::GetStudentID() const 
{ 
	return this->studentID; 
}
string Student::GetFirstName() const 
{
	return this->firstName;
}
string Student::GetLastName() const 
{ 
	return this->lastName;
}
string Student::GetEmail() const
{ 
	return this->email;
}
int Student::GetAge() const 
{ 
	return this->age; 
}
int* Student::GetDaysInCourse()
{ 
	return this->daysInCourse;
}
DegreeProgram Student::getDegreeProgram() const 
{ 
	return this->degreeProgram; 
}


//define setters
void Student::SetStudentID(string studentID) { this->studentID= studentID; }
void Student::SetFirstName(string firstName) { this->firstName = firstName; }
void Student::SetLastName(string lastName) { this->lastName = lastName; }
void Student::SetEmail(string email) { this->email = email; }
void Student::SetAge(int age) { this->age = age; }
void Student::SetDaysInCourse(int daysInCourse[])
{
	for (int i = 0; i < daysInCourseArray; i++) {
		this->daysInCourse[i] = daysInCourse[i];
	}
}
void Student::SetDegreeProgram(DegreeProgram program) { this->degreeProgram = program; }

//D.2.3 print function definition
void Student::print() {
	cout << this->GetStudentID() << '\t';
	cout << setw(5) << "First Name: " << this->GetFirstName()<<'\t';
	cout << setw(5) << "Last Name: " << this->GetLastName() << '\t';
	//cout << setw(5) << "Email: " << this->GetEmail() << '\t';
	cout << setw(5) << "Age: " << this->GetAge() << '\t' ;
	cout << setw(20) << "daysInCourse: {" << this->GetDaysInCourse()[0] << ',';
	cout << this->GetDaysInCourse()[1] << ',';
	cout << this->GetDaysInCourse()[2] << '}';
	cout << setw(15) << "Degree: " << degreeProgramStrings[this->getDegreeProgram()] << '\n';
}