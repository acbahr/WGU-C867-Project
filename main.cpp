
#include <iostream>
#include <iomanip>
#include "roster.h"
#include "student.h"
#include "degree.h"

using namespace std;

int main() {
	cout << "Scripting and Programming - Applications - C867" << endl;
	cout << "Programming language: C++" << endl;
	cout << "WGU Student ID: 000252647" << endl;
	cout << "Programmer: Aaron Bahr" << endl << endl;
	
	const string studentData[] =
	{
			"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
			"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
			"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
			"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
			"A5,Aaron,Bahr,abahr1@wgu.edu,37,15,24,28,SOFTWARE"
	};
	
	Roster classRoster;
	
	for (int i = 0; i < NUM_STUDENTS; ++i) {
		classRoster.ClassRosterParse(studentData[i]);
	}
	
	classRoster.PrintAll();
	
	cout << endl;
	
	cout << "List of invalid email addresses: " << endl;
	classRoster.PrintInvalidEmails();
	
	cout << endl << "Average days in courses, per student: " << endl;
	for (int i = 0; i < NUM_STUDENTS; ++i) {
		classRoster.PrintAvgDaysInCourse(classRoster.classRosterArray[i]->Student::getStudentId());
	}
	
	classRoster.PrintByDegreeProgram(DegreeProgram::SOFTWARE);
	
	classRoster.Remove("A3");
	cout << endl;
	classRoster.PrintAll();
	cout << endl;
	classRoster.Remove("A3");
	cout << endl;
	
	classRoster.~Roster();
	
	return 0;
}
