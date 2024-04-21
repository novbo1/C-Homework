/*
Define a class BoxOfProduce
contains 3 bundles of fruits/vegetables
represent fruits using string (file)
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
//declare constants
const int SIZE1 = 3;
const int SIZE2 = 5;
//declare a class BoxOfProduce
class BoxOfProduce
{
public:
	//Initilize
	void setBundlesOfFruits(string produce[SIZE1]);
	//get results
	void getBundlesOfFruits();
private:
	string produce[SIZE1];
};
//Read all the elements in the file to another array
void readFileStrings(string[]);
//Get randomized number
void getRandomNumber(int[]);

int main()
{
	//get random
	srand(time(NULL));

	BoxOfProduce  produceBundle;                   //object
	string temp[SIZE2], selectedStrings[SIZE1];    //temp has all 5 vegetable , selectedString has random 3 element from temp
	int randomizedNumber[SIZE1];                   //container for random number

	readFileStrings(temp); //all produce
	getRandomNumber(randomizedNumber); //random 3 numbers
	//get 3 random element from temp[]
	for (int i = 0; i < SIZE1; i++)
	{
		selectedStrings[i] = temp[randomizedNumber[i]];
	}
	//initilize
	produceBundle.setBundlesOfFruits(selectedStrings);
	//output
	produceBundle.getBundlesOfFruits();

	return 0;
}

void readFileStrings(string returnString[SIZE2])
{
	string temp[SIZE2];
	fstream getProduce; //use file
	//open file
	getProduce.open("Q4.txt");
	//get file elements stored
	for (int i = 0; i < SIZE2; i++)
	{
		getProduce >> temp[i];
	}

	for (int i = 0; i < SIZE2; i++)
	{
		temp[i] = returnString[i];
	}
	//close file
	getProduce.close();
}

void getRandomNumber(int random[SIZE1])
{
	//get random number ranged from 0 to 4
	for (int i = 0; i < SIZE1; i++)
	{
		random[i] = rand() % 5;
	}
}
void BoxOfProduce::setBundlesOfFruits(string produceTemp[SIZE1])
{
	for (int i = 0; i < SIZE1; i++)
	{
		produce[i] = produceTemp[i];
	}
}

void BoxOfProduce::getBundlesOfFruits()
{
	cout << "Current bundle contains > " << endl;

	for (int i = 0; i < SIZE1; i++)
	{
		cout << produce[i] << endl;
	}
}