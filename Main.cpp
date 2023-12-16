#include <string>
#include <iostream>
#include "roster.h"

int main() {
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,name,surname,email,0,0,0,0,SOFTWARE"
	};

	const int studentDataLength = (sizeof(studentData) / sizeof(studentData[0]));

	
	cout << "Scripting and Programming - Applications - C867\n"
		<< "Language: C++\n"
		<< "WGU Student ID: 001349684\n"
		<< "Name: Andy Wong\n\n";

	
	Roster* classRoster = new Roster(studentDataLength);

	
	for (int i = 0; i < studentDataLength; i++) {
		classRoster->parseStudentDataThenAdd(studentData[i]);
	}

	

	
	cout << "Printing All Data from Class Roster\n";
	classRoster->printAll();
	cout << "\n";

	
	classRoster->printInvalidEmails();
	cout << "\n";

	
	cout << "Average Days for All Students\n";
	for (int i = 0; i < studentDataLength; i++) {
		string currentStudentId = classRoster->classRosterArray[i]->getStudentId();
		classRoster->printAverageDaysInCourse(currentStudentId);
	}
	cout << "\n";

	
	cout << "Printing all students in SOFTWARE Program\n";
	classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << "\n";

	cout << "Removing Student with ID A3";
	classRoster->remove("A3");
	cout << "\n";
	
	cout << "Printing All Data from Class Roster after removing A3\n";
	classRoster->printAll();
	cout << "\n";

	cout << "\n";
	cout << "Trying to remove Student with ID A3, will throw error\n";
	classRoster->remove("A3");

	return 0;
}