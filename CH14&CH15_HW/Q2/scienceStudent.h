#ifndef SCIENCESTUDENT_H
#define SCIENCESTUDENT_H
#include "Student.h"

#include <iostream>
#include <string>
using namespace std;

namespace University
{
	class ScienceStudent : public Student
	{
	private:
		//Constructor
		ScienceStudent(); //Default
		ScienceStudent(Student,string,string); 
		ScienceStudent(const ScienceStudent&); //Copy constructor

		//Get basic information
		void getInfo();
	public:
		Student student;
		string discipline;
		string postgraduateCourse;
	};
}


#endif