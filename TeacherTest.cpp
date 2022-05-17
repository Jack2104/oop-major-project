#include <iostream>
#include <string>

#include "Teacher.h"

int main() {
    {
        Teacher teacher("Mr Goh", "password1", 1234, 4);

        if (teacher.getName() != "Mr Goh") {
            std::cout << "TeacherTest.cpp: Test 1 failed" << std::endl;
        }
    }

    {
        Teacher teacher("Mr Goh", "password1", 1234, 4);

        if (teacher.getPassword() != "password1") {
            std::cout << "TeacherTest.cpp: Test 2 failed" << std::endl;
        }
    }

    {
        Teacher teacher("Mr Goh", "password1", 1234, 4);

        if (teacher.getID() != 1234) {
            std::cout << "TeacherTest.cpp: Test 3 failed" << std::endl;
        }
    }

    return 0;
}
