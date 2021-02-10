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
            const auto first_rect = first->GetDimension();
            const auto second_rect = second->GetDimension();

            float radius1 = (first_rect.GetX() + first_rect.GetY()) / 4;
            float radius2 = (second_rect.GetX() + second_rect.GetY()) / 4;
            float xd = first->GetPosition().GetX() - second->GetPosition().GetX();
            float yd = first->GetPosition().GetY() - second->GetPosition().GetY();

            return std::sqrt(xd * xd + yd * yd) <= radius1 + radius2;
        }
    };
    
} // namespace block


#endif // _BLOCK_COLLISION_H