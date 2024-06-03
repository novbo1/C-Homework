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
		//Constructor
		Student();  //Default
		Student(string universityName, int registrationNumber, UniverstiyStaff proctor); 
		Student(const Student&); //Copy constructor

		void  getInfo();
	private:
		string universityName;
		int registrationNumber;
		UniverstiyStaff proctor;
	};
}

#endif