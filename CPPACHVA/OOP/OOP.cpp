#include <iostream>
#include <string>

// Demonstrating Functions, Inline Functions, and Function Overloading
class Calculator {
public:
    // Basic function to add two integers
    int add(int a, int b) {
        return a + b;
    }

    // Inline function to subtract two integers
    inline int subtract(int a, int b) {
        return a - b;
    }

    // Function overloading: multiplying integers
    int multiply(int a, int b) {
        return a * b;
    }

    // Function overloading: multiplying doubles
    double multiply(double a, double b) {
        return a * b;
    }
};


// Demonstrating Initialization Lists and Class Construction
class Engine {
private:
    int horsepower;
    std::string type;

public:
    // Constructor with initialization list
    Engine(int hp, const std::string &t) : horsepower(hp), type(t) {}

    int getHorsepower() const { return horsepower; }
    std::string getType() const { return type; }
};


// Car class containing an Engine object
class Car {
private:
    std::string brand;
    Engine engine;  // Car contains an Engine object

public:
    // Constructor using an initialization list
    Car(const std::string &b, int hp, const std::string &t) : brand(b), engine(hp, t) {}

    std::string getBrand() const { return brand; }
    int getEngineHorsepower() const { return engine.getHorsepower(); }
    std::string getEngineType() const { return engine.getType(); }

    // Destructor
    ~Car() {
        std::cout << "Car " << brand << " destroyed." << std::endl;
    }
};


// Demonstrating References vs. Pointers
void modifyValue(int *ptr) {
    int &ref = *ptr;  // Create a reference to the value pointed to by ptr
    ref *= 2;         // Modify the value through the reference
}


void referenceVsPointerExample() {
    int num = 10;

    int &ref = num; // Reference to num
    int *ptr = &num; // Pointer to num

    std::cout << "Original value: " << num << std::endl;

    ref += 5; // Modify num through reference
    std::cout << "Value after modifying through reference: " << num << std::endl;

    *ptr += 10; // Modify num through pointer
    std::cout << "Value after modifying through pointer: " << num << std::endl;

    modifyValue(ptr); // Modify num through reference inside a function
    std::cout << "Value after modifying through function: " << num << std::endl;
}


// Demonstrating Const Methods
class ConstCar {
private:
    std::string brand;
    int year;

public:
    ConstCar(const std::string &b, int y) : brand(b), year(y) {}

    // Const method to get the car's brand
    std::string getBrand() const {
        return brand;
    }

    // Non-const method to set the car's brand
    void setBrand(const std::string &b) {
        brand = b;
    }
};


void constMethodExample() {
    const ConstCar myCar("Toyota", 2020);
    ConstCar anotherCar("Honda", 2018);

    std::cout << "Car Brand (const): " << myCar.getBrand() << std::endl;
    std::cout << "Car Brand: " << anotherCar.getBrand() << std::endl;

    anotherCar.setBrand("Nissan");
    std::cout << "Updated Car Brand: " << anotherCar.getBrand() << std::endl;
}



// Main function to demonstrate all the concepts
int main() {
    // Functions, Inline Functions, and Function Overloading
    Calculator calc;
    std::cout << "Add: " << calc.add(5, 3) << std::endl;
    std::cout << "Subtract: " << calc.subtract(5, 3) << std::endl;
    std::cout << "Multiply (int): " << calc.multiply(5, 3) << std::endl;
    std::cout << "Multiply (double): " << calc.multiply(5.5, 3.3) << std::endl;

    // Initialization Lists, Classes, Constructors, and Destructors
    Car myCar("Ford", 400, "V8");
    std::cout << "Car Brand: " << myCar.getBrand() << std::endl;
    std::cout << "Engine Horsepower: " << myCar.getEngineHorsepower() << std::endl;
    std::cout << "Engine Type: " << myCar.getEngineType() << std::endl;

    // References vs. Pointers
    referenceVsPointerExample();

    // Const Methods
    constMethodExample();

    return 0;
}
