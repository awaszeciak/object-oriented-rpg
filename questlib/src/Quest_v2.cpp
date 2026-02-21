#include "../include/Quest_v2.h"
#include <iostream>

bool RPG::Quests::Quest_v2::isCompleted() const {
    return _done;
}

void RPG::Quests::Quest_v2::addSubQuest(const RPG::Quests::SubQuest_v2& subquest) {
    _subQuests.push_back(subquest);
}

void RPG::Quests::Quest_v2::makeStep(){
   
    if (_done || _subQuests.empty())
        return;


    if (_step >= _subQuests.size()) {
        _done = true;
        return;
    }

    _counter++;

    _subQuests[_step].performStep();

    if (_subQuests[_step].isCompleted()) {
        ++_step;

        if(_step >= _subQuests.size()) {
            _done = true;
        }
    }

    
}

RPG::Quests::Quest_v2::operator std::string() const {
    return _name;
}

RPG::Quests::Quest_v2::Quest_v2(std::string name) 
:   _name(name), _done(false), _subQuests(), _counter(0), _step(0) {}

RPG::Quests::Quest_v2::Quest_v2(const char* name) 
:   _name(name), _done(false), _subQuests(), _counter(0), _step(0) {}


