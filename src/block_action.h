#ifndef _BLOCK_ACTION_H
#define _BLOCK_ACTION_H
#include "SDL2/SDL.h"
#include <cstring>
#include "logging_manager.h"

namespace block
{
    enum class Type {
        Pressed,
        Released
    };

    class Action {
    private:
        Type _type;
        SDL_Event _event;
        Logger _logger;
    public:
        Action(const Action& other);
        Action& operator=(const Action& other);
        Action(const SDL_EventType event_type, const SDL_Scancode& key, Type type=Type::Pressed);

        bool Test() const;
        bool operator==(const SDL_Event& event) const;
        bool operator==(const Action& other) const;

        SDL_Event GetEvent() const;
        Type GetType() const;

    };
    
} // namespace block


#endif // _BLOCK_ACTION_H