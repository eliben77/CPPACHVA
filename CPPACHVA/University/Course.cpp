#include "Course.hpp"
#include "Student.hpp"
#include <iostream>
#include <algorithm>

// Constructor that initializes the course's name, max grade, credits, and capacity
Course::Course(const std::string &name, int max, int cred, int cap)
    : courseName(name), maxGrade(max), credits(cred), capacity(cap) {}

// Method to enroll a student in the course
bool Course::enrollStudent(Student* student) {
    if (enrolledStudents.size() < static_cast<size_t>(capacity)) {
        enrolledStudents.push_back(student);
        student->enrollInCourse(this);  // Enroll the student in this course
        return true;
    } else {
        std::cout << "Course " << courseName << " is full." << std::endl;
        return false;
    }
}

// Method to drop a student from the course
void Course::dropStudent(Student* student) {
    auto it = std::remove(enrolledStudents.begin(), enrolledStudents.end(), student);
    enrolledStudents.erase(it, enrolledStudents.end());  // Erase the removed elements from the vector
    student->dropCourse(this);  // Drop this course from the student's list
}

// Method to assign a grade to a student for this course
void Course::assignGrade(Student* student, int grade) const {
    if (grade <= maxGrade) {
        student->addGrade(this, grade);  // Add the grade to the student's record
    } else {
        std::cout << "Grade exceeds maximum for course " << courseName << std::endl;
    }
}

// Method to print all students enrolled in this course
void Course::printEnrolledStudents() const {
    std::cout << "Students enrolled in " << courseName << ":" << std::endl;
    for (const auto &student : enrolledStudents) {
        if (student) {
            std::cout << " - " << student->getName() << std::endl;
        }
    }
}

// Getter methods for course name and credits
std::string Course::getCourseName() const {
    return courseName;
}

int Course::getCredits() const {
    return credits;
}
