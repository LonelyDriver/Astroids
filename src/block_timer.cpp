#include "block_timer.h"

block::Timer::Timer() :
_start_ticks(0),
_paused_ticks(0),
_started(false),
_paused(false) {

}

void block::Timer::Start() {
    _started = true;
    _paused = false;

    _start_ticks = SDL_GetTicks();
    _paused_ticks = 0;
}

void block::Timer::Stop() {
    _started = false;
    _paused = false;

    _start_ticks = 0;
    _paused_ticks = 0;
    
}

void block::Timer::Pause() {
    if(_started && !_paused) {
        _paused = true;

        _paused_ticks = SDL_GetTicks() - _start_ticks;
        _start_ticks = 0;
    }
}

void block::Timer::Resume() {
    if(_started && _paused) {
        _paused = false;

        _start_ticks = SDL_GetTicks() - _paused_ticks;
        _paused_ticks = 0;
    }
}

Uint32 block::Timer::GetTicks() const {
    Uint32 time = 0;

    if(_started) {
        if(_paused) {
            time = _paused_ticks;
        }else {
            time = SDL_GetTicks() - _start_ticks;
        }
    }
    return time;
}

bool block::Timer::IsPaused() const {
    return _paused;
}

bool block::Timer::IsStarted() const {
    return _started;
}


// StdTimer

block::StdTimer::StdTimer() :
_start(),
_started(false)
{

}

void block::StdTimer::Start() {
    _start = std::chrono::high_resolution_clock::now();
    _started = true;
}

int64_t block::StdTimer::Milliseconds() const {
    int64_t time = 0;
    if(_started) {
        std::chrono::high_resolution_clock::time_point tmp = std::chrono::high_resolution_clock::now();
        time = std::chrono::duration_cast<std::chrono::milliseconds>(tmp - _start).count();
    }
    return time;
}

int64_t block::StdTimer::Round() {
    if(_started) {
       std::chrono::high_resolution_clock::time_point tmp = std::chrono::high_resolution_clock::now();
       const auto dt = std::chrono::duration_cast<std::chrono::milliseconds>(tmp - _start).count();  
       _start = tmp;
       return dt;
    }
    return 0;
}