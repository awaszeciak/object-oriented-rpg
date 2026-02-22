#pragma once
#include <vector>
#include <functional>

namespace RPG::Actions {
    class ActionQueue {
        private:
            std::vector<std::function<void()>> _actions;
        public:
            void push(std::function<void()> action);
            size_t size() const;

            void operator()();


    };
}