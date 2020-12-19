//
//  roster.h
//  C867 JYM1 - ClassRoster
//
//  Created by Aaron Bahr on 12/17/20.
//

#ifndef roster_h
#define roster_h
#pragma once
#include "degree.h"
#include "student.h"
#include <stdio.h>
#include <string>
using std::string;

const int DATA_COLS = 9;
static const unsigned int NUM_STUDENTS = 5;

class Roster {
public:
	/* ARRAY OF POINTERS */
	Student* classRosterArray[NUM_STUDENTS] = {nullptr, nullptr, nullptr, nullptr, nullptr};
	
	void Add(string studentID, string firstName, string lastName, string emailAddress, int age,
			 int days1, int days2, int days3, DegreeProgram degree);
	void ClassRosterParse(string record);
	void Remove(string studentID);
	void PrintAll();
	void PrintAvgDaysInCourse(string studentID);
	void PrintInvalidEmails();
	void PrintByDegreeProgram(DegreeProgram degree);
	
	
	/* DESTRUCTOR */
	~Roster();
	
private:
	// data member for incrementally adding student object in Roster::Add
	int index = -1;
};

#endif /* roster_h */
