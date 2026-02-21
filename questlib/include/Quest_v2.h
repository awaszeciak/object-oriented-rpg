#pragma once
#include <string>
#include "SubQuest_v2.h"
#include <vector>

namespace RPG{
    namespace Quests{
        class Quest_v2 {
            private:
                std::string _name;
                bool _done;
                std::vector <SubQuest_v2> _subQuests;
                mutable int _counter;
                int _step;

                

            public:
                explicit Quest_v2(std::string name);
                Quest_v2(const char* name);

                void addSubQuest(const RPG::Quests::SubQuest_v2& subquest);
                void makeStep();
                bool isCompleted() const;

                explicit operator std::string() const;

        };
    }
}