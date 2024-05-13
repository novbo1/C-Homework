#include <iostream>
#include <string>
#include <cctype>
using namespace std;
//Function to replace 4 letter words with love
string changeLetter(string);

int main()
{
    string currentSentence;
    bool result = true;
    string choice;

    //Loop until false condition
    while (result)
    {
        cout << "Enter a sentence: ";
        getline(cin, currentSentence); // Read the entire line including spaces

        currentSentence = changeLetter(currentSentence); //Save the new sentence
        cout << "Sentence after replaced with love > " << endl;
        cout << currentSentence;

        //Decide whether to quit the loop
        cout << endl << "Do you want to enter another sentence? (type quit to stop the program)" << endl;
        getline(cin, choice);
        if (choice == "quit")
        {
            //Break from loop
            result = false;
        }
    }
    return 0;
}

string changeLetter(string sentence)
{
    string result; //Final result
    string word; //Temp word to add in result

    for (char c : sentence)
    {
        //Check if it is a letter
        if (isalpha(c))
        {
            //Add word
            word += c;
        }
        else
        {
            //If a word is 4 letter long
            if (word.size() == 4)
            {
                if (isupper(word[0])) // Check if first letter is uppercase
                {
                    result += "Love";
                }
                else
                {
                    result += "love";
                }
            }
            else
            {
                //Doesn't have 4 letter, add all the elements in word to result
                result += word;
            }
            result += c;
            word.clear();
        }
    }

    // Check the last word
    if (word.size() == 4)
    {
        result += "love";
    }
    else
    {
        result += word;
    }

    return result;
}