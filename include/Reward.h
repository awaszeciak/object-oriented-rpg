#pragma once
#include "RewardType.h"
#include "Item.h"
#include "SantaClauss.h"
class Reward {
    private:
        RewardType _type;
        int _goldValue;
        SantaClauss _santa;
        Item _item;

    public:
        explicit Reward(int gold);
        explicit Reward(const Item& item);
        explicit Reward(const SantaClauss& santa);

        explicit operator int() const;
        explicit operator Item() const;
        explicit operator SantaClauss() const;

        RewardType getType() const;
        
        ~Reward();

};