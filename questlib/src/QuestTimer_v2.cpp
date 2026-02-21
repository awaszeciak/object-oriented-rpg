#include "../include/QuestTimer_v2.h"

void RPG::Quests::QuestTimer_v2::tick() {
    if (_currentStep < _duration) {
        _currentStep++;
    }
}

void RPG::Quests::QuestTimer_v2::reset() {
    _currentStep = 0;
}

RPG::Quests::QuestTimer_v2::operator bool() const {
    if (_duration > _currentStep) return true;
    else return false;
}

RPG::Quests::QuestTimer_v2::QuestTimer_v2(int duration) 
    : _duration(duration), _currentStep(0) {}