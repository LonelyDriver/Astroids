#include "block_entity.h"

block::Entity::Entity(
    SDL_Texture* texture,
    Logger logger,
    const Vector& dimension,
    const Vector& position) :
    _dimension(dimension),
    _position(position),
    _velocity(0,0),
    _logger(logger),
    _texture(texture),
    _alive(true) {

    }

bool block::Entity::IsAlive() const {
    return _alive;
}

void block::Entity::OnDestroy() {
    _alive = false;
}

const Vector block::Entity::GetPosition() const {
    return _position;
}

void block::Entity::SetPosition(const Vector& pos) {
    _position = pos;
}

const Vector block::Entity::GetDimension() const {
    return _dimension;
}