#pragma once

#include "SantaClauss.h"
#include <vector>

class ElfArmy;

class SantaArmy{
    private:
        std::vector<SantaClauss> _units;
        int _morale;

    public:
        friend void battleArmies(SantaArmy&, ElfArmy&);
        SantaArmy();
        SantaArmy(int count);
        SantaArmy(int count, bool elite);
        SantaArmy(const SantaArmy& other);

        void summonElite(int count);

        void show();



};