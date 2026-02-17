#include "SantaClauss.h"
#include <iostream>
#include "Colors.h"
#include <cstdlib>

SantaClauss::SantaClauss() :
    _baseDamage(10) {
        _santa._name = "Santa Clauss";
        _santa._hp = 100;
    #ifdef DEBUG
        std::cout << "[DEBUG][SantaClauss] Default constructor\n";
    #endif
}

SantaClauss::SantaClauss(const std::string& name, int hp, int dmg):
_baseDamage(dmg) {
    _santa._name = name;
    _santa._hp = hp;

    #ifdef DEBUG
        std::cout << "[DEBUG][SantaClauss] Parameterized constructor\n";
    #endif
}

SantaClauss::SantaClauss(const SantaClauss& other) {
    _santa._name = other._santa._name;
    _santa._eq = other._santa._eq;
    _santa._hp = other._santa._hp;
    _baseDamage = other._baseDamage;

    #ifdef DEBUG
        std::cout << "[DEBUG][SantaClauss] Copy constructor\n";
    #endif

}

SantaClauss::SantaClauss(int difficultyLevel) :
SantaClauss(
    difficultyLevel == 1 ? "Santa (Level 1)" : "Santa (Level 2)",
    difficultyLevel == 1 ? 100 : 120,
    difficultyLevel == 1 ? 10 : 20)
{
    #ifdef DEBUG
        std::cout <<"[DEBUG][SantaClauss] Delegating constructor\n";
    #endif
}

SantaClauss::SantaClauss(bool withEquipment, int hp) {
    _santa._name = "Santa Clauss with equipment";
    _santa._hp = hp;
    _baseDamage = 30;

    if (withEquipment) {
        _santa._eq.add(Item("Candy cane", 10, 5));
    }

    #ifdef DEBUG
        std::cout << "[DEBUG][SantaClauss] Equipping constructor\n";
    #endif
}

void SantaClauss::showStats() const {
    std::cout << MAGENTA <<"=== Character ===\n" << RESET;
    std::cout << "Name: " << _santa._name << "\n"; 
    std::cout << "HP: " << _santa._hp << "\n";
    std::cout << "Base damage: " << _baseDamage << "\n\n";
}



SantaClauss::~SantaClauss() = default;


int SantaClauss::getHp() const{
    return _santa._hp;
} 

void SantaClauss::takeDamage(int dmg) {
    _santa._hp -= dmg;
    if(_santa._hp < 0)
        _santa._hp = 0;
}

bool SantaClauss::isAlive() const{
    return _santa._hp > 0;
}

int SantaClauss::getBaseDamage() const {
    return _baseDamage;
}




