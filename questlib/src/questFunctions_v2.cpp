#include "../include/questFunctions_v2.h"
#include <iostream>
#include "../../include/Colors.h"

    RPG::Rewards::Reward_v2 RPG::Tasks::collectSnow_v2(RPG::Quests::Quest_v2& quest){

        std::cout << MAGENTA << "[CollectSnow] Gathering snow...\n" << RESET;

        quest.makeStep();
        if(quest.isCompleted()) {
            std::cout << YELLOW << "[CollectSnow] Quest completed!\n" <<RESET;
            Item item("Bag of Snow", 10, 10);
            return RPG::Rewards::Reward_v2(RPG::Rewards::ExpAmount_v2(100), item);
        }

        return RPG::Rewards::Reward_v2(RPG::Rewards::ExpAmount_v2(0));
    }
    RPG::Rewards::Reward_v2 RPG::Tasks::miningGold_v2(RPG::Quests::Quest_v2& quest){

        std::cout << MAGENTA << "[MiningGold] Working on quest...\n" << RESET;

        quest.makeStep();
        if(quest.isCompleted()) {
            std::cout << YELLOW << "[MiningGold] Quest completed!\n" << RESET;
            return RPG::Rewards::Reward_v2(RPG::Rewards::GoldAmount_v2(100));
        }

        return RPG::Rewards::Reward_v2(RPG::Rewards::ExpAmount_v2(0));
    }

    RPG::Rewards::Reward_v2 RPG::Tasks::huntReindeer_v2(RPG::Quests::Quest_v2& quest){
        quest.makeStep();

        std::cout << MAGENTA << "[HuntReindeer] Hunting reindeer...\n" << RESET;
        if(quest.isCompleted()) {
            
            std::cout << YELLOW << "[HuntReindeer] Quest completed!\n" <<RESET;

            Item item("Reindeer Trophy", 5, 10);
            return RPG::Rewards::Reward_v2(item, RPG::Rewards::GoldAmount_v2(75), RPG::Rewards::ExpAmount_v2(30));
        }
        return RPG::Rewards::Reward_v2(RPG::Rewards::ExpAmount_v2(0));
    }