#include <iostream>
#include <string>
#include "salariedemployee.h"
using std::string;
using std::cout;
using std::endl;

namespace SavitchEmployees
{
	SalariedEmployee::SalariedEmployee() : Employee(), salary(0) {}

	SalariedEmployee::SalariedEmployee(const string& theName, const string& theNumber , double theWeeklyPay) :
		Employee(theName,theNumber) , salary(theWeeklyPay) {}

	double SalariedEmployee::getSalary() const
	{
		return salary;
	}

	void SalariedEmployee::setSalary(double newSalary)
	{
		salary = newSalary;
	}

	void SalariedEmployee::printCheck()
	{
		setNetPay(salary);
		cout << "\n________________________________________\n";
		cout << "Pay to the order of " << getName() << endl;
		cout << "The sum of " << getNetPay() << " Dollars\n";
		cout << "________________________________________\n";
		cout << "Check stub NOT NEGOTIABLE \n";
		cout << "Employee Number: " << getSsn() << endl;
		cout << "Salaried Employee. Regular Pay: " << salary << endl;
		cout << "________________________________________\n";
	}
}