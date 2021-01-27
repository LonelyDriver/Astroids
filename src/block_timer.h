#ifndef _BLOCK_TIMER_H
#define _BLOCK_TIMER_H
#include "SDL2/SDL.h"

namespace block {
    class Timer {
    private:
    Uint32 _start_ticks;
    Uint32 _paused_ticks;
    bool _started;
    bool _paused;

    public:
        Timer();

        void Start();
        void Stop();
        void Pause();
        void Resume();
        Uint32 GetTicks() const;
        bool IsStarted() const;
        bool IsPaused() const;
    };
}

#endif