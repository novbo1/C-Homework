#include <iostream>
#include <string>
using namespace std;

class UniverstiyStaff
{
public:
	UniverstiyStaff();
	UniverstiyStaff(string theName);
	UniverstiyStaff(const UniverstiyStaff& theObject);
	string getName() const;
	UniverstiyStaff& operator= (const UniverstiyStaff& rtSide);

	friend istream& operator>>(istream& inStream, UniverstiyStaff& staffObject);
	friend ostream& operator<<(ostream& outStream, const UniverstiyStaff& staffObject);

private:
	string name;
};

class Student : public UniverstiyStaff
{
public:
private:
	string universityName;
	int registrationNumber;
	UniverstiyStaff proctor;
};

class ScienceStudent : public Student
{
private:
public:
	string discipline;
	string postgraduateCourse;
}

int main()
{

}
