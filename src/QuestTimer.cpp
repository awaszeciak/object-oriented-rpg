#include "QuestTimer.h"
#include <iostream>

QuestTimer::QuestTimer(int duration) 
: _duration(duration), _currentStep(0) {
    #ifdef DEBUG
        std::cout << "[DEBUG][QuestTimer] Constructor\n";
    #endif
}

void QuestTimer::tick() {
    if (_currentStep < _duration) {
        _currentStep++;
    }
}

QuestTimer::operator bool() const {
    if (_currentStep < _duration){
        return true;
    }
    else return false;
}