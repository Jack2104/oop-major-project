#include <iostream>
#include <string>

#include "Student.h"

int main() {
    {
        Student student("Billy", "password1", 1234, 4);

        if (student.getName() != "Billy") {
            std::cout << "StudentTest.cpp: Test 1 failed" << std::endl;
        }
    }

    {
        Student student("Billy", "password1", 1234, 4);

        if (student.getPassword() != "password1") {
            std::cout << "StudentTest.cpp: Test 2 failed" << std::endl;
        }
    }

    {
        Student student("Billy", "password1", 1234, 4);

        if (student.getID() != 1234) {
            std::cout << "StudentTest.cpp: Test 3 failed" << std::endl;
        }
    }

    return 0;
}
