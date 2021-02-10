#include "block_saucer.h"
#include "block_configuration.h"

block::Saucer::Saucer(SDL_Texture* texture, const Vector& position, Logger logger) :
_logger(logger),
Enemy(texture, position)
{

}

void block::Saucer::Render(SDL_Renderer* renderer) const {
    SDL_Rect src_rect, dest_rect;

    dest_rect.w = _dimension.GetX();
    dest_rect.h = _dimension.GetY();
    dest_rect.x = _position.GetX();
    dest_rect.y = _position.GetY();

    src_rect.w = block::SAUCERWIDTH;
    src_rect.h = block::SAUCERHEIGHT;
    src_rect.x = 0;
    src_rect.y = 0;

    if(renderer == NULL) {
        _logger->Debug("Invalid renderer");
        return;
    }
    if(_texture == NULL) {
        _logger->Debug("Invalid texture");
        return;
    }

    if(SDL_RenderCopyEx(
        renderer, 
        _texture,
        &src_rect,
        &dest_rect, 
        NULL,
        NULL,
        SDL_RendererFlip::SDL_FLIP_NONE
    ) != 0) {
        _logger->Debug(STREAM("Could not render: "<<SDL_GetError()));
    }
}

int block::Saucer::GetPoints() const {

}
void block::Saucer::ProcessEvents() {

}

bool block::Saucer::IsCollide(const Entity& other) const {

}
void block::Saucer::Update(Uint32 time_ms) {
    // KI 
}
void block::Saucer::OnDestroy() {
    Enemy::OnDestroy();
}