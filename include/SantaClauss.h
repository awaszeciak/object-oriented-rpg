#pragma once

#include "Character.h"
#include "Item.h"

class SantaClauss {
private:
    Character _santa;
    
    int _baseDamage;

public:
    SantaClauss();                                         // domyślny
    SantaClauss(const std::string& name, int hp, int dmg); // parametryczny
    SantaClauss(const SantaClauss& other);                 // kopiujący
    explicit SantaClauss(int difficultyLevel);             // delegujący
    SantaClauss(bool withEquipment, int hp);               // wyposażający

    ~SantaClauss();

    void showStats() const;
    Inventory& getInventory();

    int getHp() const;
    void takeDamage(int dmg);
    bool isAlive() const;

    int getBaseDamage() const;

};

