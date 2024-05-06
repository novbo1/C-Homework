#include <iostream>
using namespace std;

//Class to modify number using [] operator
class MyInteger
{
public:
	void setInteger(int number) { this->number = number; }  //set basic information
	int getInteger() const { return number; }               //get the number stored

	int operator [](int);
private:
	int number;
};

int main()
{
	MyInteger test;
	//test sample number
	test.setInteger(12345);
	//output result for index 0,4,7
	cout << "Test number > " << test.getInteger() << endl;
	cout << "Index number 0 = " << test[0] << endl;
	cout << "Index number 4 = " << test[4] << endl;
	cout << "Index number 7 = " << test[7] << endl;

	return 0;
}

int MyInteger::operator[](int index)
{
	int tempNumber = number;
	int maxDigit = 0;
	//caculate max digit
	while (tempNumber != 0)
	{
		tempNumber /= 10;
		maxDigit++;
	}
	
	//if out of range, then return -1
	if (index >= maxDigit || index < 0)
	{
		return -1;
	}
	//suppose maxium digit is 20
	int numbers[maxDigit];
	int i = 0;

	tempNumber = number;
	//separate number into individual numbers and reverse
	while (maxDigit > 0)
	{
		numbers[i] = tempNumber % 10;
		tempNumber /= 10;
		i++;
		maxDigit--;
	}

	return numbers[index];
}