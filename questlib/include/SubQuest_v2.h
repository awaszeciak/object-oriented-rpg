#include <string>
#include "QuestTimer_v2.h"
namespace RPG {
    namespace Quests {
        class SubQuest_v2 {
            private:
                std::string _name;
                QuestTimer_v2 _timer;
                bool _done;
                mutable int _counter;

            public:
                explicit SubQuest_v2(std::string name, int time);
                SubQuest_v2(const char* name);

                void performStep();
                bool isCompleted() const;

                int getProgress() const;

                
        };
    }
}