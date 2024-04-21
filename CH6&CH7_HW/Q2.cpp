/*
Define a class money to store money
We know
	Needs to store dollar and cent (int)
Read and set both variables, then add another function return the money as double
Test code with at least 2 money object
*/
#include <iostream>
using namespace std;
//declare a class called money
class Money 
{
public:
    void setMoney(int dollar, int cent); 
    void getMoney();
    double getTotalMoney(); // Added method to return total money as double
private:
    int dollar;
    int cent;
};

void Money::setMoney(int dollar, int cent) 
{
    this->dollar = dollar;   //dollar in private = variable dollar 
    this->cent = cent;    
}

void Money::getMoney() 
{
    if (cent < 10) 
    {
        cout << "You have $" << dollar << ".0" << cent << endl;
    }
    else 
    {
        cout << "You have $" << dollar << "." << cent << endl;
    }
}

double Money::getTotalMoney() 
{
    return dollar + (cent / 100.0); // Convert cents to dollars and add to dollar amount
}

int main() 
{
    Money money1, money2;

    // Set values for money1
    money1.setMoney(10, 50);

    // Set values for money2
    money2.setMoney(5, 75);

    // Display money amounts
    money1.getMoney();
    money2.getMoney();

    // Display total money as double
    cout << "Total money in money1: $" << money1.getTotalMoney() << endl;
    cout << "Total money in money2: $" << money2.getTotalMoney() << endl;

    return 0;
}