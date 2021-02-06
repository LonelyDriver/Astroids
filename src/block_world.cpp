#include "block_world.h"

block::World::World(Logger logger, const Vector& size) :
_logger(logger),
_size(size) {

}

block::World::~World() {

}

void block::World::AddEntity(std::unique_ptr<Entity> entity) {
    _entities.emplace_back(std::move(entity));
}

void block::World::AddEventEntity(std::unique_ptr<Entity> entity) {
    _event_entities.emplace_back(std::move(entity));
}

void block::World::Clear() {
    for(auto it = _entities.begin(); it != _entities.end();) {
        _entities.erase(it);   
    }

    for(auto it = _event_entities.begin(); it != _event_entities.end();) {
        _event_entities.erase(it);   
    }
}

bool block::World::IsCollide(const Entity& other) const {
    return false;
}

int block::World::Population() const {
    auto pop = _event_entities.size();
    pop += _entities.size();
    return pop;
}

const Vector& block::World::WorldDimension() {
    return _size;
}

void block::World::Update(Uint32 time_ms) {
    for(auto& entitiy : _entities) {
        entitiy->Update(time_ms);
    }

    for(auto& entitiy : _event_entities) {
        entitiy->Update(time_ms);
    }
}

void block::World::Render(SDL_Renderer* renderer) {
    for(auto& entitiy : _entities) {
        entitiy->Render(renderer);
    }

    for(auto& entitiy : _event_entities) {
        entitiy->Render(renderer);
    }
}

void block::World::ProcessEvents() {
    for(auto& entitiy : _event_entities) {
        entitiy->ProcessEvents();
    }
}