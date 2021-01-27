#ifndef _BLOCK_GAME_H
#define _BLOCK_GAME_H

#include "logging_manager.h"
#include "SDL2/SDL.h"

namespace block {
    class Game {
    private:
        SDL_Window* _window;
        SDL_Renderer* _renderer;
        SDL_Rect _player;
        Logger _logger;
        bool _running;

        void ProcessEvents();
        void Update();
        void Render();
    public:
        Game(const Game&) = delete;
        Game& operator=(const Game&) = delete;
        Game();

        void Run();
    };
}


#endif // _BLOCK_GAME_H