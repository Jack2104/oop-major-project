#include <iostream>
#include <string>

#include "Profile.h"

int main() {
    {
        Profile profile("Bob", "password1", 1234);

        if (profile.getName() != "Bob") {
            std::cout << "ProfileUnitTest.cpp: Test 1 failed" << std::endl;
        }
    }

    {
        Profile profile("Bob Smith", "password1", 1234);

        if (profile.getName() != "Bob Smith") {
            std::cout << "ProfileUnitTest.cpp: Test 2 failed" << std::endl;
        }
    }
    
    {
        Profile profile("", "password1", 1234);

        if (profile.getName() != "") {
            std::cout << "ProfileUnitTest.cpp: Test 3 failed" << std::endl;
        }
    }

    {
        Profile profile("Bob", "password1", 1234);

        if (profile.getPassword() != "password1") {
            std::cout << "ProfileUnitTest.cpp: Test 4 failed" << std::endl;
        }
    }

    {
        Profile profile("Bob", "password 1", 1234);

        if (profile.getPassword() != "password 1") {
            std::cout << "ProfileUnitTest.cpp: Test 5 failed" << std::endl;
        }
    }

    {
        Profile profile("Bob", "password1!@#$", 1234);

        if (profile.getPassword() != "password1!@#$") {
            std::cout << "ProfileUnitTest.cpp: Test 6 failed" << std::endl;
        }
    }

    {
        Profile profile("Bob", "", 1234);

        if (profile.getPassword() != "") {
            std::cout << "ProfileUnitTest.cpp: Test 7 failed" << std::endl;
        }
    }

    {
        Profile profile("Bob", "password1", 1234);

        if (profile.getID() != 1234) {
            std::cout << "ProfileUnitTest.cpp: Test 8 failed" << std::endl;
        }
    }

    {
        Profile profile("Bob", "password1", 100000);

        if (profile.getID() != 100000) {
            std::cout << "ProfileUnitTest.cpp: Test 9 failed" << std::endl;
        }
    }

    {
        Profile profile("Bob", "password1", -100000);

        if (profile.getID() != 100000) {
            std::cout << "ProfileUnitTest.cpp: Test 10 failed" << std::endl;
        }
    }

    {
        Profile profile("Bob", "password1", 1);

        if (profile.getID() != 1) {
            std::cout << "ProfileUnitTest.cpp: Test 11 failed" << std::endl;
        }
    }

    {
        Profile profile("Bob", "password1", -1);

        if (profile.getID() != 1) {
            std::cout << "ProfileUnitTest.cpp: Test 12 failed" << std::endl;
        }
    }

    {
        Profile profile("Bob", "password1", 0);

        if (profile.getID() != 0) {
            std::cout << "ProfileUnitTest.cpp: Test 13 failed" << std::endl;
        }
    }

    return 0;
}
