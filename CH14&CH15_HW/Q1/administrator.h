#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <iostream>
#include <string>
#include "salariedemployee.h"
using namespace std;

namespace SavitchEmployees
{
	class Administrator : protected SalariedEmployee
	{
	public:
		Administrator();
		Administrator(const string& theName, const string& theNumber, double theWeeklyPay, const string&, const string&, const string&);

		void setSupervisor(const string&);
		void setInformation();
		void print();
		void printCheck();

	private:
		string title;
		string companyAreaOfReopsibility;
		string supervisorOfAdministrator;
	protected:
		double annualSalary;
	};
}

#endif