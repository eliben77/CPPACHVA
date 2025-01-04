#include <iostream>

// A simple Complex number class
class Complex
{
private:
    int real;
    int imag;
public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    int getReal() const     {        return real;    }

    int getImag() const    {        return imag;    }

    void setReal(int r)    {        real = r;    }

    void setImag(int i)    {        imag = i;    }

    // Overload the << operator to print Complex objects
    friend std::ostream &operator<<(std::ostream &os, const Complex &c)
    {
        os << c.real << " + " << c.imag << "i";
        return os;
    }
};

// SmartPointer class for managing memory
class SmartPointer
{
private:
    Complex *ptr;

public:
    // Constructor: Assign the pointer
    SmartPointer(Complex *p = nullptr) : ptr(p) {}

    // Overload the dereference operator to access the object
    Complex &operator*() { return *ptr; }

    // Overload the -> operator to access members of the underlying pointer
    Complex *operator->() { return ptr; }

    // Destructor: Clean up memory
    ~SmartPointer() { delete ptr; } // Free the allocated memory

    // Provide operators to check if the pointer is null
    bool operator!() const { return ptr == nullptr; }
    operator bool() { return bool(ptr); }
};

int main()
{
    //  Basic output of a Complex number using SmartPointer
    SmartPointer sp1(new Complex(42, 7));
    std::cout << "*sp1  " << *sp1 << std::endl; // Outputs: 42 + 7i

    // Access and modify members using SmartPointer
    sp1->setReal(10);
    sp1->setImag(20);
    std::cout << "*sp1 modified " << *sp1 << std::endl; // Outputs: 10 + 20i

    //  Create a new SmartPointer and Complex object
    SmartPointer sp2(new Complex(5, -3));
    std::cout << "*sp2 " << *sp2 << std::endl; // Outputs: 5 + -3i
    if ((bool)sp2)
    {
        std::cout << "sp2 is not pointing to nullptr" << std::endl;
    }

    //  Create a SmartPointer with default constructor (nullptr)
    SmartPointer sp3;
    if (!sp3)
    {
        std::cout << "sp3 is pointing to nullptr" << std::endl;
    }

    //  Using SmartPointer with zero complex numbers
    SmartPointer sp4(new Complex(0, 0));
    std::cout << " " << *sp4 << std::endl; // Outputs: 0 + 0i

    //  Accessing members using -> operator
    std::cout << " Real part of sp4 = " << sp4->getReal() << std::endl;
    std::cout << " Imaginary part of sp4 = " << sp4->getImag() << std::endl;

    return 0;
}
