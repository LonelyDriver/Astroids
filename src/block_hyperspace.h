#ifndef _BLOCK_HYPERSPACE_H
#define _BLOCK_HYPERSPACE_H
#include "block_timer.h"
#include "vector2d.h"

namespace block {

    class Hyperspace {
    private:
        int _hyperspace_count;
        Uint32 _hyperspace_cooldown;
        Timer _timer;

    public:
        Hyperspace(int hyperspace_count, Uint32 hyperspace_cooldown);

        void SetCount(int count);
        void SetCooldown(Uint32 cooldown_ms);
        int GetCount() const;
        Uint32 GetCooldown() const;
        bool Ready() const;
        const Vector GoToHyperspace(int dimension_width, int dimension_height);

    };
}


#endif // _BLOCK_HYPERSPACE_H