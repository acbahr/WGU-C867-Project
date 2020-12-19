//
//  student.cpp
//  C867 JYM1 - ClassRoster
//
//  Created by Aaron Bahr on 12/17/20.
//

#include "student.h"
#include <iostream>
using std::string;

// constructors
// initializes blank student record
Student::Student() : studentID(""), firstName(""), lastName(""), emailAddress(""),
age(-1), numDays(new int[DAYS_SIZE]) {
	for (int i = 0; i < DAYS_SIZE; ++i) {
		this->numDays[i] = 0;
	}
}

// using mutators to create student object. receives arguements from Roster::Add
Student::Student(string studentID, string firstName, string lastName, string emailAddress,
				 int age, int numDays[], DegreeProgram degree)
{
	setStudentId(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmailAddress(emailAddress);
	setAge(age);
	setNumDays(numDays);
	setDegree(degree);
}

/* MUTATORS */
void Student::setStudentId(string studentID) {
	this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setNumDays(int numDays[]) {
	this->numDays = new int[DAYS_SIZE];
	for (int i = 0; i < DAYS_SIZE; ++i) {
		this->numDays[i] = numDays[i];
	}
}
void Student::setDegree(DegreeProgram degree) {
	this->degree = degree;
}

/* ACCESSORS */
string Student::getStudentId() const {
	return studentID;
}
string Student::getFirstName() const {
	return firstName;
}
string Student::getLastName() const {
	return lastName;
}
string Student::getEmailAddress() const {
	return emailAddress;
}
int Student::getAge() const {
	return age;
}
int* Student::getNumDays() const {
	return numDays;
}
DegreeProgram Student::getDegree() {
	return degree;
}

// print student record
void Student::Print() {
	std::cout << getStudentId();
	std::cout << "\tFirst name: " << getFirstName();
	std::cout << "\tLast name: " << getLastName();
	//std::cout << "\tEmail address: " << getEmailAddress();
	std::cout << "\tAge: " << getAge();
	int* days = getNumDays();
	std::cout << "\tDays in courses: ";
	for (int i = 0; i < DAYS_SIZE; ++i) {
		std::cout << days[i] << " ";
	}
	/* convert enum degree into string for printing purposes */
	string degreeString = "";
	switch (getDegree()) {
		case DegreeProgram::SECURITY:
			degreeString = "SECURITY";
			break;
		case DegreeProgram::NETWORK:
			degreeString = "NETWORK";
			break;
		case DegreeProgram::SOFTWARE:
			degreeString = "SOFTWARE";
			break;
	}
	std::cout << "\tDegree: " << degreeString << std::endl;
}

// deconstructor
Student::~Student() {}

