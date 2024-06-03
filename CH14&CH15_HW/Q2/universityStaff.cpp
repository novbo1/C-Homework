#include <iostream>
#include <string>
#include "universityStaff.h"
using namespace std;

namespace University
{
	//Default case
	UniverstiyStaff::UniverstiyStaff() : name("None") {}

	//Save name
	UniverstiyStaff::UniverstiyStaff(string name) : name(name) {}

	//Copy constructor
	UniverstiyStaff::UniverstiyStaff(const UniverstiyStaff& other) : name(other.name) {}

	//read name
	string UniverstiyStaff::getName() const { return name; }

	//= operator
	UniverstiyStaff& UniverstiyStaff::operator=(const UniverstiyStaff& rtSide)
	{
		if (this != &rtSide)
		{
			name = rtSide.name;
		}

		return *this;
	}

	//cin for object
	istream& operator>>(istream& inStream, UniverstiyStaff& staffObject)
	{
		// Read the name from the input stream
		getline(inStream, staffObject.name);
		return inStream;
	}

	//cout for object
	ostream& operator<<(ostream& outStream, const UniverstiyStaff& staffObject)
	{
		// Output the name to the output stream
		outStream << staffObject.name;
		return outStream;
	}
}