#pragma once
#include <string>
#include "Hero.h"
#include <iostream>
#include <functional>

namespace RPG::Actions {
    class Action {
        public:
            enum Type {
                Attack,
                Heal,
                Rest
            };

            Action(std::string name, Hero& hero1, Hero& hero2, int power);
            Action(std::string name, Type type, Hero& hero, int power);

            friend std::ostream& operator<<(std::ostream& os, const Action& action);
            friend std::istream& operator>>(std::istream& is, Action& action);

            Action& operator++();
            Action operator++(int);

            Action& operator--();
            Action operator--(int);


            void operator()() const;
            explicit operator int() const;    
            operator std::function<void()>() const;       
            

        private:
            std::string _name;
            Type _type;

            Hero* _source;
            Hero* _target;

            int _power;
            mutable int _counter;



        

    };
}