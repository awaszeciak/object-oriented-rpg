#pragma once

#include "Elf.h"
#include <vector>

class SantaArmy;

class ElfArmy{
    private:
        std::vector<Elf> _units;
        int _morale;


    public:
        friend void battleArmies(SantaArmy&, ElfArmy&);
        ElfArmy();
        ElfArmy(int count, ElfClassType type);
        ElfArmy(const std::vector<std::string> &names, ElfClassType type);
        ElfArmy(const ElfArmy &other);
        ~ElfArmy();

        void summonRandom(int count);
        void show() const;

};