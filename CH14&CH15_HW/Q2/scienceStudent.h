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
	public:
		string discipline;
		string postgraduateCourse;
	};
}


#endif