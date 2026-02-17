#pragma once
#include <string>

class Item {
    private:
        std::string _name;
        int _damage;
        int _value;

    public:
        Item();
        Item(std::string name, int dmg, int value);
        ~Item();

        std::string getName() const;
        int getDamage() const;
        int getValue() const;
};