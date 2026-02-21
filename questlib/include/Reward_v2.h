#pragma once
#include "RewardType_v2.h"
#include "Item.h"

namespace RPG {
    namespace Rewards {

        class GoldAmount_v2 {
            int _value;
        public:
            GoldAmount_v2(int v);
            operator int() const;
        };

        class ExpAmount_v2 {
            int _value;
        public:
            explicit ExpAmount_v2(int v);
            operator int() const;
        };


        class Reward_v2 {
            public: 

                explicit Reward_v2(GoldAmount_v2 gold);
                explicit Reward_v2(const Item& item);
                explicit Reward_v2(const Item& item, GoldAmount_v2 gold);
                explicit Reward_v2(const Item& item, GoldAmount_v2 gold, ExpAmount_v2 exp);
                explicit Reward_v2(ExpAmount_v2 exp, const Item& item);
                explicit Reward_v2(ExpAmount_v2 exp);

                explicit operator GoldAmount_v2() const;
                explicit operator ExpAmount_v2() const;
                explicit operator Item() const;

                RewardType_v2 getType() const;
                bool containsItem() const;


            private:

                RewardType_v2 _type;
                GoldAmount_v2 _goldValue;
                ExpAmount_v2 _expValue;
                Item _item;
                bool _hasItem;
                

        };
    }
}