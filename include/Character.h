#pragma once
#include "Inventory.h"
#include <string>

class Character{
    private:
        Inventory _eq;
        std::string _name;
        int _hp;
        int _dmg;
    public:
        friend class SantaClauss;
        friend class Elf;
        Character();
        Character(std::string name, int hp, int dmg);
        Character(Inventory eq, std::string name);
        ~Character();
        void showStats() const;
        Inventory& getInventory();

        inline int getHp() {
            return _hp; 
        }
};