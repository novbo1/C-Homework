#ifndef UNIVERSITYSTAFF_H
#define UNIVERSITYSTAFF_H

#include <iostream>
#include <string>
using namespace std;

namespace University
{
	class UniverstiyStaff
	{
	public:
		//Constructor
		UniverstiyStaff();                                 //Default
		UniverstiyStaff(string theName);                   //Take name 
		UniverstiyStaff(const UniverstiyStaff& theObject); //Copy constructor

		//functions
		string getName() const;
		UniverstiyStaff& operator= (const UniverstiyStaff& rtSide);

		//cin cout for object
		friend istream& operator>>(istream& inStream, UniverstiyStaff& staffObject);
		friend ostream& operator<<(ostream& outStream, const UniverstiyStaff& staffObject);

	private:
		string name;
	};
}


#endif