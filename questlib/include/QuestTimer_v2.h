#pragma once

namespace RPG::Quests {
    class QuestTimer_v2 {
        private:
            int _duration;
            int _currentStep;
    
        public:
            void tick();
            void reset();
            explicit operator bool() const;
            explicit QuestTimer_v2(int duration);
    };
}