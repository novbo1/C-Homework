#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    // Declare variables
    vector<int> grades;
    map<int, int> histogram;

    // Input grades into vector
    cout << "Enter student grades (enter -1 to finish):\n";
    int grade;
    while (true) {
        cin >> grade;
        if (grade == -1)
            break;
        grades.push_back(grade);
    }

    // Calculate histogram bins and update map
    for (int grade : grades) {
        // Calculate bin for the grade
        int bin = ((grade - 1) / 10 + 1) * 10; // Calculate bin value 
        histogram[bin]++;
    }

    // Output the histogram
    cout << "The histogram for the grades entered is:\n";
    for (const auto& entry : histogram) {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}