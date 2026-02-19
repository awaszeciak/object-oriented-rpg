#include "Character.h"
#include <string>
#include <iostream>
#include "Colors.h"

Character::Character():
_eq(), _name("Knight"), _hp(100), _dmg(10) {
    #ifdef DEBUG
        std::cout << "[DEBUG][Character] Default constructor: " << _name << "\n";
    #endif
}

Character::Character(std::string name, int hp, int dmg)
: _name(name), _hp(hp), _dmg(dmg){

}

Character::Character(Inventory eq, std::string name):
_eq(eq), _name(name), _hp(100), _dmg(10) {
    #ifdef DEBUG
        std::cout << "[DEBUG][Character] Parameterized constructor: " << _name << "\n";
    #endif
}

Character::~Character() {
    #ifdef DEBUG
        std::cout << "[DEBUG][Character] Destructor: " << _name << "\n";
    #endif
}

void Character::showStats() const {
    std::cout << MAGENTA << "\n=== Character ===\n" << RESET;
    std::cout << "Name: " << _name << "\n";
    std::cout << "HP: " << _hp << "\n";
    std::cout << "DMG: " << _dmg << "\n";

}

Inventory& Character::getInventory() {
    return _eq;
}