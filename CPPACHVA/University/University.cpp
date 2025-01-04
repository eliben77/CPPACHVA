#include <iostream>
#include "University.hpp"

// Constructor that initializes the university's name
University::University(const std::string &name) : universityName(name) {}

// Method to add a department to the university
Department* University::addDepartment(const std::string &departmentName) {
    auto department = new Department(departmentName);
    departments.push_back(department);
    return department;
}

// Method to print information about the university
void University::printUniversityInfo() const {
    std::cout << "University: " << universityName << std::endl;
    for (const auto &department : departments) {
        department->printDepartmentInfo();
        std::cout << std::endl;
    }
}

// Destructor to clean up dynamically allocated memory
University::~University() {
    for (auto department : departments) {
        delete department;
    }
}
