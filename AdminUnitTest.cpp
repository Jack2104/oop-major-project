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
        Admin admin("Bob", "password1", 1234);

        if (admin.getPassword() != "password1") {
            std::cout << "AdminTest.cpp: Test 2 failed" << std::endl;
        }
    }

    {
        Admin admin("Bob", "password1", 1234);

        if (admin.getID() != 1234) {
            std::cout << "AdminTest.cpp: Test 3 failed" << std::endl;
        }
    }

    return 0;
}
