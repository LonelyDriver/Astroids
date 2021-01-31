#ifndef _BLOCK_GAME_H
#define _BLOCK_GAME_H

#include "logging_manager.h"
#include "SDL2/SDL.h"
#include "block_resource_manager.h"
#include "block_player.h"

namespace block {
    class Game {
    private:
        SDL_Window* _window;
        SDL_Renderer* _renderer;
        block::Player _player;
        Logger _logger;
        bool _running;
        ResourceManager<TextureLoader, std::string> _texture_resource;

        void ProcessEvents();
        void Update(Uint32 time_ms);
        void Render();
    public:
        Game(const Game&) = delete;
        Game& operator=(const Game&) = delete;
        Game();
        ~Game();

        void Run();
    };
}


#endif // _BLOCK_GAME_H