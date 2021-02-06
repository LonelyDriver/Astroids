#ifndef _BLOCK_WORLD_H
#define _BLOCK_WORLD_H
#include <list>
#include <memory>
#include "vector2d.h"
#include "block_entity.h"
#include "logging_manager.h"

using  Vector = vector::Vector2D;

namespace block
{
    class World {
    private:
        std::list<std::unique_ptr<Entity>> _entities;
        std::list<std::unique_ptr<Entity>> _event_entities;
        Logger _logger;
        Vector _size;
    public:
        World(const World&) = delete;
        World& operator=(const World&) = delete;
        World(Logger logger, const Vector& size);
        ~World();

        void AddEntity(const std::unique_ptr<Entity> entity);
        void AddEventEntity(const std::unique_ptr<Entity> entity);
        void Clear();
        bool IsCollide(const Entity& other) const;
        int Population() const;
        const Vector& WorldDimension();
        void Update(Uint32 time_ms);
        void Render(SDL_Renderer* renderer);
        void ProcessEvents();


    };
    
} // namespace block


#endif // _BLOCK_WORLD_H