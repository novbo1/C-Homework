/*
Define a class HotDogStand ,that can store stands ID number   
,and how many hot dogs stand sold that day
Create a constructor  that allows user to initilze both value
Create JustSold that tracks the number of hot dogs the stand has sold 
Create a function returns the number of hot dogs sold
Add a static variable that tracks the total number of hot dogs sold by all stand
Add a static function that returns the value in the variable
Test with 3 hot dog stands
*/
#include <iostream>
using namespace std;
//declare a class HotDogStand
class HotDogStand
{
public:
	//Initilize
	HotDogStand(int standNumber, int hotDogSold)
		: standNumber(standNumber), hotDogSold(hotDogSold)
	{
		totalSold += hotDogSold; // Add initial hot dogs sold to totalSold
	}
	//Default
	HotDogStand()
	{
		standNumber = 0, hotDogSold = 0;
	}
	void JustSold()
	{
		hotDogSold += 1, totalSold += 1;
	}
	int getHotDogSold()
	{
		return hotDogSold;
	}
	int getStandID()
	{
		return standNumber;
	}
	//return total hotdog by all stand
	static int getTotalHotDogSold() 
	{
		return totalSold;
	}

private:
	int standNumber;
	int hotDogSold;
	static int totalSold;
};
//initilize total sold to 0
int HotDogStand::totalSold = 0;

void output(HotDogStand, HotDogStand, HotDogStand);

int main()
{
	HotDogStand stand1(1000, 10), stand2(2000, 20), stand3(2000, 30);

	cout << "Current\n";
	output(stand1, stand2, stand3);

	stand1.JustSold();
	stand2.JustSold();
	stand3.JustSold();

	cout << endl;

	cout << "Test JustSold \n";
	output(stand1, stand2, stand3);

	return 0;
}

void output(HotDogStand stand1, HotDogStand stand2, HotDogStand stand3)
{
	cout << "stand1   " << stand1.getStandID() << "   " << stand1.getHotDogSold() << endl;
	cout << "stand2   " << stand2.getStandID() << "   " << stand2.getHotDogSold() << endl;
	cout << "stand3   " << stand3.getStandID() << "   " << stand3.getHotDogSold() << endl;
	cout << "Total sold > " << HotDogStand::getTotalHotDogSold() << endl;
}