#include <iostream>
#include <string>
#include "administrator.h"
using namespace std;

namespace SavitchEmployees
{
	Administrator::Administrator() : title("None"), companyAreaOfReopsibility("None"), supervisorOfAdministrator("None"), annualSalary(0) {}

	Administrator::Administrator(const string& theName, const string& theNumber, double theWeeklyPay, const string& theTitle, const string& respo, const string& supervisor)
		: SalariedEmployee(theName, theNumber, theWeeklyPay), title(theTitle), companyAreaOfReopsibility(respo), supervisorOfAdministrator(supervisor)
	{
		annualSalary = theWeeklyPay * 4 * 12;
	}

	void Administrator::setSupervisor(const string& supervisor) 
	{
		supervisorOfAdministrator = supervisor;
	}


	void Administrator::setInformation()
	{
		cout << "Please enter the administraotr's title, company area of responsbility, administrator's supervisor and the annual salary " << endl;
		getline(cin, title);
		getline(cin, companyAreaOfReopsibility);
		getline(cin, supervisorOfAdministrator);
		cin >> annualSalary;
		cin.ignore();
	}

	void Administrator::print()
	{
		cout << "The administrator's basic information > " << endl;
		cout << "The title: " << title << endl;
		cout << "The company area of responsbility: " << companyAreaOfReopsibility << endl;
		cout << "The supervisor of the administrator: " << supervisorOfAdministrator << endl;
		cout << "The annual salary: " << annualSalary << endl;
	}

	void Administrator::printCheck()
	{
		setNetPay(annualSalary); // Assuming annual salary is the net pay
		cout << "\n________________________________________\n";
		cout << "Pay to the order of " << getName() << endl;
		cout << "The sum of " << getNetPay() << " Dollars\n";
		cout << "________________________________________\n";
		cout << "Check stub NOT NEGOTIABLE \n";
		cout << "Employee Number: " << getSsn() << endl;
		cout << "Salaried Administrator. Regular Pay: " << annualSalary << endl;
		cout << "________________________________________\n";
	}
}