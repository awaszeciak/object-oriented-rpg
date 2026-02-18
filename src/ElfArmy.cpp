#include "ElfArmy.h"
#include "Colors.h"
#include <iostream>


ElfArmy::ElfArmy() 
: _morale(0) {
    #ifdef DEBUG
        std::cout << "[DEBUG][ElfArmy] Default constructor\n";
    #endif
}

ElfArmy::ElfArmy(int count, ElfClassType type) :
_morale(100) {
    for (int i = 0; i < count; i++) {
        _units.emplace_back(Elf(type));
    }
    #ifdef DEBUG
        std::cout <<"[DEBUG][ElfArmy] Parameterized constructor\n";
    #endif
}

ElfArmy::ElfArmy(const std::vector<std::string> &names, ElfClassType type) :
_morale(100) {
    for (size_t i = 0 ; i < names.size(); i++) {
        _units.emplace_back(Elf(names[i], 100, type));
    }
    #ifdef DEBUG
        std::cout <<"[DEBUG][ElfArmy] Parameterized constructor\n";
    #endif
}

ElfArmy::ElfArmy(const ElfArmy &other) {
    _morale = other._morale;
    _units = other._units;
    #ifdef DEBUG
        std::cout << "[DEBUG][ElfArmy] Copy constructor\n";
    #endif
}


void ElfArmy::summonRandom(int count) {
    for (int i = 0; i < count; ++i)
        _units.emplace_back(ElfClassType::Archer); 

    _morale = 100;

}

void ElfArmy::show() const {
    std::cout << MAGENTA << "\n=== Elf Army ===\n" << RESET <<
               _units.size() 
              << " units, morale: " << _morale 
              << RESET << "\n";
}

ElfArmy::~ElfArmy() {
    #ifdef DEBUG
        std::cout << "[DEBUG][ElfArmy] Destructor\n";
    #endif
}

