#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overloading the + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overloading the - operator
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overloading the * operator
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    // Overloading the / operator
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator,
                       (imag * other.real - real * other.imag) / denominator);
    }

    // Unary minus operator
    Complex operator-() const {
        return Complex(-real, -imag);
    }

    // Unary plus operator
    Complex operator+() const {
        return *this;
    }

    // Overloading the == operator
    bool operator==(const Complex& other) const {
        return (real == other.real && imag == other.imag);
    }

    // Overloading the != operator
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    // Overloading the << operator for output
    friend std::ostream& operator<<(std::ostream& out, const Complex& c) {
        out << "(" << c.real << " + " << c.imag << "i)";
        return out;
    }

    // Overloading the >> operator for input
    friend std::istream& operator>>(std::istream& in, Complex& c) {
        std::cout << "Enter real part: ";
        in >> c.real;
        std::cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    // Prefix increment
    Complex& operator++() {
        ++real;
        ++imag;
        return *this;
    }

    // Postfix increment
    Complex operator++(int) {
        Complex temp = *this;
        ++(*this);
        return temp;
    }

    // Prefix decrement
    Complex& operator--() {
        --real;
        --imag;
        return *this;
    }

    // Postfix decrement
    Complex operator--(int) {
        Complex temp = *this;
        --(*this);
        return temp;
    }
};

class Vector {
private:
    int arr[3];

public:
    Vector(int x = 0, int y = 0, int z = 0) {
        arr[0] = x;
        arr[1] = y;
        arr[2] = z;
    }

    // Subscript operator
    int& operator[](int index) {
        return arr[index];
    }

    // Overloading the << operator for output
    friend std::ostream& operator<<(std::ostream& out, const Vector& v) {
        out << "[" << v.arr[0] << ", " << v.arr[1] << ", " << v.arr[2] << "]";
        return out;
    }
};

class Polynomial {
public:
    double operator()(double x) const {
        // Example: f(x) = x^2 + 2x + 1
        return x * x + 2 * x + 1;
    }
};

class BitwiseTest {
private:
    int value;

public:
    BitwiseTest(int v = 0) : value(v) {}

    // Bitwise AND
    BitwiseTest operator&(const BitwiseTest& other) const {
        return BitwiseTest(value & other.value);
    }

    // Bitwise OR
    BitwiseTest operator|(const BitwiseTest& other) const {
        return BitwiseTest(value | other.value);
    }

    // Bitwise XOR
    BitwiseTest operator^(const BitwiseTest& other) const {
        return BitwiseTest(value ^ other.value);
    }

    // Bitwise NOT
    BitwiseTest operator~() const {
        return BitwiseTest(~value);
    }

    // Left shift
    BitwiseTest operator<<(int shift) const {
        return BitwiseTest(value << shift);
    }

    // Right shift
    BitwiseTest operator>>(int shift) const {
        return BitwiseTest(value >> shift);
    }

    // Overloading the << operator for output
    friend std::ostream& operator<<(std::ostream& out, const BitwiseTest& b) {
        out << b.value;
        return out;
    }
};

int main() {
    // Complex number operations
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    Complex c3 = c1 + c2;
    Complex c4 = -c1;
    Complex c5 = ++c1;
    Complex c6 = c2--;

    std::cout << "c1: " << c1 << "\nc2: " << c2 << "\nc3: " << c3 << "\nc4: " << c4 << "\nc5: " << c5 << "\nc6: " << c6 << std::endl;

    // Vector operations
    Vector v1(1, 2, 3);
    std::cout << "v1: " << v1 << std::endl;
    v1[0] = 10;
    std::cout << "v1 after modification: " << v1 << std::endl;

    // Polynomial function call
    Polynomial poly;
    double result = poly(5.0);
    std::cout << "Polynomial result: " << result << std::endl;

    // Bitwise operations
    BitwiseTest b1(6);  // 0110 in binary
    BitwiseTest b2(3);  // 0011 in binary
    BitwiseTest b3 = b1 & b2;
    BitwiseTest b4 = b1 | b2;
    BitwiseTest b5 = b1 ^ b2;
    BitwiseTest b6 = ~b1;
    BitwiseTest b7 = b1 << 1;
    BitwiseTest b8 = b1 >> 1;

    std::cout << "b1 & b2: " << b3 << "\nb1 | b2: " << b4 << "\nb1 ^ b2: " << b5 << "\n~b1: " << b6
              << "\nb1 << 1: " << b7 << "\nb1 >> 1: " << b8 << std::endl;

    return 0;
}
