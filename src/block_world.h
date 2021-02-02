#ifndef _BLOCK_WORLD_H
#define _BLOCK_WORLD_H
#include <list>
#include <memory>

namespace block
{
    class World {
    private:
        std::list<Entity*> _entities;
        std::list<Entity*> _tmp_entities;
    };
    
} // namespace block


#endif // _BLOCK_WORLD_H