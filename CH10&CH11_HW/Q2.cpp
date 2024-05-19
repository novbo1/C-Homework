#include <iostream>
#include <string>
using namespace std;

class Television
{
public:
    // Constructors
    Television(string, double, string*); // Constructor to set values
    Television();                        // Default constructor
    Television(const Television& other); // Copy constructor

    ~Television();  // Destructor

    // Accessor methods
    string getDisplayType() const;
    double getDimension() const;
    string* getConnectivitySupport() const;

    // Mutator methods
    void setDisplayType(string );
    void setDimension(double );
    void setConnectivitySupport(string* );

    void getStats() const; // Get basic info
    void setStats(); // Set basic info

private:
    string displayType;
    double dimension;
    string* connectivitySupport;
};

int main()
{
    int numTVs;
    cout << "Enter the number of televisions: ";
    cin >> numTVs;

    Television* TVs = new Television[numTVs];

    for (int i = 0; i < numTVs; ++i) {
        cout << "TV #" << i + 1 << ":" << endl;
        TVs[i].setStats();

        char customize;
        cout << "Do you want to customize this TV? (y/n): ";
        cin >> customize;
        if (customize == 'y' || customize == 'Y') {
            cout << "Customizing TV #" << i + 1 << ":" << endl;
            // You can prompt for customization here, for example:
            string display;
            double dim;
            string connectivity[3];

            cout << "Enter Display Type: ";
            cin >> display;
            cout << "Enter Dimension (in inches): ";
            cin >> dim;
            cout << "Enter Connectivity Support (3 modes): ";
            for (int j = 0; j < 3; ++j) {
                cin >> connectivity[j];
            }

            // Set the values using mutator methods
            TVs[i].setDisplayType(display);
            TVs[i].setDimension(dim);
            TVs[i].setConnectivitySupport(connectivity);
        }
    }

    for (int i = 0; i < numTVs; ++i) {
        cout << "Details of TV #" << i + 1 << ":" << endl;
        TVs[i].getStats();
    }

    delete[] TVs;
    TVs = nullptr;

    return 0;
}


// Constructor implementation
Television::Television(string display, double dim, string* connectivity)
{
    displayType = display;
    dimension = dim;
    connectivitySupport = connectivity;
}

// Default constructor
Television::Television()
{
    displayType = "";
    dimension = 0.0;
    connectivitySupport = nullptr;
}

// Copy constructor
Television::Television(const Television& other)
{
    displayType = other.displayType;
    dimension = other.dimension;
    if (other.connectivitySupport != nullptr) {
        connectivitySupport = new string[3];
        for (int i = 0; i < 3; ++i) {
            connectivitySupport[i] = other.connectivitySupport[i];
        }
    }
    else {
        connectivitySupport = nullptr;
    }
}

// Destructor
Television::~Television()
{
    delete[] connectivitySupport;
    connectivitySupport = nullptr;
}

// Accessor methods
string Television::getDisplayType() const
{
    return displayType;
}

double Television::getDimension() const
{
    return dimension;
}

string* Television::getConnectivitySupport() const
{
    return connectivitySupport;
}

// Mutator methods
void Television::setDisplayType(string display)
{
    displayType = display;
}

void Television::setDimension(double dim)
{
    dimension = dim;
}

void Television::setConnectivitySupport(string* connectivity)
{
    connectivitySupport = connectivity;
}

// Display basic info
void Television::getStats() const
{
    cout << "Display Type: " << displayType << endl;
    cout << "Dimension: " << dimension << " inches" << endl;
    cout << "Connectivity Support: ";
    for (int i = 0; i < 3; ++i) {
        cout << connectivitySupport[i] << " ";
    }
    cout << endl;
}

void Television::setStats()
{
    cout << "Enter Display Type: ";
    cin >> displayType;
    cout << "Enter Dimension (in inches): ";
    cin >> dimension;
    cout << "Enter Connectivity Support (3 modes): ";
    connectivitySupport = new string[3]; // Allocate memory for the dynamic array
    for (int i = 0; i < 3; ++i)
    {
        cin >> connectivitySupport[i];
    }
}