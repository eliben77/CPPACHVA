#include <iostream>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For seeding random number generator
using namespace std;

// Base Class: Character
class Character {
protected:
    string name;
    int health;

    // Protected method to reduce health
    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    }

public:
    Character(const string& name, int health) : name(name), health(health) {}
    virtual ~Character() {}

    // Virtual method for attack action
    virtual void attack(Character& target) = 0;

    // Public wrapper to apply damage
    void receiveDamage(int damage) {
        takeDamage(damage);
    }

    // Public getter for name
    string getName() const {
        return name;
    }

    // Display character's current health
    void displayStatus() const {
        cout << name << " has " << health << " health remaining." << endl;
    }

    // Check if the character is alive
    bool isAlive() const { return health > 0; }
};

// Derived Class: Warrior
class Warrior : public Character {
private:
    int strength;

public:
    Warrior(const string& name, int health, int strength)
        : Character(name, health), strength(strength) {}

    void attack(Character& target) override {
        int damage = strength + (rand() % 10); // Random bonus damage
        cout << getName() << " swings a sword at " << target.getName() << " for " << damage << " damage!" << endl;
        target.receiveDamage(damage); // Call the public wrapper
    }
};

// Derived Class: Mage
class Mage : public Character {
private:
    int magicPower;
    int spellsRemaining;

public:
    Mage(const string& name, int health, int magicPower, int spells)
        : Character(name, health), magicPower(magicPower), spellsRemaining(spells) {}

    void attack(Character& target) override {
        if (spellsRemaining > 0) {
            int damage = magicPower + (rand() % 15); // Random bonus damage
            cout << getName() << " casts a fireball at " << target.getName() << " for " << damage << " damage!" << endl;
            target.receiveDamage(damage); // Call the public wrapper
            spellsRemaining--;
        } else {
            cout << getName() << " is out of spells and cannot attack!" << endl;
        }
    }
};

// Main function: Game loop
int main() {
    // Seed random number generator
    srand(static_cast<unsigned>(time(0)));

    // Create characters
    Warrior warrior("Thor", 100, 20);
    Mage mage("Merlin", 80, 25, 3);

    // Game loop
    cout << "Battle begins between " << warrior.getName() << " and " << mage.getName() << "!" << endl;

    Character* fighter1 = &warrior;
    Character* fighter2 = &mage;

    while (fighter1->isAlive() && fighter2->isAlive()) {
        // Fighter 1 attacks Fighter 2
        fighter1->attack(*fighter2);
        fighter2->displayStatus();

        if (!fighter2->isAlive()) break;

        // Fighter 2 attacks Fighter 1
        fighter2->attack(*fighter1);
        fighter1->displayStatus();
    }

    // Display the winner
    if (fighter1->isAlive()) {
        cout << fighter1->getName() << " wins the battle!" << endl;
    } else {
        cout << fighter2->getName() << " wins the battle!" << endl;
    }

    return 0;
}
