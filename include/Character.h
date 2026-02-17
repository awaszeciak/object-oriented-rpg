#pragma once
#include "Inventory.h"
#include <string>

class Character{
    private:
        Inventory _eq;
        std::string _name;
        int _hp;

    public:
        friend class SantaClauss;
        Character();
        Character(Inventory eq, std::string name);
        ~Character();
        void showStats() const;
        Inventory& getInventory();

        inline int getHp() {
            return _hp; 
        }
};