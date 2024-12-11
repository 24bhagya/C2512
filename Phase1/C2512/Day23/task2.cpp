//single inheritance using static binding:
=============================================================
//Create two static objects for Both Base and Derived class and call all behaviour 
//one two dynamic objects for Base and Derived class 
//and call all behaviours

//Define constructors and destructors for all the classes 
//Example 9: `Gaming System`
//`Base Class:` Character `{field: health, behavior: move()}`
//- `Derived Class:` Warrior `{field: weaponType, behavior: attack()}`

#include <iostream>
#include <string>

using  std::cout;
using std::endl;
using std::string;

// Base Class
class Character {
protected:
    int health;

public:
    Character(int h) : health(h) {
        cout << "Character constructor called. Health: " << health << endl;
    }

    ~Character() {
        cout << "Character destructor called.\n";
    }

    void move() {
        cout << "Character is moving. Health: " << health << endl;
    }
};

// Derived Class
class Warrior : public Character {
private:
    string weaponType;

public:
    Warrior(int h, const string& weapon) : Character(h), weaponType(weapon) {
        cout << "Warrior constructor called. Weapon: " << weaponType << endl;
    }

    ~Warrior() {
        cout << "Warrior destructor called.\n";
    }

    void attack() {
        cout << "Warrior is attacking with " << weaponType << ". Health: " << health << endl;
    }
};

int main() {
    // Creating static objects
    cout << "Creating static objects:\n";
    Character staticCharacter(100);
    Warrior staticWarrior(200, "Sword");

    staticCharacter.move();
    staticWarrior.move();
    staticWarrior.attack();

    cout << "\nCreating dynamic objects:\n";
    // Creating dynamic objects
    Character* dynamicCharacter = new Character(80);
    Warrior* dynamicWarrior = new Warrior(150, "Axe");

    dynamicCharacter->move();
    dynamicWarrior->move();
    dynamicWarrior->attack();

    cout << "\nDeleting dynamic objects:\n";
    delete dynamicCharacter;
    delete dynamicWarrior;

    return 0;
}
