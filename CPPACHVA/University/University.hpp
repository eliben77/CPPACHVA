#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include <string>
#include <vector>
#include "Department.hpp"

// Class to represent a university
class University {
private:
    std::string universityName;  // Name of the university
    std::vector<Department*> departments;  // List of departments in the university

public:
    // Constructor that initializes the university's name
    University(const std::string &name);

    // Method to add a department to the university
    Department* addDepartment(const std::string &departmentName);

    // Method to print information about the university
    void printUniversityInfo() const;

    // Destructor to clean up dynamically allocated memory
    ~University();
};

#endif
