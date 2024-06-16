#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Dice
{
public:
	//Constructor for Dice
	Dice() : numSides(6) { srand(time(NULL)); }
	Dice(int numSides) : numSides(numSides) { srand(time(NULL)); }

	//function to roll two dice , and return the sum
	int rollTwoDice(const Dice& die1, const Dice& die2)
	{
		return die1.rollDice() + die2.rollDice();
	}

	//Virtual function for roll dice
	virtual int rollDice() const { return rand() % numSides + 1; }
protected:
	int numSides;
};

class LoadedDice : public Dice
{
public:
	//Constructor for LoadedDice
	LoadedDice() : Dice() {}
	LoadedDice(int numSides) : Dice(numSides) {}

	int rollDice() const override
	{
		int die = Dice::rollDice();

		//50% chance to set roll into largest
		if (rand() % 100 < 50)
		{
			die = numSides;
		}

		return die;
	}
};

int main()
{
	//Declaration
	Dice die1,die2;
	LoadedDice Ldie1,Ldie2;

	int sumOfTwoDice;

	cout << "The sum of two dice" << endl;
	for (int i = 0; i < 10; i++)
	{
		sumOfTwoDice = die1.rollTwoDice(die1, die2);
		cout << "Iterate " << i+1 << ": " << sumOfTwoDice << endl;
	}

	cout << endl; 

	cout << "The sum of two dice" << endl;
	for (int i = 0; i < 10; i++)
	{
		sumOfTwoDice = Ldie1.rollTwoDice(Ldie1, Ldie2);
		cout << "Iterate " << i+1 << ": " << sumOfTwoDice << endl;
	}

	return 0;
}