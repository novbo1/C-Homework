#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "universityStaff.h"
using namespace std;

namespace University
{
	class Student : public UniverstiyStaff
	{
	public:
		Student();
		Student(string universityName, int registrationNumber, UniverstiyStaff proctor);
		Student();
	private:
		string universityName;
		int registrationNumber;
		UniverstiyStaff proctor;
	};
}

#endif