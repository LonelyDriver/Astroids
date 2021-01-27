#include "block_game.h"
#include "block_timer.h"

block::Game::Game() :
_window(),
_renderer(),
_player(),
_logger(LogManager::GetLogger("Game")),
_running(false) {
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

    SDL_SetRenderDrawColor(_renderer, 0,0,0,SDL_ALPHA_OPAQUE);
    SDL_RenderClear(_renderer);
    SDL_RenderPresent(_renderer);

    _player.x = 20;
    _player.y = 10;
    _player.w = 100;
    _player.h = 100;
}

void block::Game::Run() {
    _running = true;
    Uint32 time_since_last_update = 0;
    const Uint32 ticks_per_frame = 1000 / 60;
    block::Timer timer;
    _logger->Debug(STREAM("Ticks per frame: "<<ticks_per_frame));
    SDL_Delay(2000);
    while(_running) {
        timer.Start();
        ProcessEvents();
        bool repaint = false;
        _logger->Debug(STREAM("Last update: "<<time_since_last_update));
        time_since_last_update += timer.GetTicks();
        while(time_since_last_update > ticks_per_frame) {
            time_since_last_update -= ticks_per_frame;
            Update(); // Update(ticks_per_frame)
            repaint= true;
            _logger->Debug("UPDATE");
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
            
            default:
                break;
            }
        }


    }
}

void block::Game::Update() {

}

void block::Game::Render() {
    SDL_RenderClear(_renderer);
    SDL_SetRenderDrawColor(_renderer, 0, 191, 255, 0x00);
    SDL_RenderFillRect(_renderer, &_player);
    SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0x00, 0xFF);

    SDL_RenderPresent(_renderer);
}