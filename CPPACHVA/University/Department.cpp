#include <iostream>
#include <algorithm>
#include "Department.hpp"

// Constructor that initializes the department's name
Department::Department(const std::string &name) : departmentName(name) {}

// Method to add a student to the department
Student* Department::addStudent(const std::string &studentName) {
    auto student = new Student(studentName);
    students.push_back(student);
    return student;
}

// Method to add a course to the department
Course* Department::addCourse(const std::string &courseName, int maxGrade, int credits, int capacity) {
    auto course = new Course(courseName, maxGrade, credits, capacity);
    courses.push_back(course);
    return course;
}

// Method to enroll a student in a course
void Department::enrollStudentInCourse(const std::string &studentName, const std::string &courseName) {
    auto studentIt = std::find_if(students.begin(), students.end(),
                                  [&studentName](Student* s) { return s->getName() == studentName; });
    auto courseIt = std::find_if(courses.begin(), courses.end(),
                                 [&courseName](Course* c) { return c->getCourseName() == courseName; });

    if (studentIt != students.end() && courseIt != courses.end()) {
        if (!(*courseIt)->enrollStudent(*studentIt)) {
            std::cout << "Could not enroll student " << studentName << " in course " << courseName << std::endl;
        }
    } else {
        std::cout << "Student or course not found." << std::endl;
    }
}

// Method to print information about the department
void Department::printDepartmentInfo() const {
    std::cout << "Department: " << departmentName << std::endl;
    std::cout << "Students: " << std::endl;
    for (const auto &student : students) {
        std::cout << " - " << student->getName() << std::endl;
    }
    std::cout << "Courses: " << std::endl;
    for (const auto &course : courses) {
        std::cout << " - " << course->getCourseName() << " (" << course->getCredits() << " credits)" << std::endl;
        course->printEnrolledStudents();
    }
}

// Destructor to clean up dynamically allocated memory
Department::~Department() {
    for (auto student : students) {
        delete student;
    }
    for (auto course : courses) {
        delete course;
    }
}
