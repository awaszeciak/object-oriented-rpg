#include "ElfArmy.h"
#include "Colors.h"
#include <iostream>


void ElfArmy::summonRandom(int count)
{
    for (int i = 0; i < count; ++i)
        units.emplace_back(ElfClassType::Archer); // losowy łucznik

    morale = 100;

    std::cout << CYAN << "Przywołano " << count 
              << " losowych Elfów!" << RESET << "\n";
}

void ElfArmy::show() const
{
    std::cout << CYAN << "\nArmia Elfów: " 
              << units.size() 
              << " jednostek, morale: " << morale 
              << RESET << "\n";
}
