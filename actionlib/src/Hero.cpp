#include "../include/Hero.h"
#include "../../include/Colors.h"
#include <iostream>

RPG::Actions::Hero::Hero(std::string name, int hp, int energy) 
    : _name(name), _hp(hp), _energy(energy) {}

void RPG::Actions::Hero::show() const {
    std::cout << GREEN << "=== Hero ===\n"<< RESET << "Name: " << _name << "   HP: " << _hp << " Energy: " << _energy << "\n";
}

void RPG::Actions::Hero::takeDamage(int dmg) {
    _hp -= dmg;
    if (_hp < 0) _hp = 0;
}

void RPG::Actions::Hero::heal(int value) {
    _hp += value;
}

void RPG::Actions::Hero::rest(int value) {
    _hp +=10;
}