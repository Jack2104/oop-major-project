#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <string>

class Assignment {
    private:
        string name; // Assignment name
        int weight; // Assignment % weight for the course
        int grade; // Grade obtained for the assignment
        string description; // Description of the assignment
    
    public:
        Assignment();
        Assignment(string name, float weight, float grade, string description);
        ~Assignment();

        /* Assigns a name to the assignment */
        void setName(string name);

        /* Assings a % weight of the assignment for the course */
        void setWeight(float weight);

        /* Assigns a grade for the assignment */
        void setGrade(float grade);

        /* Assings a description for the assignment */
        void setDescription(string description);

        /* Returns assignment name */
        string getName();

        /* Returns assignment weight */
        float getWeight();

        /* Returns assignment grade */
        float getGrade();

        /* Returns assignment description */
        string getDescription();

        /* Prints all assignment info to user */
        void printAssignmentInfo();
};

#endif
