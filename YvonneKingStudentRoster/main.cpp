#include "roster.h"
using namespace std;

int main() {
	//F.1 
	cout << "C867 Scripting and Programming - Applications" << endl; 
	cout << "C++ Programming Language" << endl;
	cout << "Student ID: 001231138" << endl;
	cout << "Yvonne M King " << endl;
	cout << endl;
	cout << "*************" << endl;
	cout << "*************" << endl;
	cout << endl;

	const int numStudents = 5;
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawery99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Yvonne,King ,von_amari@hotmail.com,40,15,33,20,SOFTWARE", //A. Modifiy table to include your name
	};

	//FIXME course days not displaying
	
	Roster classRoster; // creating default contructor

	//parsing studentData
	for (int i = 0; i < numStudents; ++i) {
		classRoster.parse(studentData[i]);
	}
	//display all students on roster	
	classRoster.printAll();
	cout << endl;
	

	//display invalid emails 
	classRoster.printInvalidEmails();

	//classRoster.printAverageDaysInCourse(string(classRoster));


	//display software degree students
	cout << "Displaying " << degreeProgramStrings[2] << " degree students: " << endl;
	classRoster.printByDegreeProgram((DegreeProgram)SOFTWARE);


	//display students by degree plan
	for (int i = 0; i < 3; i++) {
		cout << "Displaying students by degree program : " << degreeProgramStrings[i] << endl; classRoster.printByDegreeProgram((DegreeProgram)i);
	}

	

	//student's average days in course
	cout << "Average days in course by student ID: " << endl;
	for (int i = 0; i < numStudents; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
	}
	cout << endl;


	//remove student ID A3
	cout << "Removing Student A3 " << endl;
	classRoster.remove("A3");
	cout << endl;
	cout << "Removing Student A3 " << endl;
	classRoster.remove("A3");
	cout << endl;



	cout << endl;
	cout << "DESTRUCTOR" << endl;
	system("pause");
	return 0;
}