#include "Student.hpp"
#include "Course.hpp"
#include <iostream>
#include <algorithm>

// Constructor that initializes the student's name
Student::Student(const std::string &n) : name(n) {}

// Method to add a grade for a specific course
void Student::addGrade(const Course* course, int grade) {
    grades[course] = grade;
}

// Method to enroll the student in a course
void Student::enrollInCourse(Course* course) {
    if (std::find(enrolledCourses.begin(), enrolledCourses.end(), course) == enrolledCourses.end()) {
        enrolledCourses.push_back(course);
    } else {
        std::cout << "Already enrolled in " << course->getCourseName() << std::endl;
    }
}

// Method to drop a course
void Student::dropCourse(Course* course) {
    enrolledCourses.erase(
        std::remove(enrolledCourses.begin(), enrolledCourses.end(), course),
        enrolledCourses.end());
}

// Method to calculate the student's average grade
double Student::calculateAverage() const {
    int total = 0;
    for (const auto &grade : grades) {
        total += grade.second;
    }
    return grades.empty() ? 0 : static_cast<double>(total) / grades.size();
}

// Method to print all the grades of the student
void Student::printGrades() const {
    std::cout << "Grades for " << name << ":" << std::endl;
    for (const auto &grade : grades) {
        std::cout << " - " << grade.first->getCourseName() << ": " << grade.second << std::endl;
    }
}

// Method to print all the courses the student is enrolled in
void Student::printEnrolledCourses() const {
    std::cout << name << " is enrolled in the following courses:" << std::endl;
    for (const auto &course : enrolledCourses) {
        std::cout << " - " << course->getCourseName() << std::endl;
    }
}

// Getter method for the student's name
std::string Student::getName() const {
    return name;
}
