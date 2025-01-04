#ifndef MAT_HPP
#define MAT_HPP

#include <iostream>
#include <stdexcept>

class SquareMat {
private:
    int size;
    int** data;

public:
    // Constructor and Destructor
    SquareMat(int n);
    ~SquareMat();
    SquareMat(const SquareMat& other);
    SquareMat& operator=(const SquareMat& other);

    // Basic arithmetic operations
    SquareMat operator+(const SquareMat& other) const;
    SquareMat operator-(const SquareMat& other) const;
    SquareMat operator*(const SquareMat& other) const;  // Matrix * Matrix
    SquareMat operator%(const SquareMat& other) const; // Element-wise multiplication

    SquareMat operator*(const int scalar) const;    // Matrix * scalar
    SquareMat operator/(int scalar) const;    // Matrix / scalar
    SquareMat operator%(int scalar) const;    // Matrix % scalar
    SquareMat operator^(int power) const;     // Matrix power

    // Scalar * Matrix (global function)
    friend SquareMat operator*(const int scalar, const SquareMat& matrix);

    // Unary operators
    SquareMat operator-() const;              // Negation
    SquareMat& operator~() ;              // Transpose (self)

    // Increment/Decrement
    SquareMat& operator++();                  // Pre-increment
    SquareMat operator++(int);                // Post-increment
    SquareMat& operator--();                  // Pre-decrement
    SquareMat operator--(int);                // Post-decrement

    // Compound assignment
    SquareMat& operator+=(const SquareMat& other);
    SquareMat& operator-=(const SquareMat& other);

    // Comparison operators
    bool operator==(const SquareMat& other) const;
    bool operator!=(const SquareMat& other) const;

    // Access operators
    int& operator()(int i, int j);
    int* operator[](int index) const;

    // Output stream overload
    friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);
};

#endif // MAT_HPP
