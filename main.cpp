#include <iostream>
#include <string>
#include <vector>
#include "roster.h"
#include "student.h"
#include "degree.h"
using namespace std;
//Hello there! I hope you enjoy my program.


//Roster object classRoster is created.
Roster classRoster;

//Breakout function accepts the block of data and begins the row-by-row parse operation.
void breakout(const string block[]) { 
	cout << "###################################" << endl << endl;
	int i = 0; 
	int blockSize = (sizeof(block) + 1);
	cout << "Importing " << blockSize << " new students." << endl << endl;

	string oneString;
	for (i = 0; i < blockSize; ++i) {
		oneString = block[i];
		classRoster.parse(oneString);
	}
}
//Main function begins.
int main() {

	cout << "C867 Scripting and Programming - Applications" << endl << endl;
	cout << "C++" << endl << endl;
	cout << "WGU Student ID: #001689211" << endl << endl;
	cout << "Rebecca Lacoste" << endl << endl;

	//Input block.
    const string studentData[] =

    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
      "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
      "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
      "A5,Rebecca,Lacoste,rlacos1@wgu.edu,43,5,6,8,SOFTWARE" };
	
	


	//Breakout is called to import data.
	breakout(studentData);
	cout << endl << "Import complete." << endl << endl;
	cout << "###################################" << endl << endl;

	//Prints class roster after import.
	classRoster.printAll();

	//Prints list of invalid emails with reasons for invalidation.
	classRoster.printInvalidEmails();

	//Prints the average days in coures for the desired student based on entered StudentID.
	classRoster.printAverageDaysInCourse("A1");

	//Prints students in desired program based on enumerated DegreeProgram value entered.
	classRoster.printByDegreeProgram(SOFTWARE);

	//Deletes student with entered studentID value.
	classRoster.remove("A3");

	//Attempts to delete student a second time and prompts 'Student not found' message.
	classRoster.remove("A3");

	//Prints the updated class roster.
	classRoster.printAll();

	//Destroys classRoster.
	classRoster.~Roster();

	cout << endl << "All done here. Thanks!" << endl;
	return 0;
}