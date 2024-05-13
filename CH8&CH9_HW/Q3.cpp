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
	PrimeNumber operator++(int); //postfix
	PrimeNumber operator--(int);

private:
	int number;
};

int main()
{
	PrimeNumber test1(13);
	++test1;
	cout << test1.getPrimeNumber() << endl;
	test1++;
	cout << test1.getPrimeNumber() << endl;
	--test1;
	cout << test1.getPrimeNumber() << endl;
	test1--;
	cout << test1.getPrimeNumber() << endl;
	return 0;
}

PrimeNumber PrimeNumber::operator++()
{
	int nextPrime = number + 1;
	bool isPrime = false;

	while (!isPrime)
	{
		bool result = true;
		for (int j = 2; j < nextPrime; j++)
		{
			if (nextPrime % j == 0)
			{
				result = false;
				break;
			}
		}
		if (result)
		{
			isPrime = true;
			break; // Found the next prime, exit the loop
		}
		nextPrime++; // Move to the next number
	}

	number = nextPrime;
	return PrimeNumber(nextPrime);
}

PrimeNumber PrimeNumber::operator--()
{
	if (number == 1)
	{
		cout << "There's no prime number before 1" << endl;
		exit(1);
	}

	int prevPrime = number - 1;

	while (true)
	{
		bool isPrime = true;
		for (int i = 2; i <= prevPrime / 2; ++i)
		{
			if (prevPrime % i == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
			break;
		--prevPrime;
	}

	number = prevPrime;
	return PrimeNumber(prevPrime);
}

PrimeNumber PrimeNumber::operator++(int filter)
{
	int nextPrime = number + 1;
	bool isPrime = false;

	while (!isPrime)
	{
		bool result = true;
		for (int j = 2; j < nextPrime; j++)
		{
			if (nextPrime % j == 0)
			{
				result = false;
				break;
			}
		}
		if (result)
		{
			isPrime = true;
			break; // Found the next prime, exit the loop
		}
		nextPrime++; // Move to the next number
	}

	number = nextPrime;
	return PrimeNumber(nextPrime);
}

PrimeNumber PrimeNumber::operator--(int filter)
{
	if (number == 1)
	{
		cout << "There's no prime number before 1" << endl;
		exit(1);
	}

	int prevPrime = number - 1;

	while (true)
	{
		bool isPrime = true;
		for (int i = 2; i <= prevPrime / 2; ++i)
		{
			if (prevPrime % i == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
			break;
		--prevPrime;
	}

	number = prevPrime;
	return PrimeNumber(prevPrime);
}