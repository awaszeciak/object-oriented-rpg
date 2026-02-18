#include "SantaArmy.h"
#include "Colors.h"
#include <iostream>

SantaArmy::SantaArmy()
    : _morale(0) {
#ifdef DEBUG
    std::cout << "[DEBUG][SantaArmy] Default constructor\n";
#endif
}


SantaArmy::SantaArmy(int count) 
    : _morale(100) {
        for (int i = 0; i < count; i++) {
            _units.emplace_back(SantaClauss());
        }
        #ifdef DEBUG
            std::cout << "[DEBUG][SantaArmy] Parametrized constructor\n";
        #endif
}

SantaArmy::SantaArmy(int count, bool elite)
    : _morale(120) {
        if (elite) {
            for (int i = 0; i < count; i++) {
                _units.emplace_back("Elite Santa", 150);
            }
        }
        else {
            for (int i = 0; i < count; i++) {
                _units.emplace_back(SantaClauss());
            }
        }

        #ifdef DEBUG
            std::cout << "[DEBUG][SantaArmy] Parametrized constructor\n";
        #endif
}

void SantaArmy::summonElite(int count) {
    for (int i = 0; i < count; i++) {
        _units.emplace_back("Elite Santa", 150);
    }
    _morale = 120;

}

SantaArmy::SantaArmy(const SantaArmy& other) {
    _units = other._units;
    _morale = other._morale;
    #ifdef DEBUG
        std::cout << "[DEBUG][SantaArmy] Copy constructor\n";
    #endif  
}

void SantaArmy::show() {
    std::cout << MAGENTA << "\n=== SantaClauss Army ===" << RESET << std::endl;
    std::cout << _units.size() << " units, morale: " << _morale << std::endl;
}