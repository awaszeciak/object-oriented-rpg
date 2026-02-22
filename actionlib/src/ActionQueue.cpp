#include "../include/ActionQueue.h"

namespace RPG::Actions {
    void ActionQueue::push(std::function<void()> action) {
        _actions.push_back(action);
    }

    size_t ActionQueue::size() const {
        return _actions.size();
    }

    void ActionQueue::operator()() {
        for (auto& action : _actions) {
            action();
        }
        _actions.clear();
    }
}
