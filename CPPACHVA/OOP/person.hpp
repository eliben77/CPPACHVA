#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    Person(const std::string &n, int a) : name(n), age(a) {
}

    std::string getName() const { return name; }
    int getAge() const { return age; }
};



