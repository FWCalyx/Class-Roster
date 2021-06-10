#include <iostream>
#include <string>
#include <vector>
#include "student.h"
using namespace std;

//ENUM Strings
string whatDegree[] = { "SECURITY", "NETWORK", "SOFTWARE" };


//Accessor Functions
string Student::getStudentID() const {
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
int Student::getStudentAge() const {
	return studentAge;
}
int Student::getDays1() const {
	return daysInCourse[0];
}
int Student::getDays2() const {
	return daysInCourse[1];
}
int Student::getDays3() const {
	return daysInCourse[2];
}
DegreeProgram Student::getDegreeProgram() const {
	return degreeProgram;
}

//Mutator Functions
void Student::setStudentID(string newID) {
	studentID = newID;
	return;
}
void Student::setFirstName(string newFirst) {
	firstName = newFirst;
	return;
}
void Student::setLastName(string newLast) {
	lastName = newLast;
	return;
}
void Student::setEmailAddress(string newEmail) {
	emailAddress = newEmail;
	return;
}
void Student::setStudentAge(int newAge) {
	studentAge = newAge;
	return;
}
void Student::setDays1(int newDays1) {
	daysInCourse[0] = newDays1;
	return;
}
void Student::setDays2(int newDays2) {
	daysInCourse[1] = newDays2;
	return;
}
void Student::setDays3(int newDays3) {
	daysInCourse[2] = newDays3;
	return;
}
void Student::setDegreeProgram(DegreeProgram newDegree) {
	degreeProgram = newDegree;
	return;
}

//Constructor Functions
Student::Student() { //Default Constructor
	return;
}
Student::Student(string resStudentID, string resFirstName, string resLastName, string resEmail, int resAge, int resDaysInCourse[3], DegreeProgram resDegree) { //Overloaded Constructor
	studentID       = resStudentID;
	firstName       = resFirstName;
	lastName        = resLastName;
	emailAddress    = resEmail;
	studentAge      = resAge;
	daysInCourse[0] = resDaysInCourse[0];
	daysInCourse[1] = resDaysInCourse[1];
	daysInCourse[2] = resDaysInCourse[2];
	degreeProgram   = resDegree;
	return;
}


//Destructor Function
Student::~Student() {
	cout << "Destructor called for Student Object." << endl << endl;
	return;
}

//Copy Constructor
Student::Student(const Student& origStudent) {
	studentID       = origStudent.studentID;
	firstName       = origStudent.firstName;
	lastName        = origStudent.lastName;
	emailAddress    = origStudent.emailAddress;
	studentAge      = origStudent.studentAge;
	daysInCourse[0] = origStudent.daysInCourse[0];
	daysInCourse[1] = origStudent.daysInCourse[1];
	daysInCourse[2] = origStudent.daysInCourse[2];
	degreeProgram   = origStudent.degreeProgram;
	return;
}

//Copy Assignment Operator
Student& Student::operator=(const Student& objToCopy) {
	if (this != &objToCopy) {
		studentID       = objToCopy.studentID;
		firstName       = objToCopy.firstName;
		lastName        = objToCopy.lastName;
		emailAddress    = objToCopy.emailAddress;
		studentAge      = objToCopy.studentAge;
		daysInCourse[0] = objToCopy.daysInCourse[0];
		daysInCourse[1] = objToCopy.daysInCourse[1];
		daysInCourse[2] = objToCopy.daysInCourse[2];
		degreeProgram   = objToCopy.degreeProgram;
	}

	return *this;
}

//Print Function
void Student::print() const {
	cout << studentID << "\tFirst Name: " << firstName << "\tLast Name: " << lastName << "\tAge: " << studentAge << "\tDays In Course: {" << daysInCourse[0] << "," << daysInCourse[1] << "," << daysInCourse[2] << "}"<< "\tDegree Program: " << whatDegree[degreeProgram] << endl;
	return;
}