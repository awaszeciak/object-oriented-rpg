#include "Quest.h"
#include <string>

Quest::Quest(const char* name)
: _name(name), _completed(false)
{}

Quest::Quest(std::string name, int duration) 
: _name(std::move(name)), _duration(duration), _completed(false) {}

int Quest::getDuration() {
    return _duration;
}