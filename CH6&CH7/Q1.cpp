/*
Define a class called pizza
We know
	type of pizza > deep dish , hand tossed, pan 
	along with size > small , medium , large
	the number of pepperoni/cheese toppings
Caculate the pizza price based on following and the list the description 
*/

#include <iostream>
#include <cstdlib>
using namespace std;

//define a class PIzza
class Pizza
{
public:
	void input();                //input all the basic member variables
	void outputDescription();    //output the description and price
private:
	int type;                    //pizza type
	int size;                    //pizza size
	int numberOfTopping;         //number of pizzas topping
	void test();                 //test if the number is validate or not 
	double computePrice();       //compute the total price
};

int main()
{
	Pizza customer;                //declare an object called customer
	customer.input();              //input basic info for customer
	customer.outputDescription();  //output the result
	return 0;
}

void Pizza::input()
{
	//prompt
	cout << "How you want your pizza?\n"
		<< "Enter the type of pizza, (0 for deep dish , 1 for hand tossed, 2 for pan)\n"
		<< "along with the size of pizza (0 for small , 1 for medium , 2 for big)\n"
		<< "and the number of pepperoni or cheese toppings.\n";
	//input
	cin >> type >> size >> numberOfTopping;
	//test validate or not
	test();
}

void Pizza::outputDescription()
{
	cout << "The description for your pizza : \n";

	cout << "Type : ";
	switch(type)
	{
	case 0:
		cout << "Deep dish";
		break;
	case 1:
		cout << "Hand tossed";
		break;
	case 2:
		cout << "Pan";
		break;
	default:
		cout << "False input of pizza type.";
	}
	cout << endl << "Size : ";

	switch (size)
	{
	case 0:
		cout << "Small";
		break;
	case 1:
		cout << "Medium";
		break;
	case 2:
		cout << "Large";
		break;
	default:
		cout << "False input of pizza size.";
	}
	cout << endl << "Number of topping : " << numberOfTopping << endl;
	cout << "The price would be " << computePrice();
}

void Pizza::test()
{
	//if out of range , exit the code
	if ((type < 0) || (type > 2))
	{
		cout << "Wrong type input.";
		exit(1);
	}
	if ((size < 0) || (size > 2))
	{
		cout << "Wrong size input.";
		exit(1);
	}
	if (numberOfTopping < 0)
	{
		cout << "Wrong number of topping input.";
		exit(1);
	}
}
double Pizza::computePrice()
{
	double totalPrice;
	int sizePrice;

	switch (size)
	{
	case 0:
		sizePrice = 10;
		break;
	case 1:
		sizePrice = 14;
		break;
	case 2:
		sizePrice = 17;
		break;
	}
	totalPrice = sizePrice + 2 * numberOfTopping;

	return totalPrice;	
}