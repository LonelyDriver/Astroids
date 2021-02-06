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
        borderControl(entitiy.get());
    }

    for(auto& entitiy : _event_entities) {
        entitiy->Update(time_ms);
        borderControl(entitiy.get());
    }
}

void block::World::borderControl(Entity* entity) {
    const auto& pos = entity->GetPosition();

    if(pos.GetX() < 0) {
        entity->SetPosition(Vector(_size.GetX(), _size.GetY() - pos.GetY()));
    }else if(pos.GetX() > _size.GetX()) {
        entity->SetPosition(Vector(0, _size.GetY() - pos.GetY()));
    }else if(pos.GetY() < 0) {
        entity->SetPosition(Vector(_size.GetX() - pos.GetX(), _size.GetY()));
    }else if(pos.GetY() > _size.GetY()) {
        entity->SetPosition(Vector(_size.GetX() - pos.GetX(), 0));
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