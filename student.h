#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;


class Student {
	public: 
		//Accessor Functions
		string getStudentID() const;
		string getFirstName() const;
		string getLastName() const;
		string getEmailAddress() const;
		int getStudentAge() const;
		int getDays1() const;
		int getDays2() const;
		int getDays3() const;
		DegreeProgram getDegreeProgram() const;

		//Mutator Functions
		void setStudentID(string newID);
		void setFirstName(string newFirst);
		void setLastName(string newLast);
		void setEmailAddress(string newEmail);
		void setStudentAge(int newAge);
		void setDays1(int newDays1);
		void setDays2(int newDays2);
		void setDays3(int newDays3);
		void setDegreeProgram(DegreeProgram newDegree);

		//Constructor Functions
		Student(); // Default Constructor
		Student(string resStudentID, string resFirstName, string resLastName, string resEmail, int resAge, int resDaysInCourse[3], DegreeProgram resDegree); //Overloaded Constructor

		//Destructor Function
		~Student();

		//Copy Constructor
		Student(const Student& origStudent);

		//Copy Assignment Operator
		Student& operator=(const Student& objToCopy);

		//Print Function
		void print() const;

	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int studentAge;
		int daysInCourse[3];
		DegreeProgram degreeProgram;			
};
#endif