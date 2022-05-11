main: Assignment.cpp Course.cpp Profile.cpp Admin.cpp Teacher.cpp Student.cpp main.cpp
	g++ Assignment.cpp Course.cpp Profile.cpp Admin.cpp Teacher.cpp Student.cpp main.cpp -o main.out

test:
	./main < test_input.txt