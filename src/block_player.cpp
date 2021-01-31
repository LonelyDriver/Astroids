#include "block_player.h"
#include "block_configuration.h"

block::Player::Player() :
_position(200,200),
_velocity(0,0),
_logger(LogManager::GetLogger("Player")),
_is_moving(false),
_rotation(0),
_angle(0),
_texture() {
}

void block::Player::Update(const Uint32 delta_time_ms) {
    float seconds = delta_time_ms / 1000.0;
    if(_rotation != 0) {
        _angle += (_rotation>0?1:-1)*180*seconds;
    }
    if(_is_moving) {
        float angle = _angle / 180 * block::PI - block::PI / 2;
        Vector acceleration(std::cos(angle), std::sin(angle));
        _velocity += acceleration;
    }
    _velocity *= 0.9;
    _velocity.SetLimit(10);
    _position += _velocity;
}

void block::Player::Moving(bool is_moving) {
    _is_moving = is_moving;
}

void block::Player::Rotation(int rotation) {
    if(rotation > 0) {
        _rotation = 1;
    }else if(rotation < 0) {
        _rotation = -1;
    }else {
        _rotation = 0;
    }
}

void block::Player::SetTexture(SDL_Texture* texture) {
    if(texture != nullptr) {
        _texture = texture;
        _logger->Debug("Texture set");
    }
}

void block::Player::Render(SDL_Renderer* renderer) const {
    SDL_Rect src_rect, dest_rect;

    dest_rect.w = block::SHIPWIDTH / 2;
    dest_rect.h = block::SHIPHEIGHT / 2;
    dest_rect.x = _position.GetX();
    dest_rect.y = _position.GetY();

    src_rect.w = block::SHIPWIDTH;
    src_rect.h = block::SHIPHEIGHT;
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
        _angle,
        NULL,
        SDL_RendererFlip::SDL_FLIP_NONE
    ) != 0) {
        _logger->Debug(STREAM("Could not render: "<<SDL_GetError()));
    }
}
