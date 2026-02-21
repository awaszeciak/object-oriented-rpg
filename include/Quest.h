#pragma once
#include <string>


class Quest {
    private: 
        std::string _name;
        int _duration;
        bool _completed;
        mutable int _counter;

    public:
        Quest(const char* name); 
        explicit Quest(std::string name, int duration=0); 

        int getDuration();

        std::string getName() const;

        explicit operator std::string() const;

        void incrementExecution() const;
        

        

};