namespace block
{
    template<typename T>
    void ActionMap<T>::Add(const T& key, const Action& action) {
        _map.emplace(key, action);
    }
    
    template<typename T>
    const Action& ActionMap<T>::Get(const T& key) const {
        return _map.at(key);
    }
} // namespace block
