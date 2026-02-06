#include <iostream>
using namespace std;

// Basklass med virtual funktion för polymorphism
class Animal {
public:
    virtual void sound() {
        cout << "Djuret ger ifrån sig ett ljud" << endl;
    }
    virtual ~Animal() {}  // Virtual destruktor för korrekt cleanup
};

// Mellanliggande klass med public inheritance (standard för "är-en" relation)
class Mammal : public Animal {
public:
    void breathe() {
        cout << "Mammals breath through their lungs" << endl;
    }
};

// Hund med public arv från Mammal
class Dog : public Mammal {
public:
    void sound() override {
        cout << "The Dog Barks: Woof!" << endl;
    }
};

// Katt med public arv från Mammal
class Cat : public Mammal {
public:
    void sound() override {
        cout << "The Cat goes Meow: Meow!" << endl;
    }
};

// Fågel med PRIVATE arv från Animal (exempel på private inheritance)
// Animals publika medlemmar blir privata i Bird – t.ex. kan inte kallas utanför Bird
class Bird : private Animal {
public:
    void sound() override {
        cout << "The Bird Tweets: Tweet!" << endl;
    }
    // Wrapper för att demonstrera tillgång internt
    void makeSound() {
        sound();  // Fungerar internt trots private arv
    }
    void fly() {
        cout << "The Bird flies gracefully." << endl;
    }
};

int main() {
    Animal* ptr;  // Pekare till basklass för polymorphism

    // Public arv-exempel
    Dog dog;
    ptr = &dog;
    ptr->sound();  // Polymorfism: Kallar Dogs sound()
    dog.breathe();

    Cat cat;
    ptr = &cat;
    ptr->sound();  // Polymorfism: Kallar Cats sound()
    cat.breathe();

   
    return 0;
}
