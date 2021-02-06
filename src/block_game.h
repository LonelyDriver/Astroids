#ifndef _BLOCK_GAME_H
#define _BLOCK_GAME_H

#include <memory>
#include "logging_manager.h"
#include "SDL2/SDL.h"
#include "block_resource_manager.h"
#include "block_world.h"

namespace block {
    class Game {
    private:
        SDL_Window* _window;
        SDL_Renderer* _renderer;
        Logger _logger;
        bool _running;
        ResourceManager<TextureLoader, std::string> _texture_resource;
        Vector _world_size;
        std::shared_ptr<World> _world;

        void ProcessEvents();
        void Update(Uint32 time_ms);
        void Render();

        void InitializeSDL(const Vector& window_pos, const Vector& window_size);
        void InitializeSDLAudio();
    public:
        Game(const Game&) = delete;
        Game& operator=(const Game&) = delete;
        Game(const Vector& window_pos, const Vector& window_size);
        ~Game();

        void Run();
        void InitializeTextures();
        void InitializeEntities();
    };
}


#endif // _BLOCK_GAME_H