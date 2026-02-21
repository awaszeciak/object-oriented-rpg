#include "Reward.h"
#include <iostream>

Reward::Reward(int gold) 
: _type(RewardType::Gold), _goldValue(gold),  _santa(), _item() {
    #ifdef DEBUG
        std::cout << "[DEBUG][Reward] Gold constructor\n";
    #endif
}

Reward::Reward(const Item& item)
: _type(RewardType::Item), _goldValue(0), _santa(), _item(item) {
    #ifdef DEBUG
        std::cout << "[DEBUG][Reward] Item constructor\n";
    #endif
}

Reward::Reward(const SantaClauss& santa)
: _type(RewardType::Companion), _goldValue(0), _santa(santa), _item(){
    #ifdef DEBUG
        std::cout << "[DEBUG][Reward] SantaClauss constructor\n";
    #endif
}

Reward::~Reward() {
    #ifdef DEBUG 
        std::cout << "[DEBUG][Reward] Destructor\n";
    #endif
}

Reward::operator int() const{
    if(_type != RewardType::Gold) {
        throw std::logic_error("Reward is not gold");
    }
    return _goldValue;
}

Reward::operator SantaClauss() const {
    if(_type != RewardType::Companion) {
        throw std::logic_error("Reward is not companion");
    }
    return _santa;
}

Reward::operator Item() const {
    if(_type != RewardType::Item) {
        throw std::logic_error("Reward is not item");
    }
    return _item;
}

RewardType Reward::getType() const {
    return _type;
}