/*
Create a class Weight
create 3 set functions to take weight as input (pounds kilongrams ounces)
create function return stored weight in pounds kilograms ounces
*/

#include <iostream>
using namespace std;
//define a class Weight
class Weight {
public:
    //Initilize
    void setWeightPounds(double pounds);
    void setWeightKilograms(double kilograms);
    void setWeightOunces(double ounces);
    //Convert
    double getWeightPounds() const;
    double getWeightKilograms() const;
    double getWeightOunces() const;

private:
    double pounds;
};

int main() {
    Weight weight;

    // Set weight in pounds
    weight.setWeightPounds(10.5);
    cout << "Weight in pounds: " << weight.getWeightPounds() << " lbs" << endl;

    // Convert to kilograms
    cout << "Weight in kilograms: " << weight.getWeightKilograms() << " kg" << endl;

    // Convert to ounces
    cout << "Weight in ounces: " << weight.getWeightOunces() << " oz" << endl;

    // Set weight in kilograms
    weight.setWeightKilograms(5);
    cout << "Weight in pounds: " << weight.getWeightPounds() << " lbs" << endl;

    // Set weight in ounces
    weight.setWeightOunces(160);
    cout << "Weight in pounds: " << weight.getWeightPounds() << " lbs" << endl;

    return 0;
}

void Weight::setWeightPounds(double pounds) 
{
    this->pounds = pounds;
}

void Weight::setWeightKilograms(double kilograms)
{
    this->pounds = kilograms * 2.21; // Convert kilograms to pounds
}

void Weight::setWeightOunces(double ounces) 
{
    this->pounds = ounces / 16.0; // Convert ounces to pounds
}

double Weight::getWeightPounds() const 
{
    return pounds;
}

double Weight::getWeightKilograms() const 
{
    return pounds / 2.21; // Convert pounds to kilograms
}

double Weight::getWeightOunces() const 
{
    return pounds * 16.0; // Convert pounds to ounces
}
