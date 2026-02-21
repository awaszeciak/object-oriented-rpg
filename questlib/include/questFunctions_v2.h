#pragma once
#include "Quest_v2.h"
#include "../../include/Item.h"
#include "Reward_v2.h"

namespace RPG::Tasks {
    RPG::Rewards::Reward_v2 miningGold_v2(RPG::Quests::Quest_v2& quest);
    RPG::Rewards::Reward_v2 collectSnow_v2(RPG::Quests::Quest_v2& quest);
    RPG::Rewards::Reward_v2 huntReindeer_v2(RPG::Quests::Quest_v2& quest);
}