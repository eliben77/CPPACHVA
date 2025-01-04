#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

// Abstract Base Class: Animal
class Animal {
protected:
    std::string name;

public:
    Animal(const std::string& name);
    virtual ~Animal();

    // Pure virtual methods
    virtual void makeSound() const = 0;
    virtual void move() const = 0;

    // Getter for animal name
    std::string getName() const;
};

// Derived Class: Lion
class Lion : public Animal {
public:
    Lion(const std::string& name);

    void makeSound() const override;
    void move() const override;
};

// Derived Class: Eagle
class Eagle : public Animal {
public:
    Eagle(const std::string& name);

    void makeSound() const override;
    void move() const override;
};

// Derived Class: Fish
class Fish : public Animal {
public:
    Fish(const std::string& name);

    void makeSound() const override;
    void move() const override;
};

// Factory Function
Animal* createAnimal(const std::string& type, const std::string& name);

#endif // ANIMAL_HPP
