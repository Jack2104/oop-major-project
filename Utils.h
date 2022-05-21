#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

using namespace std;

class Utils {
    public:
        /* Continually prompt the user for a string until a valid input is entered, and return it */
        static string getStringInput(string inputName, string inputConditions);

        /* Continually prompt the user for a string until a valid input is entered, and return it if it's an accepted input */
        static string getStringInput(string inputName, string inputConditions, vector<string> acceptedInputs);

        /* Continually prompt the user for an integer until a valid input is entered, and return it */
        static int getIntInput(string inputName, string inputConditions);

        /* Continually prompt the user for a bounded integer until a valid input is entered, and return it */
        static int getIntInput(string inputName, string inputConditions, int lowerBound, int upperBound);
};


#endif
