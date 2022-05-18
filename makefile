main: Assignment.cpp Course.cpp Profile.cpp Admin.cpp Teacher.cpp Student.cpp main.cpp
	g++ Assignment.cpp Course.cpp Profile.cpp Admin.cpp Teacher.cpp Student.cpp main.cpp -o main.out

profile_unit_test: Profile.cpp ProfileTest.cpp
	g++ Profile.cpp ProfileTest.cpp -o ProfileTest.out

admin_unit_test: Assignment.cpp Course.cpp Profile.cpp Student.cpp Teacher.cpp Admin.cpp AdminUnitTest.cpp
	g++ Assignment.cpp Course.cpp Profile.cpp Student.cpp Teacher.cpp Admin.cpp AdminUnitTest.cpp -o AdminUnitTest.out

teacher_unit_test: Assignment.cpp Course.cpp Profile.cpp Teacher.cpp TeacherUnitTest.cpp
	g++ Assignment.cpp Course.cpp Profile.cpp Teacher.cpp TeacherUnitTest.cpp -o TeacherUnitTest.out

student_unit_test: Assignment.cpp Course.cpp Profile.cpp Student.cpp StudentUnitTest.cpp
	g++ Assignment.cpp Course.cpp Profile.cpp Student.cpp StudentUnitTest.cpp -o StudentUnitTest.out

course_unit_test: Assignment.cpp Course.cpp CourseUnitTest.cpp
	g++ Assignment.cpp Course.cpp CourseUnitTest.cpp -o CourseUnitTest.out

course_input_test: Assignment.cpp Course.cpp CourseInputTest.cpp
	g++ Assignment.cpp Course.cpp CourseUnitTest.cpp -o CourseInputTest.out
	./CourseUnitTest < course_test_input.txt

assignment_unit_test: Assignment.cpp AssignmentUnitTest.cpp
	g++ Assignment.cpp AssignmentUnitTest.cpp -o AssignmentUnitTest.out

assignment_input_test: Assignment.cpp AssignmentInputTest.cpp
	g++ Assignment.cpp AssignmentInputTest.cpp -o AssignmentInputTest.out

integration_test:
	./main < test_input.txt