#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <vector>
#include <map>

// Forward declaration of the Course class
class Course;

// Class to represent a student
class Student {
private:
    std::string name;  // Name of the student
    std::map<const Course*, int> grades;  // Maps Course objects to grades using raw pointers
    std::vector<Course*> enrolledCourses;  // List of courses the student is enrolled in

public:
    // Constructor that initializes the student's name
    Student(const std::string &n);

    // Method to add a grade for a specific course
    void addGrade(const Course* course, int grade);

    // Method to enroll the student in a course
    void enrollInCourse(Course* course);

    // Method to drop a course
    void dropCourse(Course* course);

    // Method to calculate the student's average grade
    double calculateAverage() const;

    // Method to print all the grades of the student
    void printGrades() const;

    // Method to print all the courses the student is enrolled in
    void printEnrolledCourses() const;

    // Getter method for the student's name
    std::string getName() const;
};

#endif
