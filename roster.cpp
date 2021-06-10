#include <iostream>
#include <string>
#include "roster.h"
#include <vector>
#include "student.h"
#include "degree.h"
using namespace std;


//Adds a student using variables provided by parse. Could be modified to receive user input instead. 
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	cout << "Student " << (stuCounter + 1) << "...";
	int resDaysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[stuCounter++] = new Student(studentID, firstName, lastName, emailAddress, age, resDaysInCourse, degreeProgram);
	cout << "added." << endl;
	return;
}
//Parses a row of data in the format provided by const string studentData[].
void Roster::parse(string row) {
	int rhs = 0;											//Sets right-hand search boundary to position 0.
	int lhs = 0;											//Sets left-hand search boundary to position 0.
	vector<string> tempData;								//Creates transfer vector.
	
	while (rhs != string::npos) {							
		rhs = row.find(',', lhs);							//Sets right-hand search boundary to the first comma's position.
		tempData.push_back(row.substr(lhs, (rhs - lhs)));	//Saves substring between boundaries as a value in transfer vector.
		lhs = rhs + 1;										//Moves left-hand boundary to just beyond last comma.
	}
	DegreeProgram degree;								
	string ID    = tempData.at(0);								//Assigns values to transfer variables
	string fName = tempData.at(1);
	string lName = tempData.at(2);
	string email = tempData.at(3);
	int age      = stoi(tempData.at(4));
	int days1    = stoi(tempData.at(5));
	int days2    = stoi(tempData.at(6));
	int days3    = stoi(tempData.at(7));
if (tempData.at(8) == "SECURITY") {
	degree = SECURITY;
}
else if (tempData.at(8) == "NETWORK") {
	degree = NETWORK;
}
else if (tempData.at(8) == "SOFTWARE") {
	degree = SOFTWARE;
}
else {
	cout << "BAD DEGREE! BAD!";
	exit(EXIT_FAILURE);
}
add(ID, fName, lName, email, age, days1, days2, days3, degree);	//Calls add function. 

return;
}
void Roster::remove(string studentID) {								//Removes student by assigning targeted student's pointer to 'nullptr'.
	cout << endl << "Attempting to delete Student with ID " << studentID << "..." << endl << endl;
	int i = 0;
	int sizeLimit = 5;
	bool wasDeleted = false;
	for (i = 0; i < sizeLimit; ++i) {
		if (classRosterArray[i] != nullptr) {

			if ((*classRosterArray[i]).getStudentID() == studentID) {
				classRosterArray[i] = nullptr;
				wasDeleted = true;
			}
		}
	}
	if (wasDeleted == true) {										//Prints appropriate message based on whether a student was deleted or not.
		cout << "Student with ID " << studentID << " was deleted." << endl;
	}
	else {
		cout << "Student ID " << studentID << " not found." << endl << endl;
	}
	return;
}
void Roster::printAll() {										//Prints all students.
	cout << "Printing Full Student List:" << endl << endl;
	int i         = 0;
	int sizeLimit = 5;
	for (i = 0; i < sizeLimit; ++i) {
		if (classRosterArray[i] != nullptr) {					//Eliminates null rows from consideration.
			(*classRosterArray[i]).print();
			}
		}
	return;
}

void Roster::printAverageDaysInCourse(string studentID) {		//Prints average days in course for desired student.
	cout << endl << "Printing Average Days in Course:" << endl << endl;
	int i         = 0;
	int sizeLimit = 5;
	int avg = 0;
	for (i = 0; i < sizeLimit; ++i) {
		if (classRosterArray[i] != nullptr) {					//Eliminates null rows from consideration.
			if ((*classRosterArray[i]).getStudentID() == studentID) {
				cout << "Student with ID " << (*classRosterArray[i]).getStudentID() << " averages ";
				avg = 0;
				avg += (*classRosterArray[i]).getDays1();
				avg += (*classRosterArray[i]).getDays2();
				avg += (*classRosterArray[i]).getDays3();
				cout << (avg / 3) << " days in course." << endl;
			}
		}
	}
	return;
}
void Roster::printInvalidEmails() {								//Prints a list of invalid emails with reasons for invalidation.
	cout << endl << "Printing List of Invalid Emails:" << endl << endl;
	int i = 0;
	int sizeLimit = 5;
	string emailHolder;
	for (i = 0; i < sizeLimit; ++i) {
		if (classRosterArray[i] != nullptr) {					//Eliminates null rows from consideration.
			emailHolder = (*classRosterArray[i]).getEmailAddress();
			if (emailHolder.find(' ') != string::npos) {
				cout << emailHolder << " includes a space." << endl;
			}
			else if (emailHolder.find('@') == string::npos) {
				cout << emailHolder << " is missing an @ symbol." << endl;
			}
			else if (emailHolder.find('.') == string::npos) {
				cout << emailHolder << " is missing a period." << endl;
			}
		}
	}
	return;
}
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) { //Prints students based on degree program entered.
	string whatDegree[] = { "SECURITY", "NETWORK", "SOFTWARE" };
	cout << endl;
	cout << "Students majoring in " << whatDegree[degreeProgram] << ":" << endl << endl;
	int i = 0;
	int sizeLimit = 5;
	for (i = 0; i < sizeLimit; ++i) {
		if (classRosterArray[i] != nullptr) {					//Eliminates null rows from consideration.
			if ((*classRosterArray[i]).getDegreeProgram() == degreeProgram) {
				(*classRosterArray[i]).print();
			}
		}
	}
	cout << endl;
	
	return;
}
Roster::Roster() {								//Default Constructor
	return;
}
Roster::Roster(Student* classRosterArray[5]) {  //Overloaded Constructor
	return;
}
Roster::~Roster() {								//Destructor
	return;
}