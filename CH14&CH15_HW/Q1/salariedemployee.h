#ifndef SALARIEDEMOPLOYEE_H
#define SALARIEDEMOPLOYEE_H

#include <string>
#include "employee.h"

using std::string;

namespace SavitchEmployees
{
	class SalariedEmployee : public Employee
	{
	public:
		SalariedEmployee();
		SalariedEmployee(const string&, const string&, double);
		double getSalary() const;
		void setSalary(double);
		void printCheck();

	private:
		double salary;
	};
}

#endif
