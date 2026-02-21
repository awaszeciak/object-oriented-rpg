#include "../include/Reward_v2.h"

RPG::Rewards::GoldAmount_v2::GoldAmount_v2(int v)
    : _value(v) {}

RPG::Rewards::GoldAmount_v2::operator int() const {
    return _value;
}

RPG::Rewards::ExpAmount_v2::ExpAmount_v2(int v)
    : _value(v) {}

RPG::Rewards::ExpAmount_v2::operator int() const {
    return _value;
}

bool RPG::Rewards::Reward_v2::containsItem() const {
    return _hasItem;
}

RewardType_v2 RPG::Rewards::Reward_v2::getType() const {
    return _type;
}

RPG::Rewards::Reward_v2::Reward_v2(GoldAmount_v2 gold) 
    : _type(RewardType_v2::Gold), _goldValue(gold), _expValue(0), _item(), _hasItem(false) {}

RPG::Rewards::Reward_v2::Reward_v2(const Item& item) 
    : _type(RewardType_v2::Item), _goldValue(0), _expValue(0), _item(item), _hasItem(true) {}

RPG::Rewards::Reward_v2::Reward_v2(const Item& item, GoldAmount_v2 gold)
    : _type(RewardType_v2::Item_Gold), _goldValue(gold), _expValue(0), _item(item), _hasItem(true) {}

RPG::Rewards::Reward_v2::Reward_v2(const Item& item, GoldAmount_v2 gold, ExpAmount_v2 exp) 
    : _type(RewardType_v2::Item_Gold_Exp), _goldValue(gold), _expValue(exp), _item(item), _hasItem(true) {}

RPG::Rewards::Reward_v2::Reward_v2(ExpAmount_v2 exp, const Item& item) 
    : _type(RewardType_v2::Exp_Item), _goldValue(0), _expValue(exp), _item(item), _hasItem(true) {}

RPG::Rewards::Reward_v2::Reward_v2(ExpAmount_v2 exp) 
    : _type(RewardType_v2::Exp), _goldValue(0), _expValue(exp), _item(), _hasItem(false) {}

RPG::Rewards::Reward_v2::operator RPG::Rewards::GoldAmount_v2() const {
    return _goldValue;
}

RPG::Rewards::Reward_v2::operator RPG::Rewards::ExpAmount_v2() const {
    return _expValue;
}

RPG::Rewards::Reward_v2::operator Item() const {
    return _item;
}
