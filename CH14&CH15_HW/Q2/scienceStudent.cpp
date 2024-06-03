#include <iostream>
#include <string>
#include "scienceStudent.h"
using namespace std;

namespace University
{
	ScienceStudent::ScienceStudent() : Student(), discipline("None"), postgraduateCourse("None") {}

	ScienceStudent::ScienceStudent(Student stu, string discipline, string postgraduateCourse) :
		student(stu), discipline(discipline), postgraduateCourse(postgraduateCourse) {}

	ScienceStudent::ScienceStudent(const ScienceStudent& stu) : 
		student(stu.student), discipline(stu.discipline), postgraduateCourse(stu.postgraduateCourse) {}

    void ScienceStudent::getInfo()
    {
        cout << "_____________________\n";
        cout << "Science Student Information:\n";
        student.getInfo();
        cout << "Discipline: " << discipline << endl
            << "Postgraduate Course: " << postgraduateCourse << endl
            << "_____________________\n";
    }
}