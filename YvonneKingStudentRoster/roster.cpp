#include "roster.h"
#include "student.h"
#include <string>
#include <cstring>
#include <iomanip>
void Roster::parse(string studentData) {
	DegreeProgram degreeProgram = SOFTWARE;
	
	string foundSecurity = "SECURITY";
	string foundNetWork = "NETWORK";
	string foundSoftware = "SOFTWARE";

		if (studentData.find(foundSecurity, 0) != string::npos) {
			degreeProgram = SECURITY;
		}
		else if (studentData.find(foundNetWork, 0) != string::npos) {
			degreeProgram = NETWORK;
		}

	
		int rightside = studentData.find(",");
		string ID = studentData.substr(0, rightside);

		
		int leftside = rightside + 1; 
		rightside = studentData.find(",", leftside);
		string firstN = studentData.substr(leftside, rightside - leftside);

		leftside = rightside + 1;
		rightside = studentData.find(",", leftside);
		string lastN = studentData.substr(leftside, rightside - leftside);

		leftside = rightside + 1;
		rightside = studentData.find(",", leftside);
		string email = studentData.substr(leftside, rightside - leftside);

		leftside = rightside + 1;
		rightside = studentData.find(",", leftside);
		int studentAge = stod(studentData.substr(leftside, rightside - leftside));

		leftside = rightside + 1;
		rightside = studentData.find(",", leftside);
		int days1 = stod(studentData.substr(leftside, rightside - leftside));

		leftside = rightside + 1;
		rightside = studentData.find(",", leftside);
		int days2 = stod(studentData.substr(leftside, rightside - leftside));

		leftside = rightside + 1;
		rightside = studentData.find(",", leftside);
		int days3 = stod(studentData.substr(leftside, rightside - leftside));

	
		add(ID, firstN, lastN, email, studentAge, days1, days2, days3, degreeProgram);


}
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int courseDays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, courseDays, degreeProgram);
}
void Roster::printAll() {
	cout << "Displaying all students: " << endl;
	cout << endl;
	//Student::printHeader();
	
	for (int i = 0; i <= Roster::lastIndex; ++i) 
	{
		classRosterArray[i]->Student::print();
	}

}

void Roster::printByDegreeProgram(DegreeProgram program) {
	//Student::printHeader();
	int i = 0;
	
	for (int i = 0; i <= Roster::lastIndex; i++) 
	{
		if (Roster::classRosterArray[i]->getDegreeProgram() == program)
		{ 
			classRosterArray[i]->print(); 
		}
	}
	cout << endl;
}



//E.3.e verify student email, display all invalid email addresses. 
//should include @ and . and no spaces
void Roster::printInvalidEmails() {
	cout << "Displaying invalid emails: " << endl;
	cout << endl;
	{
		bool badEmail = false;
		for (int i = 0; i <= Roster::lastIndex; i++)
		{
			string email = (Roster::classRosterArray[i]->GetEmail());

			if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') !=string::npos) {
				badEmail = true;
					cout << email << ": " << Roster::classRosterArray[i]->GetStudentID() << endl;
			}
			else if (badEmail ==false && i <1 ) {
				cout << "NO INVALID EMAIL FOUND" << endl;
			}
		}
	}
	cout << endl;
	cout << endl;
}


//print average number of days in the three courses, identified by the student ID
void Roster::printAverageDaysInCourse(string studentID) {
	
	double average = 0.0;
	for (int i = 0; i <= lastIndex; i++) {
	
		if (Roster::classRosterArray[i]->GetStudentID() == studentID)
		{
			cout << Roster::classRosterArray[i]->GetStudentID() << ":" <<
				(classRosterArray[i]->GetDaysInCourse()[0] +
					classRosterArray[i]->GetDaysInCourse()[1] +
					classRosterArray[i]->GetDaysInCourse()[2]) / 3.0 << endl;
		}
	}

	
}


void Roster::remove(string studentID) 
{
	bool removed = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (classRosterArray[i]->GetStudentID() == studentID) // if  studentID at index i  equals input student ID
		{
			removed = true;
			if (i <= numStudents ) // as long as i  is less than or equal to numStudents of 5
			{
				Student*  temporary = classRosterArray[i]; //temporary holding address of index 2 /A3
				classRosterArray[i] = classRosterArray[numStudents-2]; //index 2 /a3 now asssiged to index 3 /a4 address 
				classRosterArray[i + 1] = classRosterArray[numStudents -1];  //index 2 + 1 == index3 now should equal address index 4 /a5
				
				
				classRosterArray[numStudents-1] = temporary; // temp holding info from index 2 now assigned to index 4
				
			}
			Roster::lastIndex--; //removing info at index 4
		}
	}
		if (removed == true) 
		{
			cout << studentID << " removed from repository" << endl;
			cout << endl;
			this->printAll();
		}
		else {
			cout << studentID << " not found." << endl;
		}
	}



Roster::~Roster() {
	cout << endl;
	for (int i = 0; i < numStudents; i++) {
		cout << "Destroying student: " << Roster::classRosterArray[i]->GetStudentID()<<endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
 }



