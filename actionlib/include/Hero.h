#pragma once
#include <string>

namespace RPG::Actions {
    class Hero {
        private:
            std::string _name;
            int _hp;
            int _energy;
        public:
            Hero(std::string name, int hp, int energy);
            void show() const;

            void takeDamage(int dmg);
            void heal(int value);
            void rest(int value);

    };
}