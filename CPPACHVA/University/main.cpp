#include "University.hpp"
#include "Department.hpp"
#include "Student.hpp"
#include "Course.hpp"
#include <iostream>

int main() {
    // Create a university
    University university("Tech University");

    // Create departments in the university
    Department* csDepartment = university.addDepartment("Computer Science");
    Department* mathDepartment = university.addDepartment("Mathematics");

    // Create courses in the Computer Science department
    Course* cppCourse = csDepartment->addCourse("C++ Programming", 100, 3, 30);
    Course* algoCourse = csDepartment->addCourse("Algorithms", 100, 4, 25);

    // Create courses in the Mathematics department
    Course* calculusCourse = mathDepartment->addCourse("Calculus", 100, 4, 40);
    Course* algebraCourse = mathDepartment->addCourse("Linear Algebra", 100, 3, 35);

    // Add students to the Computer Science department
    Student* alice = csDepartment->addStudent("Alice");
    Student* bob = csDepartment->addStudent("Bob");

    // Add students to the Mathematics department
    Student* charlie = mathDepartment->addStudent("Charlie");
    Student* diana = mathDepartment->addStudent("Diana");

    // Enroll students in courses
    csDepartment->enrollStudentInCourse("Alice", "C++ Programming");
    csDepartment->enrollStudentInCourse("Alice", "Algorithms");
    csDepartment->enrollStudentInCourse("Bob", "C++ Programming");

    mathDepartment->enrollStudentInCourse("Charlie", "Calculus");
    mathDepartment->enrollStudentInCourse("Diana", "Calculus");
    mathDepartment->enrollStudentInCourse("Diana", "Linear Algebra");

    // Assign grades to students in Computer Science courses
    cppCourse->assignGrade(alice, 95);
    algoCourse->assignGrade(alice, 89);
    cppCourse->assignGrade(bob, 76);

    // Assign grades to students in Mathematics courses
    calculusCourse->assignGrade(charlie, 88);
    calculusCourse->assignGrade(diana, 92);
    algebraCourse->assignGrade(diana, 85);

    // Print details of the university
    std::cout << "University Information:" << std::endl;
    university.printUniversityInfo();

    // Print specific details about a department
    std::cout << "\nComputer Science Department Information:" << std::endl;
    csDepartment->printDepartmentInfo();

    // Print specific details about a course
    std::cout << "\nC++ Programming Course Information:" << std::endl;
    cppCourse->printEnrolledStudents();

    // Print specific details about a student
    std::cout << "\nAlice's Grades:" << std::endl;
    alice->printGrades();
    std::cout << "Alice's Average Grade: " << alice->calculateAverage() << std::endl;

    return 0;
}
