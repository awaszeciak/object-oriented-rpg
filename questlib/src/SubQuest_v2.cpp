#include "../include/SubQuest_v2.h"

RPG::Quests::SubQuest_v2::SubQuest_v2(std::string name, int time)
    : _name(name), _timer(time), _done(false), _counter(0) {}

RPG::Quests::SubQuest_v2::SubQuest_v2(const char* name) 
    : _name(name), _timer(3), _done(false), _counter(0) {}

bool RPG::Quests::SubQuest_v2::isCompleted() const {
    return _done;
}

int RPG::Quests::SubQuest_v2::getProgress() const {
    return _counter;
}

void RPG::Quests::SubQuest_v2::performStep() {
    if (_done)
        return;

    if (static_cast<bool>(_timer)) {
        _timer.tick();
        ++_counter;
    }

    if (!static_cast<bool>(_timer)) {
        _done = true;
    }
}