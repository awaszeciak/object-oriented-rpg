#include "SantaClauss.h"
#include <iostream>
#include <cstdlib>

SantaClauss::SantaClauss() {
    #ifdef DEBUG
        std::cout << "[DEBUG][SantaClauss] Domyślny\n";
    #endif
}

SantaClauss::SantaClauss(const std::string& name, int hp, int dmg) {
    _santa._name = name;
    _santa._hp = hp;
    _baseDamage = dmg;

    #ifdef DEBUG
        std::cout << "[DEBUG][SantaClauss] Parametryczny\n";
    #endif
}

SantaClauss::SantaClauss(const SantaClauss& other) {
    _santa._name = other._santa._name;
    _santa._eq = other._santa._eq;
    _santa._hp = other._santa._hp;
    _baseDamage = other._baseDamage;

    #ifdef DEBUG
        std::cout << "[DEBUG][SantaClauss] Kopiujący\n";
    #endif

}

SantaClauss::SantaClauss(bool withEquipment, int hp) {

}

void SantaClauss::showStats() const {
    std::cout << "=== Postać ===\n";
    std::cout << "Imię: " << _santa._name << "\n"; 
    std::cout << "HP: " << _santa._hp << "\n";
    std::cout << "Bazowe obrażenia: " << _baseDamage << "\n";
}



SantaClauss::~SantaClauss() {
    
}


int SantaClauss::getHp() const{
    return _santa._hp;
} 

void SantaClauss::takeDamage(int dmg) {
    
}

bool SantaClauss::isAlive() const{

}

int SantaClauss::getBaseDamage() const {

}




