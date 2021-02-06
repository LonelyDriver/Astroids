#include "block_game.h"
#include "block_timer.h"
#include "SDL2/SDL_mixer.h"
#include "block_exeption.h"
#include "block_player.h"

block::Game::Game(const Vector& window_pos, const Vector& window_size) :
_window(),
_renderer(),
_logger(LogManager::GetLogger("Game")),
_running(false),
_texture_resource(),
_world_size(window_size),
_world(std::make_unique<World>(LogManager::GetLogger("World"), window_size)) {
    InitializeSDL(window_pos, window_size);
    InitializeSDLAudio();
}

void block::Game::InitializeSDL(const Vector& window_pos, const Vector& window_size) {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    _window = SDL_CreateWindow(
        "Block Wars",
        window_pos.GetX(),
        window_pos.GetY(),
        window_size.GetX(),
        window_size.GetY(),
        0
    );
    if(_window == nullptr) {
        throw BlockException(
            std::string("Creating window failed").c_str(),
            __FILE__,
            __LINE__,
            BLOCK_ERROR::WINDOW_INIT,
            SDL_GetError()
        );
    }
    _renderer = SDL_CreateRenderer(
        _window,
        -1,
        SDL_RENDERER_ACCELERATED
    );
    if(_renderer == nullptr) {
        throw BlockException(
            std::string("Creating renderer failed").c_str(),
            __FILE__,
            __LINE__,
            BLOCK_ERROR::RENDERER_INIT,
            SDL_GetError()
        );
    }

    SDL_SetRenderDrawColor(_renderer, 0,0,0,255);
    SDL_RenderClear(_renderer);
    SDL_RenderPresent(_renderer);
}

void block::Game::InitializeSDLAudio() {
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        throw BlockException(
            std::string("Audio initilization failed").c_str(),
            __FILE__,
            __LINE__,
            BLOCK_ERROR::AUDIO_INIT,
            Mix_GetError()
        );
    }
}

void block::Game::InitializeTextures() {
    _texture_resource.Load("player", _renderer, "../assets/Ship.png");
}

void block::Game::InitializeEntities() {
    const auto& player_texture = _texture_resource.Get("player");
    auto player = std::make_unique<Player>(player_texture.GetTexture());
    _world->AddEventEntity(std::move(player));
}

block::Game::~Game() {
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void block::Game::Run() {
    _running = true;
    Uint32 time_since_last_update = 0;
    const Uint32 ticks_per_frame = 1000 / 60;
    block::Timer timer;
    
    while(_running) {
        timer.Start();
        ProcessEvents();
        bool repaint = false;
        time_since_last_update += timer.GetTicks();
        
        while(time_since_last_update > ticks_per_frame) {
            time_since_last_update -= ticks_per_frame;
            Update(ticks_per_frame);
            repaint = true;
        }
        if(repaint) {
            Render();
        }
    }
}

void block::Game::ProcessEvents() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
            _logger->Debug("Cya");
            break;
        }else if(event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                _running = false;
                break;
            }
        }
    }
    _world->ProcessEvents();
}

void block::Game::Update(Uint32 time_ms) {
    _world->Update(time_ms);
    /*
    _player.Update(time_ms);

    const auto& player_pos = _player.GetPosition();

    if(player_pos.GetX() < 0) {
        _player.SetPosition(Vector(_world_size.GetX(), _world_size.GetY() - player_pos.GetY()));
    }else if(player_pos.GetX() > _world_size.GetX()) {
        _player.SetPosition(Vector(0, _world_size.GetY() - player_pos.GetY()));
    }else if(player_pos.GetY() < 0) {
        _player.SetPosition(Vector(_world_size.GetX() - player_pos.GetX(), _world_size.GetY()));
    }else if(player_pos.GetY() > _world_size.GetY()) {
        _player.SetPosition(Vector(_world_size.GetX() - player_pos.GetX(), 0));
    }
    */
}

void block::Game::Render() {
    SDL_RenderClear(_renderer);
    _world->Render(_renderer);

    SDL_RenderPresent(_renderer);
}