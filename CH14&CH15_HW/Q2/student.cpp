#include <iostream>
#include <string>
#include "student.h"

namespace University
{
	Student::Student() : universityName("None"), registrationNumber(0), proctor() {}

	Student::Student(string universityName, int registrationNumber, UniverstiyStaff proctor) :
		universityName(universityName), registrationNumber(registrationNumber), proctor(proctor) {}

	Student::Student(const Student& other) : 
		universityName(other.universityName) , registrationNumber(other.registrationNumber) , proctor(other.proctor) {}


	void Student::getInfo()
	{
		cout << "_____________________\n";
		cout << "Student Information : \n"
			<< "University Name: " << universityName << endl
			<< "Registration Number: " << registrationNumber << endl
			<< "Proctor's Name: " << proctor.getName() << endl
			<< "_____________________\n";
	}
}