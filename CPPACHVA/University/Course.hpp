#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
#include <vector>

// Forward declaration of the Student class
class Student;

// Class to represent a course
class Course {
private:
    std::string courseName;  // Name of the course
    int maxGrade;  // Maximum grade possible in the course
    int credits;  // Number of credits the course is worth
    int capacity;  // Maximum number of students allowed in the course
    std::vector<Student*> enrolledStudents;  // List of students enrolled in the course

public:
    // Constructor that initializes the course's name, max grade, credits, and capacity
    Course(const std::string &name, int max, int cred, int cap);

    // Method to enroll a student in the course
    bool enrollStudent(Student* student);

    // Method to drop a student from the course
    void dropStudent(Student* student);

    // Method to assign a grade to a student for this course
    void assignGrade(Student* student, int grade) const;

    // Method to print all students enrolled in this course
    void printEnrolledStudents() const;

    // Getter methods for course name and credits
    std::string getCourseName() const;
    int getCredits() const;
};

#endif
