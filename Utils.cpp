#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Utils.h"

using namespace std;

string Utils::getStringInput(string inputName, string inputConditions) {
    string input;
    cout << inputName << "(" << inputConditions << "): ";

    // Continually prompt the user for input until a valid input is entered
    while (!getline(cin, input) || input.empty() || input.find_first_not_of(' ') == string::npos || input.find_first_not_of('	') == string::npos) {
        cout << "Sorry, that's not a valid input." << endl;
        cout << inputName << "(" << inputConditions << "): ";
    }

    cout << "  " << inputName << " was recorded as " << input << endl;

    return input;
}

string Utils::getStringInput(string inputName, string inputConditions, vector<string> acceptedInputs) {
    string input;
    bool inputValid = false;
    
    cout << inputName << "(" << inputConditions << "): ";

    while (!inputValid) {
        // Continually prompt the user for input until a valid input is entered
        while (!getline(cin, input) || input.empty() || input.find_first_not_of(' ') == string::npos || input.find_first_not_of('	') == string::npos) {
            cout << "Sorry, that's not a valid input." << endl;
            cout << inputName << "(" << inputConditions << "): ";
        }

        vector<string>::iterator ptr;

        for (ptr = acceptedInputs.begin(); ptr < acceptedInputs.end(); ptr++) {
            if (*ptr == input) {
                inputValid = true;
                break;
            }
        }
    }

    cout << "  " << inputName << " was recorded as " << input << endl;

    return input;
}

int Utils::getIntInput(string inputName, string inputConditions) {
    int input;
    cout << inputName << "(" << inputConditions << "): ";
    cin >> input;

    // Continually prompt the user for input until an integer is passed
    while(!input) {
        cin.clear(); // Clear the buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore all the inputted characters

        cout << "  Sorry, that's not a valid input." << endl << "Maximum course count: ";
        cin >> input;
    }

    cout << "  " << inputName << " count was recorded as " << input << endl;
    
    return input;
}

int Utils::getIntInput(string inputName, string inputConditions, int lowerBound, int upperBound) {
    int input;
    cout << inputName << "(" << inputConditions << "): ";
    cin >> input;

    // Continually prompt the user for input until an integer is passed
    while(!input || input < lowerBound || input > upperBound) {
        cin.clear(); // Clear the buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore all the inputted characters

        cout << "  Sorry, that's not a valid input." << endl << "Maximum course count: ";
        cin >> input;
    }

    cout << "  " << inputName << " count was recorded as " << input << endl;

    return input;
}
