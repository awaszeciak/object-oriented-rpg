#include "SantaArmy.h"
#include "battleArmies.h"
#include "ElfArmy.h"
#include "Colors.h"
#include <iostream>
#include <cstdlib>

void battleArmies(SantaArmy& sArmy, ElfArmy& eArmy) {
    int round = 1;
    while (!sArmy._units.empty() && !eArmy._units.empty()) {
        std::cout << YELLOW << "\n[Round " << round << "]\n" << RESET;

        SantaClauss& fighterSanta = sArmy._units.front();
        Elf& fighterElf = eArmy._units.front();

        int sHit = fighterSanta.getBaseDamage() + std::rand() % 10;
        int eHit = fighterElf.getBaseDamage() + std::rand() % 8;

        std::cout << "Santa attacks for " << sHit << "\n";
        fighterElf.takeDamage(sHit);

        if (!fighterElf.isAlive()) {
            std::cout << RED << "An Elf has fallen!\n" << RESET;
            eArmy._units.erase(eArmy._units.begin()); 
        }
        else {
            std::cout << "Elf hits for " << eHit << "\n";
            fighterSanta.takeDamage(eHit);

            if (!fighterSanta.isAlive()) {
                std::cout << RED << "A Santa has fallen!\n" << RESET;
                sArmy._units.erase(sArmy._units.begin());
            }
        }
        round++;
    }

    std::cout << GREEN << "\n === ARMY BATTLE RESULT ===\n" << RESET;

    if (sArmy._units.empty() && eArmy._units.empty()) {
        std::cout << "Draw!\n";
    }
    else if (sArmy._units.empty())
        std::cout << "Elves win!\n";
    else
        std::cout << "Santa Army wins!\n";
}
