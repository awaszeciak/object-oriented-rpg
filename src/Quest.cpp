#include "Quest.h"
#include <string>
#include <iostream>

Quest::Quest(const char* name)
: _name(name), _completed(false), _duration(2)
{
    #ifdef DEBUG
        std::cout << "[DEBUG][Quest] Implicit onstructor\n";
    #endif
}

Quest::Quest(std::string name, int duration) 
: _name(std::move(name)), _duration(duration), _completed(false) {
    #ifdef DEBUG
        std::cout << "[DEBUG][Quest] Explicit contructor\n";
    #endif
}

int Quest::getDuration() {
    return _duration;
}

std::string Quest::getName() const {
    return _name;
}

Quest::operator std::string() const {
    return _name;
}

void Quest::incrementExecution() const {
    _counter++;
}