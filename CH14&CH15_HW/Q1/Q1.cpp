#include <iostream>
#include "administrator.h"
#include "salariedemployee.h"

using namespace std;
using namespace SavitchEmployees;

int main() {
    // Create a SalariedEmployee object
    SalariedEmployee emp1("John Doe", "123-45-6789", 1000);
    emp1.printCheck();

    // Create an Administrator object
    Administrator admin("Jane Smith", "987-65-4321", 2000, "Manager", "Operations", "John Doe");
    admin.print();
    admin.printCheck();

    return 0;
}