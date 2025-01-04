#include "Animal.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Create a collection of animals
    vector<Animal*> zoo;

    // Add animals using the factory function
    zoo.push_back(createAnimal("Lion", "Simba"));
    zoo.push_back(createAnimal("Eagle", "Majestic"));
    zoo.push_back(createAnimal("Fish", "Goldie"));
    zoo.push_back(createAnimal("Lion", "Nala"));
    zoo.push_back(createAnimal("Fish", "Bubbles"));

    // Simulate the animals' behavior
    for (const auto& animal : zoo) {
        if (animal) { // Check if the animal was successfully created
            cout << "Meet " << animal->getName() << "!" << endl;
            animal->makeSound();
            animal->move();
            cout << endl;
        }
    }

    // Clean up memory
    for (auto& animal : zoo) {
        delete animal;
    }

    return 0;
}
