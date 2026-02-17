#pragma once
#include "Character.h"
#include "Item.h"
#include <string>

enum class ElfClassType {
    Warrior,
    Mage,
    Archer
};


class Elf {
    private:

    public:
        Elf();
        Elf(const std::string& name, int hp, int dmg);
        Elf(const Elf& const);
        explicit Elf(int diffucultyLevel);
        Elf(bool withEquipment, int hp);

        ~Elf();

        void showStats() const;
        Inventory& getInventory();
        int getHp() const;
        void takeDamage(int dmg);
        bool isAlive() const;
        int getBaseDamage() const;


};