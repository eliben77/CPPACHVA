#include "myprog2.hpp"
#include <iostream>

int func2()
{
    int age = 25;
    float height = 180;
    char grade = 'A';
    bool isStudent = true;

    std::cout << "Age: " << age << std::endl;
    std::cout << "Height: " << height << std::endl;
    std::cout << "Grade: " << grade << std::endl;
    std::cout << "Is Student: " << isStudent << std::endl;

    return 0;
}

int if_positive()
{
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    if (number > 0)
    {
        std::cout << "The number is positive." << std::endl;
    }
    else if (number < 0)
    {
        std::cout << "The number is negative." << std::endl;
    }
    else
    {
        std::cout << "The number is zero." << std::endl;
    }

    return 0;
}

void check_grade()
{

    char grade;
    std::cout << "Enter your grade (A, B, C, D, or F): ";
    std::cin >> grade;

    switch (grade)
    {
    case 'A':
        std::cout << "Excellent!" << std::endl;
        break;
    case 'B':
        std::cout << "Good!" << std::endl;
        break;
    case 'C':
        std::cout << "Fair!" << std::endl;
        break;
    case 'D':
        std::cout << "Poor!" << std::endl;
        break;
    case 'F':
        std::cout << "Fail!" << std::endl;
        break;
    default:
        std::cout << "Invalid grade." << std::endl;
    }
}

void loop_examples()
{
    
    int i;
    for (i = 0; i < 10; i++)
    {
        std::cout << i << " ";
    }
    std::cout << " \n";
    i = 0;
    while (i < 10)
    {
        std::cout << i << " ";
        i++;
    }
    std::cout << " \n";
    
    i=0;
    do
    {
        std::cout << i << " ";
        i++;
    } while (i < 10);
}