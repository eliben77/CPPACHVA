#include <iostream>

class Complex {
private:
    double real; // Real part of the complex number
    double imag; // Imaginary part of the complex number

public:
    // Constructor to initialize the complex number
    // Default values are 0.0 for both real and imaginary parts
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overloading the + operator for adding two complex numbers
    // Returns a new Complex object with the sum of the real and imaginary parts
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overloading the - operator for subtracting two complex numbers
    // Returns a new Complex object with the difference of the real and imaginary parts
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overloading the * operator for multiplying two complex numbers
    // Returns a new Complex object with the product of the complex numbers
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    // Overloading the / operator for dividing two complex numbers
    // Returns a new Complex object with the quotient of the complex numbers
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator,
                       (imag * other.real - real * other.imag) / denominator);
    }

    // Overloading the unary - operator for negating a complex number
    // Returns a new Complex object with the negated real and imaginary parts
    Complex operator-() const {
        return Complex(-real, -imag);
    }

    // Overloading the unary + operator for returning the same complex number
    // Returns the current object without modification
    Complex operator+() const {
        return *this;
    }

    // Overloading the == operator for comparing two complex numbers
    // Returns true if both real and imaginary parts are equal, otherwise false
    bool operator==(const Complex& other) const {
        return (real == other.real && imag == other.imag);
    }

    // Overloading the != operator for checking inequality between two complex numbers
    // Returns true if the real or imaginary parts are different, otherwise false
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    // Overloading the << operator for outputting a complex number to an output stream
    // Allows complex numbers to be printed in the format "(real + imag i)"
    friend std::ostream& operator<<(std::ostream& out, const Complex& c) {
        out << "(" << c.real << " + " << c.imag << "i)";
        return out;
    }

    // Overloading the >> operator for inputting a complex number from an input stream
    // Prompts the user to enter the real and imaginary parts of the complex number
    friend std::istream& operator>>(std::istream& in, Complex& c) {
        std::cout << "Enter real part: ";
        in >> c.real;
        std::cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    // Overloading the prefix ++ (++c) operator for incrementing the real and imaginary parts
    // Increments both real and imaginary parts by 1
    // Returns a reference to the current object
    Complex& operator++() {
        ++real;
        ++imag;
        return *this;
    }

    // Overloading the postfix ++ (c++) operator for incrementing the real and imaginary parts
    // Increments both real and imaginary parts by 1
    // Returns the original value before incrementing
    Complex operator++(int) {
        Complex temp = *this;
        ++(*this); // reuse of prefix operator
        return temp;
    }

    // Overloading the prefix -- operator for decrementing the real and imaginary parts
    // Decrements both real and imaginary parts by 1
    // Returns a reference to the current object
    Complex& operator--() {
        --real;
        --imag;
        return *this;
    }

    // Overloading the postfix -- operator for decrementing the real and imaginary parts
    // Decrements both real and imaginary parts by 1
    // Returns the original value before decrementing
    Complex operator--(int) {
        Complex temp = *this;
        --(*this);
        return temp;
    }
};

int main() {
    Complex c1(3.0, 4.0);  // Creating a complex number 3 + 4i
    Complex c2(1.0, 2.0);  // Creating a complex number 1 + 2i

    // Performing arithmetic operations
    Complex sum = c1 + c2;         // Adding c1 and c2
    Complex diff = c1 - c2;        // Subtracting c2 from c1
    Complex prod = c1 * c2;        // Multiplying c1 by c2
    Complex quot = c1 / c2;        // Dividing c1 by c2

    // Outputting the results
    std::cout << "c1: " << c1 << "\nc2: " << c2 << "\nSum: " << sum << "\nDifference: " << diff
              << "\nProduct: " << prod << "\nQuotient: " << quot << std::endl;

    // Increment and decrement operations
    ++c1;  // Prefix increment, increments c1
    std::cout << "c1 after prefix ++: " << c1 << std::endl;

    c1++;  // Postfix increment, increments c1
    std::cout << "c1 after postfix ++: " << c1 << std::endl;

    --c1;  // Prefix decrement, decrements c1
    std::cout << "c1 after prefix --: " << c1 << std::endl;

    c1--;  // Postfix decrement, decrements c1
    std::cout << "c1 after postfix --: " << c1 << std::endl;

    // Inputting a new complex number from the user
    Complex c3;
    std::cin >> c3;  // Using >> operator to input
    std::cout << "You entered: " << c3 << std::endl;  // Using << operator to output

    return 0;
}
