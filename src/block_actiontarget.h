#ifndef _BLOCK_ACTIONTARGET_H
#define _BLOCK_ACTIONTARGET_H
#include <list>
#include <functional>
#include "block_action.h"
#include "block_actionmap.h"

namespace block
{
    using FuncType = std::function<void(const SDL_Event& event)>;
    template<typename T = int>
    class ActionTarget {
    private:
        std::list<std::pair<Action, FuncType>> _events_realtime;
        const ActionMap<T>& _action_map;
    public:
        ActionTarget(const ActionTarget&) = delete;
        const ActionTarget& operator=(const ActionTarget&) = delete;
        ActionTarget(const ActionMap<T>& map);

        bool ProcessEvent(const SDL_Event& e) const;
        void ProcessEvent() const;

        void Bind(const T& key, const FuncType& callback);
        void Unbind(const T& key);

    };
} // namespace block

#include "block_actiontarget.tpl"

#endif // _BLOCK_ACTIONTARGET_H