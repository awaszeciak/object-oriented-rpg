#include "../include/Action.h"
#include "../../include/Colors.h"

RPG::Actions::Action::Action(std::string name, Hero& hero1, Hero& hero2, int power ) 
    : _name(name), _type(Type::Attack), _source(&hero1), _target(&hero2), _power(power), _counter(0) {}

RPG::Actions::Action::Action(std::string name, Type type, Hero& hero, int power) 
    : _name(name), _type(type), _source(&hero), _target(nullptr), _power(power), _counter(0) {}

std::ostream& RPG::Actions::operator<<(std::ostream& os, const Action& action) {
    os << MAGENTA << "=== Action ===\n"<< RESET << "Name: " << action._name << 
    " Type: " << action._type << " Power: " << action._power;
    return os;
}

RPG::Actions::Action& RPG::Actions::Action::operator++() {
    ++_power;
    return *this;
}

RPG::Actions::Action RPG::Actions::Action::operator++(int) {
    Action temp = *this;
    ++(*this);
    return temp;
}

RPG::Actions::Action& RPG::Actions::Action::operator--() {
    --_power;
    return *this;
}

RPG::Actions::Action RPG::Actions::Action::operator--(int) {
    Action temp = *this;
    --(*this);
    return temp;
}

RPG::Actions::Action::operator int() const {
    return _power;
}

std::istream& RPG::Actions::operator>>(std::istream& is, Action& action)
{
    int power;
    std::string name;

    is >> power >> name;

    action._power = power;
    action._name = name;

    return is;
}

void RPG::Actions::Action::operator()() const {
    ++_counter;

    switch(_type) {
        case Attack:
            if( _target)
                _target->takeDamage(_power);
            break;
        case Heal:
            if(_source)
                _source->heal(_power);
            break;
        case Rest:
            if(_source)
                _source->rest(_power);
            break;
    }
}

RPG::Actions::Action::operator std::function<void ()>() const {
    return [this]() {
        (*this)();
    };
}