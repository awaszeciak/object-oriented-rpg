#include "Elf.h"
#include <iostream>
#include <cstdlib>
#include "Colors.h"


Elf::Elf() :
    _baseDamage(15)
{
    _elf._name = "Elf";
    #ifdef DEBUG    
        std::cout << "[DEBUG][Elf] Default constructor\n";
    #endif
}

Elf::Elf(const std::string& name, int hp, ElfClassType type) 
    : _baseDamage(20), _type(type)
{
    _elf._name = name;
    _elf._hp = hp;
    #ifdef DEBUG
        std::cout << "[DEBUG][Elf] Parameterized constructor\n";
    #endif
}

Elf::Elf(const Elf& other) {
    _elf._name = other._elf._name;
    _elf._eq = other._elf._eq;
    _elf._hp = other._elf._hp;
    _baseDamage = other._baseDamage;
    _type = other._type;

    #ifdef DEBUG
        std::cout << "[DEBUG][Elf] Copy constructor\n";
    #endif
}

Elf Elf::createWarrior(const std::string& name) {
    return Elf(name, 100, ElfClassType::Warrior);
}

Elf Elf::createMage(const std::string& name) {
    return Elf(name, 80, ElfClassType::Mage);
}

Elf::Elf(ElfClassType type)
    : Elf(
        type == ElfClassType::Archer ? "Elf Archer" :
        type == ElfClassType::Mage   ? "Elf Mage"   :
                                       "Elf Warrior",

        type == ElfClassType::Archer ? 100 :
        type == ElfClassType::Mage   ? 50  : 80, type)
{
    #ifdef DEBUG
        std::cout << "[DEBUG][Elf] Delegating constructor\n";
    #endif
}


void Elf::showStats() const {
    std::cout << MAGENTA <<"=== Character ===\n" << RESET;
    std::cout << "Name: " << _elf._name << "\n"; 
    std::cout << "HP: " << _elf._hp << "\n";
    std::cout << "Base damage: " << _baseDamage << "\n\n";
}


Inventory& Elf::getInventory() {
    return _elf._eq;
}

int Elf::getHp() const {
    return _elf._hp;
}

void Elf::takeDamage(int dmg) {
    _elf._hp -= dmg;
    if (_elf._hp < 0) {
        _elf._hp = 0;
    }
}

bool Elf::isAlive() const {
    return _elf._hp>0;
}

int Elf::getBaseDamage() const {
    return _baseDamage;
}



Elf::~Elf() = default;