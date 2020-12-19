#include "roster.h"
#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using std::string;

// Receive student record from ClassRosterParse, and create new student object then add object to classRosterArray
// Sends arguements to student() constructor
void Roster::Add(string studentID, string firstName, string lastName, string emailAddress,
				 int age, int days1, int days2, int days3, DegreeProgram degree) {
	int numDays[] = {days1, days2, days3};

	classRosterArray[++index] = new Student(studentID, firstName, lastName, emailAddress, age, numDays, degree);
}

// Parse each record from the studentData table and send to Roster::Add
void Roster::ClassRosterParse(string record) {
	std::vector<string> tokens;
	DegreeProgram testDegree;
	for (int i = 0; i < NUM_STUDENTS; ++i) {
		std::stringstream ss(record);
		
		while (ss.good()) {
			string subStr;
			std::getline(ss, subStr, ',');
			tokens.push_back(subStr);
		}
		
		if (tokens[8] == "SECURITY") {
			testDegree = DegreeProgram::SECURITY;
		}
		if (tokens[8] == "NETWORK") {
			testDegree = DegreeProgram::NETWORK;
		}
		if (tokens[8] == "SOFTWARE") {
			testDegree = DegreeProgram::SOFTWARE;
		}
	}
	Roster::Add(tokens.at(0), tokens.at(1), tokens.at(2), tokens.at(3), stoi(tokens.at(4)), stoi(tokens.at(5)),
				stoi(tokens.at(6)), stoi(tokens.at(7)), testDegree);
}

// Remove student record with studentID input
void Roster::Remove(string studentID) {
	std::cout << "Removing student record with student ID: " << studentID << "..." << std::flush;
	for (int k = 0; k < NUM_STUDENTS; ++k) {
		if (classRosterArray[k] == nullptr) {
			std::cout << "...Record does not exist!" << std::endl;
			break;
		}
		else if (studentID == classRosterArray[k]->Student::getStudentId()) {
			classRosterArray[k] = nullptr;
			std::cout << "Student record removed!" << std::endl;
		}
	}
}

// Print entire classRosterArray, [tab] separated
void Roster::PrintAll() {
	for (int i = 0; i < NUM_STUDENTS; ++i) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->Student::Print();
		}
	}
}

// Takes studentID input, retrieves numDays array and averages the days, then outputs that avg
void Roster::PrintAvgDaysInCourse(string studentID) {
	for (int k = 0; k < NUM_STUDENTS; ++k) {
		if (studentID == classRosterArray[k]->Student::getStudentId()) {
			int* days = classRosterArray[k]->getNumDays();
			std::cout << studentID << "'s average days in course: ";
			int avgDays = (days[0] + days[1] + days[2]) / 3;
			std::cout << avgDays << std::endl;
		}
	}
}

// Prints emails that have spaces, no '@', or no '.'
void Roster::PrintInvalidEmails() {
	for (int i = 0; i < NUM_STUDENTS; ++i) {
		bool foundAt = false;
		bool foundPeriod = false;
		bool foundSpace = false;
		string email = "";
		email = classRosterArray[i]->Student::getEmailAddress();
		for (char &charIndex : email) {
			if (charIndex == '@') {
				foundAt = true;
			}
			if (charIndex == '.') {
				foundPeriod = true;
			}
			if (charIndex == ' ') {
				foundSpace = true;
			}
		}
		// foundAt and foundPeriod need to be true for valid emails.
		// foundSpace needs to be false for valid emails
		if (foundAt == false || foundPeriod == false || foundSpace == true) {
			std::cout << classRosterArray[i]->Student::getEmailAddress() << std::endl;
		}
	}
}

// recieves DegreeProgram enumerated value as input and returns each record with that degree
void Roster::PrintByDegreeProgram(DegreeProgram degree) {
	std::cout << std::endl << "Printing by degree..." << std::endl;
	for (int i = 0; i < NUM_STUDENTS; ++i) {
		if (classRosterArray[i] != nullptr) {
			if (degree == classRosterArray[i]->Student::getDegree()) {
				classRosterArray[i]->Student::Print();
			}
		}
	}
	std::cout << std::endl;
}

// destructor
Roster::~Roster() {}
