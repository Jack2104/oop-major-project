main: Assignment.cpp Course.cpp Profile.cpp Admin.cpp Teacher.cpp Student.cpp main.cpp
	g++ Assignment.cpp Course.cpp Profile.cpp Admin.cpp Teacher.cpp Student.cpp main.cpp -o main.out

profiletest: Profile.cpp ProfileTest.cpp
	g++ Profile.cpp ProfileTest.cpp -o ProfileTest.out

coursetest: Assignment.cpp Course.cpp CourseTest.cpp
	g++ Assignment.cpp Coruse.cpp CourseTest.cpp -o CourseTest.out

test:
	./main < test_input.txt