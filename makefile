main: Assignment.cpp Course.cpp Profile.cpp Admin.cpp Teacher.cpp Student.cpp Utils.cpp main.cpp
	g++ Assignment.cpp Course.cpp Profile.cpp Admin.cpp Teacher.cpp Student.cpp Utils.cpp main.cpp -o main.out

# Profile tests
profile_unit_test: Profile.cpp ProfileUnitTest.cpp
	g++ Profile.cpp ProfileUnitTest.cpp -o ProfileUnitTest.out

# Admin tests
admin_unit_test: Assignment.cpp Course.cpp Profile.cpp Student.cpp Teacher.cpp Admin.cpp Utils.cpp AdminUnitTest.cpp
	g++ Assignment.cpp Course.cpp Profile.cpp Student.cpp Teacher.cpp Admin.cpp Utils.cpp AdminUnitTest.cpp -o AdminUnitTest.out

admin_input_test: Assignment.cpp Course.cpp Profile.cpp Student.cpp Teacher.cpp Admin.cpp Utils.cpp AdminInputTest.cpp
	g++ Assignment.cpp Course.cpp Profile.cpp Student.cpp Teacher.cpp Admin.cpp Utils.cpp AdminInputTest.cpp -o AdminInputTest.out
	./AdminInputTest.out < admin_test_input.txt

# Teacher tests
teacher_unit_test: Assignment.cpp Course.cpp Profile.cpp Teacher.cpp TeacherUnitTest.cpp
	g++ Assignment.cpp Course.cpp Profile.cpp Teacher.cpp TeacherUnitTest.cpp -o TeacherUnitTest.out

teacher_input_test: Assignment.cpp Course.cpp Profile.cpp Teacher.cpp Utils.cpp TeacherInputTest.cpp
	g++ Assignment.cpp Course.cpp Profile.cpp Teacher.cpp Utils.cpp TeacherInputTest.cpp -o TeacherInputTest.out
	./TeacherInputTest.out < teacher_test_input.txt

# Student tests
student_unit_test: Assignment.cpp Course.cpp Profile.cpp Student.cpp StudentUnitTest.cpp
	g++ Assignment.cpp Course.cpp Profile.cpp Student.cpp StudentUnitTest.cpp -o StudentUnitTest.out

student_input_test: Assignment.cpp Course.cpp Profile.cpp Student.cpp Utils.cpp StudentInputTest.cpp
	g++ Assignment.cpp Course.cpp Profile.cpp Student.cpp Utils.cpp StudentInputTest.cpp -o StudentInputTest.out
	./StudentInputTest.out < student_test_input.txt

# Course tests
course_unit_test: Assignment.cpp Course.cpp CourseUnitTest.cpp
	g++ Assignment.cpp Course.cpp CourseUnitTest.cpp -o CourseUnitTest.out

course_input_test: Assignment.cpp Course.cpp Utils.cpp CourseInputTest.cpp
	g++ Assignment.cpp Course.cpp Utils.cpp CourseInputTest.cpp -o CourseInputTest.out
	./CourseInputTest.out < course_test_input.txt

# Assignment tests
assignment_unit_test: Assignment.cpp AssignmentUnitTest.cpp
	g++ Assignment.cpp AssignmentUnitTest.cpp -o AssignmentUnitTest.out

assignment_input_test: Assignment.cpp AssignmentInputTest.cpp
	g++ Assignment.cpp AssignmentInputTest.cpp -o AssignmentInputTest.out

# Utils tests
utils_input_test: Utils.cpp UtilsInputTest.cpp
	g++ Utils.cpp UtilsInputTest.cpp -o UtilsInputTest.out
	./UtilsInputTest.out < utils_test_input.txt

# Unit test
unit_test: profile_unit_test admin_unit_test teacher_unit_test student_unit_test course_unit_test assignment_unit_test
	./ProfileUnitTest.out
	./AdminUnitTest.out
	./TeacherUnitTest.out
	./StudentUnitTest.out
	./CourseUnitTest.out
	./AssignmentUnitTest.out

# Input test
input_test: admin_input_test teacher_input_test student_input_test course_input_test assignment_input_test utils_input_test
	./AdminInputTest.out <  admin_test_input.txt
	./TeacherInputTest.out < teacher_test_input.txt
	./StudentInputTest.out < student_test_input.txt
	./CourseInputTest.out < course_test_input.txt
	./AssignmentInputTest.out
	./UtilsInputTest.out < utils_test_input.txt

# Full integration test
integration_test:
	./main.out < test_input.txt
	