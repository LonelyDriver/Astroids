#ifndef _BLOCK_COLLISION_H
#define _BLOCK_COLLISION_H
#include "block_entity.h"

namespace block
{
    class Collision {
    public:
        Collision() = delete;
        Collision(const Collision&) = delete;
        Collision& operator=(const Collision&) = delete;

        static bool CircleTest(const Entity* first, const Entity* second) {
            return false;
        }
    };
    
} // namespace block


#endif // _BLOCK_COLLISION_H