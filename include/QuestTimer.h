#pragma once

class QuestTimer {
    private:
        int _duration;
        int _currentStep;

    public:
        explicit QuestTimer(int duration);

        void tick();
        explicit operator bool() const;

};