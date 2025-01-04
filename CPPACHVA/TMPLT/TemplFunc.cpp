#include <iostream>
#include <string>

// 1. Basic Function Template: Finds the maximum of two values
template <typename T>
T findMax(const T& a, const T& b) {
    return (a > b) ? a : b;
}

// 2. Overloaded Function Template: Calculates the sum of two or three values
template <typename T>
T calculateSum(const T& a, const T& b) {
    return a + b;
}

template <typename T>
T calculateSum(const T& a, const T& b, const T& c) {
    return a + b + c;
}

// 3. Specialized Template: Finds the "maximum" string based on length
template <>
std::string findMax(const std::string& a, const std::string& b) {
    return (a.length() > b.length()) ? a : b;
}

// 4. Template with Arrays: Calculates the sum of an array
template <typename T>
T sumArray(const T* arr, size_t size) {
    T sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

// 5. Template with Default Parameters: Multiplies two values with a scale factor
template <typename T = int>
T multiply(const T& a, const T& b, const T& scaleFactor = 1) {
    return (a * b) * scaleFactor;
}

// 6. Practical Use Case: Swaps two values
template <typename T>
void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Main function demonstrating various template functionalities
int main() {
    // Basic Function Template
    int x = 10, y = 20;
    std::cout << "Max of " << x << " and " << y << ": " << findMax(x, y) << std::endl;

    double p = 3.14, q = 2.71;
    std::cout << "Max of " << p << " and " << q << ": " << findMax(p, q) << std::endl;

    std::string str1 = "Hello", str2 = "World!";
    std::cout << "Longer string: " << findMax(str1, str2) << std::endl;

    // Overloaded Function Template
    std::cout << "Sum of 10 and 20: " << calculateSum(10, 20) << std::endl;
    std::cout << "Sum of 1.1, 2.2, and 3.3: " << calculateSum(1.1, 2.2, 3.3) << std::endl;

    // Template with Arrays
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << "Sum of intArray: " << sumArray(intArray, 5) << std::endl;
    std::cout << "Sum of doubleArray: " << sumArray(doubleArray, 5) << std::endl;

    // Template with Default Parameters
    std::cout << "Product of 3 and 4 (default scaleFactor): " << multiply(3, 4) << std::endl;
    std::cout << "Product of 3 and 4 (scaleFactor = 2): " << multiply(3, 4, 2) << std::endl;

    // Practical Use Case: Swapping Values
    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    swapValues(x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

    double a = 1.1, b = 2.2;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swapValues(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    return 0;
}
