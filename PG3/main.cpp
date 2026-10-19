#include <iostream>

class Animal {
public:
    virtual void Speak() const = 0;
};

class Dog : public Animal {
public:
    void Speak() const override {
        std::cout << "Woof!\n";
    }
};

class Cat : public Animal {
public:
    void Speak() const override {
        std::cout << "Meow!\n";
    }
};

int main() {
    Dog dog;
    Cat cat;

    const Animal* animals[] = { &dog, &cat };
    for (const Animal* animal : animals) {
        animal->Speak();
    }

    return 0;
}