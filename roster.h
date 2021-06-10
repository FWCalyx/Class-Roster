#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"
#include "degree.h"
#include <string>
#include <iostream>

using namespace std;
//Defines the Roster Class
class Roster {
	public: 
		void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
		void parse(string row);
		void remove(string studentID);
		void printAll();
		void printAverageDaysInCourse(string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(DegreeProgram degreeProgram);
		Roster();
		Roster(Student* classRosterArray[5]);
		~Roster();
	private:
		Student* classRosterArray[5];
		int stuCounter = 0;
};

#endif
