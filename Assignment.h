#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <string>

using namespace std;

class Assignment {
    private:
        string name; // Assignment name
        int weight; // Assignment % weight for the course
        int grade; // Grade obtained for the assignment
        string description; // Description of the assignment
    
    public:
        Assignment();
        Assignment(string name, int weight, string description);

        /* Assigns a name to the assignment */
        void setName(string name);

        /* Assings a % weight of the assignment for the course */
        void setWeight(int weight);

        /* Assigns a grade for the assignment */
        void setGrade(int grade);

        /* Assings a description for the assignment */
        void setDescription(string description);

        /* Returns assignment name */
        string getName();

        /* Returns assignment weight */
        int getWeight();

        /* Returns assignment grade */
        int getGrade();

        /* Returns assignment description */
        string getDescription();

        /* Prints all assignment info to user */
        void printAssignmentInfo();
};

#endif
