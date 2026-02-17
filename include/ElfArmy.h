#pragma once

#include "Elf.h"
#include <vector>


class ElfArmy{
    private:
        std::vector<Elf> _units;
        int _morale;


    public:
        ElfArmy();
        ElfArmy(int count, ElfClassType type);
        ElfArmy(const std::vector<std::string> &names, ElfClassType type);
        ElfArmy(const ElfArmy &other);
        ~ElfArmy();

        void summonRandom(int count);
        void show() const;

};