main: Assignment.cpp Course.cpp Profile.cpp Admin.cpp Teacher.cpp Student.cpp main.cpp
	g++ Assignment.cpp Course.cpp Profile.cpp Admin.cpp Teacher.cpp Student.cpp main.cpp -o main.out

profile_test: Profile.cpp ProfileTest.cpp
	g++ Profile.cpp ProfileTest.cpp -o ProfileTest.out

admin_test: Assignment.cpp Course.cpp Profile.cpp Student.cpp Teacher.cpp Admin.cpp AdminTest.cpp
	g++ Assignment.cpp Course.cpp Profile.cpp Student.cpp Teacher.cpp Admin.cpp AdminTest.cpp -o AdminTest.out

teacher_test: Assignment.cpp Course.cpp Profile.cpp Teacher.cpp TeacherTest.cpp
	g++ Assignment.cpp Course.cpp Profile.cpp Teacher.cpp TeacherTest.cpp -o TeacherTest.out

student_test: Assignment.cpp Course.cpp Profile.cpp Student.cpp StudentTest.cpp
	g++ Assignment.cpp Course.cpp Profile.cpp Student.cpp StudentTest.cpp -o StudentTest.out

course_test: Assignment.cpp Course.cpp CourseTest.cpp
	g++ Assignment.cpp Course.cpp CourseTest.cpp -o CourseTest.out

assignment_test: Assignment.cpp AssignmentTest.cpp
	g++ Assignment.cpp AssignmentTest.cpp -o AssignmentTest.out

integration_test:
	./main < test_input.txt