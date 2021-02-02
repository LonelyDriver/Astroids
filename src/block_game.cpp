#include "block_game.h"
#include "block_timer.h"

block::Game::Game() :
_window(),
_renderer(),
_player(),
_logger(LogManager::GetLogger("Game")),
_running(false),
_texture_resource() {
    SDL_Init(SDL_INIT_VIDEO);

    _window = SDL_CreateWindow(
        "Block Wars",
        400,
        400,
        800,
        600,
        0
    );
    if(_window == nullptr) {
        _logger->Debug(STREAM("Creating window failed"<<SDL_GetError()));
        exit(-1);
    }
    _renderer = SDL_CreateRenderer(
        _window,
        -1,
        SDL_RENDERER_ACCELERATED
    );
    if(_renderer == nullptr) {
        _logger->Debug(STREAM("Creating renderer failed"<<SDL_GetError()));
        exit(-1);
    }

    SDL_SetRenderDrawColor(_renderer, 0,0,0,255);
    SDL_RenderClear(_renderer);
    SDL_RenderPresent(_renderer);
}

void block::Game::InitializeTextures() {
    _texture_resource.Load("player", _renderer, "../assets/Ship.png");
}

void block::Game::InitializeEntities() {
    const auto& player_texture = _texture_resource.Get("player");
    _player.SetTexture(player_texture.GetTexture());
    _player.SetDefaultInputs();
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
    _player.ProcessEvents();
}

void block::Game::Update(Uint32 time_ms) {
    _player.Update(time_ms);
}

void block::Game::Render() {
    SDL_RenderClear(_renderer);
    _player.Render(_renderer);

    SDL_RenderPresent(_renderer);
}