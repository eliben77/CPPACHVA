#include "Animal.hpp"
#include <iostream>

using namespace std;

// Implementation of Animal methods
Animal::Animal(const std::string& name) : name(name) {}
Animal::~Animal() {}

std::string Animal::getName() const {
    return name;
}

// Implementation of Lion methods
Lion::Lion(const std::string& name) : Animal(name) {}

void Lion::makeSound() const {
    cout << name << " roars: Roarrrr!" << endl;
}

void Lion::move() const {
    cout << name << " runs swiftly across the savannah." << endl;
}

// Implementation of Eagle methods
Eagle::Eagle(const std::string& name) : Animal(name) {}

void Eagle::makeSound() const {
    cout << name << " screeches: Screeeech!" << endl;
}

void Eagle::move() const {
    cout << name << " soars high in the sky." << endl;
}

// Implementation of Fish methods
Fish::Fish(const std::string& name) : Animal(name) {}

void Fish::makeSound() const {
    cout << name << " bubbles: Blub blub!" << endl;
}

void Fish::move() const {
    cout << name << " swims gracefully in the water." << endl;
}

// Factory Function Implementation
Animal* createAnimal(const std::string& type, const std::string& name) {
    if (type == "Lion") {
        return new Lion(name);
    } else if (type == "Eagle") {
        return new Eagle(name);
    } else if (type == "Fish") {
        return new Fish(name);
    } else {
        cerr << "Unknown animal type: " << type << endl;
        return nullptr;
    }
}
