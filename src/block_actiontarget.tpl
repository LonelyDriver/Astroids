namespace block {
    template<typename T>
    ActionTarget<T>::ActionTarget(const ActionMap<T>& map) : _action_map(map) {

    }

    template<typename T>
    bool ActionTarget<T>::ProcessEvent(const SDL_Event& event) const {
        bool res = false;

        for(auto& action : _events_realtime) {
            if(action.first == event) {
                action.second(event);
                res = true;
                break;
            }
        }
        return res;
    }

    template<typename T>
    void ActionTarget<T>::ProcessEvent() const {
        for(auto& action : _events_realtime) {
            if(action.first.Test()) {
                action.second(action.first.GetEvent());
            }
        }
    }

    template<typename T>
    void ActionTarget<T>::Bind(const T& key, const FuncType& callback) {
        const Action& action = _action_map.Get(key);
        _events_realtime.emplace_back(action, callback);
    }

    template<typename T>
    void ActionTarget<T>::Unbind(const T& key) {
        auto remove = [&key](const std::pair<T, FuncType>& pair) -> bool {
            return pair.first == key;
        };
        _events_realtime.remove_if(remove);
    }

}
