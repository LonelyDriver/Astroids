#ifndef _BLOCK_ENTITY_H
#define _BLOCK_ENTITY_H
#include "SDL2/SDL.h"
#include "logging_manager.h"
#include "vector2d.h"

using  Vector = vector::Vector2D;

namespace block
{
    class Entity {
    protected:
        Vector _dimension;
        Vector _position;
        Vector _velocity;
        Logger _logger;
        
        SDL_Texture* _texture;
        bool _alive;

    public:
        Entity(const Entity&) = delete;
        Entity& operator=(const Entity&) = delete;
        Entity(SDL_Texture* texture, Logger logger, const Vector& dimension, const Vector& position=Vector(500,350));
        virtual ~Entity() {}

        virtual bool IsAlive() const;
        virtual bool IsCollide(const Entity& other) const = 0;
        virtual void Update(Uint32 time_ms) = 0;
        virtual void Render(SDL_Renderer* renderer) const = 0;
        virtual void OnDestroy();

        virtual void ProcessEvents() = 0;
        const Vector GetPosition() const;
        void SetPosition(const Vector& pos);
        const Vector GetDimension() const;

    };
} // namespace block


#endif // _BLOCK_ENTITY_H