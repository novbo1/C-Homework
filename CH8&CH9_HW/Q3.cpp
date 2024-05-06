#include <iostream>
#include <cstdlib>
using namespace std;

//class to use ++ or -- for prime numbers
class PrimeNumber
{
public:
	//constructor
	PrimeNumber(int number) { this->number = number; }
	PrimeNumber() { number = 1; }

	int getPrimeNumber() { return number; }

	//overloaded functions for ++ and --
	PrimeNumber operator++();    //prefix
	PrimeNumber operator--();
	//PrimeNumber operator++(int); //postfix
	//PrimeNumber operator--(int);

private:
	int number;
};

int main()
{
	PrimeNumber test1(13);
	++test1;
	cout << test1.getPrimeNumber() << endl;
	return 0;
}

PrimeNumber PrimeNumber::operator++()
{
	int nextPrime = 0;
	bool result = true;

	for (int i = number; i < number + 10; i++)
	{
		for (int j = 2; j < i-1; j++)
		{
			if (i % j == 0)
			{
				result = false;
				break;
			}
		}
		if (result)
		{
			nextPrime = i;
		}
		result = true;
	}
	number = nextPrime;
	return PrimeNumber(nextPrime);
}

PrimeNumber PrimeNumber::operator--()
{
	int lastPrime;

	if (number == 1)
	{
		cout << "There's no prime number before 1" << endl;
		exit(1);
	}

	for (int i = number;i > number-10;i--)
	{
		for (int j = 2; j < i - 1;j++)
		{
			if (i % j == 0)
			{
				lastPrime = i;
				break;
			}
		}
	}

	return PrimeNumber(lastPrime);
}

/*PrimeNumber PrimeNumber::operator++(int filter)
{
	int nextPrime;

	for (int i = number; i < number + 10; i++)
	{
		for (int j = 2; j < i - 1; j++)
		{
			if (i % j == 0)
			{
				nextPrime = i;
				break;
			}
		}
	}
	number = nextPrime;
	return PrimeNumber(nextPrime);
}*/

/*PrimeNumber PrimeNumber::operator--(int filter)
{
	int lastPrime;

	if (number == 1)
	{
		cout << "There's no prime number before 1" << endl;
		exit(1);
	}

	for (int i = number;i > number - 10;i--)
	{
		for (int j = 2; j < i - 1;j++)
		{
			if (i % j == 0)
			{
				lastPrime = i;
				break;
			}
		}
	}

	return PrimeNumber(lastPrime);
}*/