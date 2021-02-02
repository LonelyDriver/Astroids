#include "block_action.h"

block::Action::Action(
    const SDL_EventType event_type,
    const SDL_Scancode& key,
     block::Type type) :
_type(type),
_event(),
_logger(LogManager::GetLogger("Action")) {
    _event.type = event_type;
    _event.key.keysym.scancode = key;
}

block::Action::Action(const Action& other) :
_type(other._type),
_event(),
_logger() {
    std::memcpy(&_event, &other._event, sizeof(SDL_Event));
    _logger = other._logger;
}

block::Action& block::Action::operator=(const Action& other) {
    std::memcpy(&_event, &other._event, sizeof(SDL_Event));
    _type = other._type;
    return *this;
}

bool block::Action::operator==(const SDL_Event& event) const {
    bool res = false;

    switch (event.type)
    {
    case SDL_KEYDOWN:
        
        if(_type == Type::Pressed) {
            res = event.key.keysym.scancode == _event.key.keysym.scancode;
        }
        break;
    case SDL_KEYUP:    
        if(_type == Type::Released) {
            res = event.key.keysym.scancode == _event.key.keysym.scancode;
        }
        break;
    
    default:
        break;
    }
    return res;
}

bool block::Action::operator==(const Action& other) const {
    return _type == other._type && other == _event;
}

bool block::Action::Test() const {
    bool res = false;

    if(_event.type == SDL_KEYDOWN) {
        if(_type == Type::Pressed) {
            const Uint8* state = SDL_GetKeyboardState(NULL);
            res = state[_event.key.keysym.scancode];
        }
    }else if(_event.type == SDL_KEYUP) {
        if(_type == Type::Released) {
            const Uint8* state = SDL_GetKeyboardState(NULL);
            res = state[_event.key.keysym.scancode];
        }
    }

    return res;
}

SDL_Event block::Action::GetEvent() const {
    return _event;
}

block::Type block::Action::GetType() const {
    return _type;
}