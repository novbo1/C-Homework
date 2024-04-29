#include <iostream>
#include <cstdlib>
using namespace std;

// Class representing complex numbers.
class Complex {
public:
    // Constructors
    Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}
    Complex(double realPart) : real(realPart), imaginary(0) {}
    Complex() : real(0), imaginary(0) {}

    // Overloaded arithmetic operators for complex numbers
    friend const Complex operator +(const Complex&, const Complex&);
    friend const Complex operator -(const Complex&, const Complex&);
    friend const Complex operator *(const Complex&, const Complex&);

    // Overloaded comparison operator for complex numbers
    friend bool operator ==(const Complex&, const Complex&);

    // Overloaded stream operators for input/output of complex numbers
    friend ostream& operator <<(ostream&, const Complex&);
    friend istream& operator >>(istream&, Complex&);

    // Static function to count the number of complex numbers created
    static void numberCount() { currentNumber++; }

private:
    double real; // Real part of the complex number
    double imaginary; // Imaginary part of the complex number
    static int currentNumber; // Static variable to count the number of complex numbers
};

// Initialization of the static member variable
int Complex::currentNumber = 1;

// Definition of the imaginary unit
const Complex i(0, 1);

int main()
{
    Complex test1, test2, result;

    // Input two complex numbers from the user
    cin >> test1;
    cin >> test2;

    // Perform arithmetic operations on the complex numbers and display the results
    result = test1 + test2;
    cout << "Number1 + Number2 = " << result << endl;
    result = test1 - test2;
    cout << "Number1 - Number2 = " << result << endl;
    result = test1 * test2;
    cout << "Number1 * Number2 = " << result << endl;

    return 0;
}

// Overloaded arithmetic operators implementation
const Complex operator +(const Complex& number1, const Complex& number2)
{
    double realPart = number1.real + number2.real;
    double imaginaryPart = number1.imaginary + number2.imaginary;
    return Complex(realPart, imaginaryPart); // Create a new Complex object with the result
}

const Complex operator -(const Complex& number1, const Complex& number2)
{
    double realPart = number1.real - number2.real;
    double imaginaryPart = number1.imaginary - number2.imaginary;
    return Complex(realPart, imaginaryPart); // Create a new Complex object with the result
}

const Complex operator *(const Complex& number1, const Complex& number2)
{
    //From formula, we know (a+bi)*(c+di) = (ac-bd)+(ad+bc)*i

    //ac-bd
    double realPart = number1.real * number2.real - number1.imaginary * number2.imaginary;
    //ad+bc
    double imaginaryPart = number1.real * number2.imaginary + number1.imaginary * number2.real;
    return Complex(realPart, imaginaryPart); // Create a new Complex object with the result
}

// Overloaded comparison operator implementation
bool operator ==(const Complex& number1, const Complex& number2)
{
    // Check if real and imaginary parts of both complex numbers are equal
    return (number1.real == number2.real) && (number1.imaginary == number2.imaginary);
}

// Overloaded stream insertion operator implementation
ostream& operator <<(ostream& outputStream, const Complex& number)
{
    outputStream << number.real;
    if (number.imaginary >= 0)
        outputStream << " + " << number.imaginary << "i";
    else
        outputStream << " - " << -number.imaginary << "i";

    return outputStream;
}

// Overloaded stream extraction operator implementation
istream& operator >>(istream& inputStream, Complex& number)
{
    cout << "Enter real part of the Number" << Complex::currentNumber << ": " << endl;
    inputStream >> number.real;
    cout << "Enter imaginary part of the Number" << Complex::currentNumber << ": " << endl;
    inputStream >> number.imaginary;

    // Increment the number of complex numbers created
    Complex::numberCount();

    return inputStream;
}