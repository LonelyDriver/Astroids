#ifndef _BLOCK_ACTIONMAP_H
#define _BLOCK_ACTIONMAP_H
#include <unordered_map>
#include "block_action.h"

namespace block
{
    template<typename T = int>
    class ActionMap {
    private:
        std::unordered_map<T,Action> _map;

    public:
        ActionMap(const ActionMap<T>& other) = delete;
        ActionMap& operator=(const ActionMap<T>& other) = delete;
        ActionMap() = default;

        void Add(const T& key, const Action& action);
        const Action& Get(const T& key) const;
    }; 
} // namespace block

#include "block_actionmap.tpl"

#endif // _BLOCK_ACTIONMAP_H