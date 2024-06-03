#include <iostream>
#include "scienceStudent.h"

using namespace University;

int main() {
    // Create a University staff member
    UniverstiyStaff staff("John Doe");

    // Create a Student
    Student student("Oxford", 123456, staff);

    // Create a ScienceStudent
    ScienceStudent scienceStudent(student, "Physics", "Quantum Mechanics");

    // Display information for all objects
    cout << "University Staff: " << staff << endl;
    cout << "Student: " << student << endl;
    cout << "Science Student: " << scienceStudent << endl;

    // Get and display detailed information for the ScienceStudent
    scienceStudent.getInfo();

    return 0;
}