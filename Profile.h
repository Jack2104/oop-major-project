#ifndef PROFILE_H
#define PROFILE_H

#include <string>

using namespace std;

class Profile {
    protected:
        string name;
        string password;
        int schoolID;
    
    public:
        Profile();
        Profile(string name, string password, int schoolID);

        /* Returns the profile's name */
        string getName();
        
        /* Sets the profile's name */
        void setName(string name);

        /* Returns the profile's password */
        string getPassword();
        
        /* Sets the profile's password */
        void setPassword(string password);

        /* Returns the profile's ID */
        int getID();

        /* Sets the profile's ID. Negative inputs will be multiplied by -1 */
        void setID(int schoolID);

        /* Abstract methods */
        virtual void printTitle();
        virtual void constructEmail();
};

#endif
