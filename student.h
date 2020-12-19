

#ifndef student_h
#define student_h
#pragma once
#include "degree.h"
//#include "roster.h"
#include <stdio.h>
#include <string>
using std::string;

class Student {
public:
	/* CONSTRUCTORS */
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress,
			int age, int numDays[], DegreeProgram degree);
	
	/* MUTATORS */
	void setStudentId(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setNumDays(int numDays[]);
	void setDegree(DegreeProgram degree);
	
	/* ACCESSORS */
	string getStudentId() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmailAddress() const;
	int getAge() const;
	int* getNumDays() const;
	DegreeProgram getDegree();
	virtual void Print();
	
	const int DAYS_SIZE = 3;
	
	/* DESTRUCTOR */
	~Student();
	
private:
	// DATA MEMBERS
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int* numDays;
	DegreeProgram degree;
};

#endif /* student_h */
