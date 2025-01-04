#ifndef DEPARTMENT_HPP
#define DEPARTMENT_HPP

#include <string>
#include <vector>
#include "Student.hpp"
#include "Course.hpp"

// Class to represent a department
class Department {
private:
    std::string departmentName;  // Name of the department
    std::vector<Student*> students;  // List of students in the department
    std::vector<Course*> courses;  // List of courses offered by the department

public:
    // Constructor that initializes the department's name
    Department(const std::string &name);

    // Method to add a student to the department
    Student* addStudent(const std::string &studentName);

    // Method to add a course to the department
    Course* addCourse(const std::string &courseName, int maxGrade, int credits, int capacity);

    // Method to enroll a student in a course
    void enrollStudentInCourse(const std::string &studentName, const std::string &courseName);

    // Method to print information about the department
    void printDepartmentInfo() const;

    // Destructor to clean up dynamically allocated memory
    ~Department();
};

#endif
