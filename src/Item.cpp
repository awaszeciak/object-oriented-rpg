#include "Item.h"
#include <iostream>

Item::Item():
    _name("Brak"), _damage(0), _value(0)  {
        #ifdef DEBUG
            std::cout << "[DEBUG][Item] Default constructor\n";
        #endif
}

Item::Item(std::string name, int dmg, int value):
    _name(name), _damage(dmg), _value(value) {
        #ifdef DEBUG
            std::cout << "[DEBUG][Item] Parameterized constructor: " << _name << "\n";
        #endif
}

Item::~Item() {
    #ifdef DEBUG
        std::cout << "[DEBUG][Item] Destructor: " << _name << "\n"; 
    #endif
}

std::string Item::getName() const {
    return _name;
}

int Item::getDamage() const {
    return _damage;
}

int Item::getValue() const {
    return _value;
}