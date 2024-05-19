#include <iostream>
#include <string>
using namespace std;

class Subscriber {
public:
    // Constructors
    Subscriber(string name, int numChannels); // Constructor for getting values
    Subscriber();                             // Default constructor
    Subscriber(const Subscriber& other);      // Copy constructor
    ~Subscriber();                            // Destructor

    // Member functions
    void inputValues();
    void output() const;
    void resetChannels();

    // Overloaded assignment operator
    Subscriber& operator=(const Subscriber& other);

private:
    string name;
    int numChannels;
    string* channelList; // Dynamic array of strings
};

int main() 
{
    // Creating a subscriber and inputting values
    Subscriber sub;
    sub.inputValues();

    // Outputting the subscriber's details
    cout << "\nSubscriber details:" << endl;
    sub.output();

    // Resetting the channels
    sub.resetChannels();
    cout << "\nAfter resetting channels:" << endl;
    sub.output();

    // Testing the copy constructor and assignment operator
    Subscriber subCopy = sub; // Copy constructor
    sub = subCopy; // Assignment operator

    return 0;
}

// Constructor for getting values
Subscriber::Subscriber(string name, int numChannels) : name(name), numChannels(numChannels) 
{
    channelList = new string[numChannels];
}

// Default constructor
Subscriber::Subscriber() : name("None"), numChannels(0), channelList(nullptr) {}

// Copy constructor
Subscriber::Subscriber(const Subscriber& other) : name(other.name), numChannels(other.numChannels) 
{
    channelList = new string[numChannels];
    for (int i = 0; i < numChannels; ++i) 
    {
        channelList[i] = other.channelList[i];
    }
}

// Destructor
Subscriber::~Subscriber() 
{
    delete[] channelList;
    channelList = nullptr;
}

// Overloaded assignment operator
Subscriber& Subscriber::operator=(const Subscriber& other) 
{
    if (this != &other) 
    {
        delete[] channelList;

        name = other.name;
        numChannels = other.numChannels;
        channelList = new string[numChannels];

        for (int i = 0; i < numChannels; ++i) 
        {
            channelList[i] = other.channelList[i];
        }
    }
    return *this;
}

// Function to input all values from the user
void Subscriber::inputValues() 
{
    cout << "Enter subscriber name: ";
    getline(cin, name);

    cout << "Enter number of channels: ";
    cin >> numChannels;
    cin.ignore(); // Ignore the newline character left in the buffer

    delete[] channelList;
    channelList = new string[numChannels];

    cout << "Enter the names of the channels: " << endl;
    for (int i = 0; i < numChannels; ++i) 
    {
        cout << "Channel " << i + 1 << ": ";
        getline(cin, channelList[i]);
    }
}

// Function to output the name and list of all channels
void Subscriber::output() const 
{
    cout << "Subscriber Name: " << name << endl;
    cout << "Number of Channels: " << numChannels << endl;
    for (int i = 0; i < numChannels; ++i) 
    {
        cout << "Channel " << i + 1 << ": " << channelList[i] << endl;
    }
}

// Function to reset the number of channels and the channel list
void Subscriber::resetChannels() 
{
    numChannels = 0;
    delete[] channelList;
    channelList = nullptr;
}

