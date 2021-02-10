#ifndef _BLOCK_ENEMY_H
#define _BLOCK_ENEMY_H

#include "SDL2/SDL.h"
#include "block_entity.h"
#include "vector2d.h"

namespace block
{
    class Enemy : public Entity {
    public:
        Enemy(SDL_Texture* texture, const Vector& position);
        Enemy(const Enemy&) = delete;
        Enemy& operator=(const Enemy&) = delete;

        virtual int GetPoints() const = 0;
        virtual void OnDestroy();
    };
    
} // namespace block



#endif // _BLOCK_ENEMY_H