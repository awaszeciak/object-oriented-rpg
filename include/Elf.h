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
        Character _elf;
        int _baseDamage;
        ElfClassType _type;

    public:
        Elf();
        Elf(const std::string& name, int hp, ElfClassType type);
        Elf(const Elf& other);
        Elf(ElfClassType type);

        ~Elf();

        static Elf createWarrior(const std::string& name);
        static Elf createMage(const std::string& name);

        void showStats() const;
        Inventory& getInventory();
        int getHp() const;
        void takeDamage(int dmg);
        bool isAlive() const;
        int getBaseDamage() const;


};