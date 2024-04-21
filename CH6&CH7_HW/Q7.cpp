#include <iostream>
#include <string>
#include <cstdlib> //for exit
using namespace std;
class PostalCode {
public:
    PostalCode(int zip);
    PostalCode(string bar);

    int getZipCode();
    string getBarCode();
private:
    int zipCode;
    string barCode;

    bool checkBarCode();
    bool checkTwoOnes();

    int calculateZipCode();
    string getFiveDigitValues();
};
PostalCode::PostalCode(int zip) : zipCode(zip) {}
PostalCode::PostalCode(string bar) : barCode(bar) {}

int PostalCode::getZipCode() {
    if (checkBarCode()) {
        //if bar code is in right format
        if (checkTwoOnes()) {
            //if two ones in every five digits
            zipCode = calculateZipCode();
        }
        else {
            cout << "Error validating two ones in every five digits!";
            exit(1);
        }
    }
    else {
        cout << "Bar-Code Validation Error!";
        exit(1);
    }
    return zipCode;
}

string PostalCode::getBarCode() {
    barCode = getFiveDigitValues();
    barCode = "1" + barCode + "1";
    return barCode;
}
bool PostalCode::checkBarCode() {
    bool result;
    if ((barCode.length() == 27) && ((static_cast<int>(barCode[0]) - 48) == 1)
        && ((static_cast<int>(barCode[26]) - 48) == 1)) {
        result = true;
    }
    else { result = false; }
    return result;
}
bool PostalCode::checkTwoOnes() {
    bool fiveCases[5];
    //stores true if each five digit group contains
    //two ones
    int arrCount = 0;
    int numberOnes;
    //number of number ones
    bool result = true;
    for (int i = 1; i <= 25; i = i + 5) {
        numberOnes = 0;
        //resetting the value of numberOnes for next loop
        for (int j = i; j <= i + 4; j++) {
            if ((static_cast<int>(barCode[j]) - 48) == 1) {
                numberOnes++;
            }
        }
        if (numberOnes == 2) {
            fiveCases[arrCount] = true;
        }
        else { fiveCases[arrCount] = false; }
        arrCount++;
    }
    for (int i = 0; i < 5; i++) {
        if (fiveCases[i] == false) {
            result = false;
            break;
        }
    }
    return result;
}
int PostalCode::calculateZipCode() {
    int result = 0;
    int sumArr[5];
    //stores sum of five five digit group of numbers
    int arrCounter = 0;
    int sum;
    int tempCounter;
    //to count first, second third, fourth, fifth value
    for (int i = 1; i <= 25; i = i + 5) {
        sum = 0;
        //reseting the value of sum after each five digits
        tempCounter = 1;
        //reseting the value of tempCounter
        for (int j = i; j <= i + 4; j++) {
            if (tempCounter == 1) {
                sum += (static_cast<int>(barCode[j]) - 48) * 7;
                tempCounter++;
            }
            else if (tempCounter == 2) {
                sum += (static_cast<int>(barCode[j]) - 48) * 4;
                tempCounter++;
            }
            else if (tempCounter == 3) {
                sum += (static_cast<int>(barCode[j]) - 48) * 2;
                tempCounter++;
            }
            else if (tempCounter == 4) {
                sum += (static_cast<int>(barCode[j]) - 48) * 1;
                tempCounter++;
            }
            else if (tempCounter == 5) {
                sum += (static_cast<int>(barCode[j]) - 48) * 0;
                tempCounter++;
            }

        }
        if (sum == 11) {
            sum = 0;
        }
        sumArr[arrCounter] = sum;
        //storing the sum in array
        arrCounter++;
    }
    int multiplier = 10000;
    //now, converting the values in arr into an integer number
    for (int i = 0; i < 5; i++) {
        result += sumArr[i] * multiplier;
        multiplier = multiplier / 10;
    }
    return result;
}
string PostalCode::getFiveDigitValues() {
    string result = "";
    int divisor = 10000;
    int number = zipCode;
    int currentDigit;
    for (int i = 0; i < 5; i++) {
        currentDigit = number / divisor;
        switch (currentDigit) {
        case 0:
            result += "11000";
            break;
        case 1:
            result += "00011";
            break;
        case 2:
            result += "00101";
            break;
        case 3:
            result += "00110";
            break;
        case 4:
            result += "01001";
            break;
        case 5:
            result += "01010";
            break;
        case 6:
            result += "01100";
            break;
        case 7:
            result += "10001";
            break;
        case 8:
            result += "10010";
            break;
        case 9:
            result += "10100";
            break;
        default:
            result += "00000";
            cout << "Error!" << endl;
        }
        number = number % divisor;
        divisor = divisor / 10;
    }
    return result;
}
int main() {
    PostalCode pc("110100101000101011000010011");
    cout << "The ZIP code is: " << pc.getZipCode();
    cout << endl;
    PostalCode pstl(99504);
    cout << "The Bar Code is: " << pc.getBarCode();
    cout << endl;
    return 0;
}