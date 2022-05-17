#include <iostream>
#include <string>

#include "Admin.h"

int main() {
    {
        Admin admin("Bob", "password1", 1234);

        if (admin.getName() != "Bob") {
            std::cout << "AdminTest.cpp: Test 1 failed" << std::endl;
        }
    }

    {
        Admin admin(" ", "password1", 1234);

        if (admin.getName() != " ") {
            std::cout << "AdminTest.cpp: Test 2 failed" << std::endl;
        }
    }

    {
        Admin admin("", "password1", 1234);

        if (admin.getName() != "") {
            std::cout << "AdminTest.cpp: Test 3 failed" << std::endl;
        }
    }

    {
        Admin admin("Bob", "password1", 1234);

        if (admin.getPassword() != "password1") {
            std::cout << "AdminTest.cpp: Test 4 failed" << std::endl;
        }
    }

    {
        Admin admin("Bob", " ", 1234);

        if (admin.getPassword() != " ") {
            std::cout << "AdminTest.cpp: Test 5 failed" << std::endl;
        }
    }

    {
        Admin admin("Bob", "", 1234);

        if (admin.getPassword() != "") {
            std::cout << "AdminTest.cpp: Test 6 failed" << std::endl;
        }
    }

    {
        Admin admin("Bob", "password1", 1234);

        if (admin.getID() != 1234) {
            std::cout << "AdminTest.cpp: Test 7 failed" << std::endl;
        }
    }

    {
        Admin admin("Bob", "password1", 1);

        if (admin.getID() != 1) {
            std::cout << "AdminTest.cpp: Test 8 failed" << std::endl;
        }
    }

    {
        Admin admin("Bob", "password1", 0);

        if (admin.getID() != 0) {
            std::cout << "AdminTest.cpp: Test 9 failed" << std::endl;
        }
    }

    {
        Admin admin("Bob", "password1", -1);

        if (admin.getID() != -1) {
            std::cout << "AdminTest.cpp: Test 10 failed" << std::endl;
        }
    }

    {
        Admin admin("Bob", "password1", -1234);

        if (admin.getID() != -1234) {
            std::cout << "AdminTest.cpp: Test 11 failed" << std::endl;
        }
    }

    return 0;
}
