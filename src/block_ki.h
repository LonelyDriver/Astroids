#ifndef _BLOCK_KI
#define _BLOCK_KI
#include "vector2d.h"
#include "block_timer.h"

namespace block
{
    class IdleBrain {
    private:
        Timer _timer;
        float _angle;
    public:
        IdleBrain(const IdleBrain&) = delete;
        IdleBrain& operator=(const IdleBrain&) = delete;

        IdleBrain();

        const Vector Think();
        float GetAngle() const;
        
    };
} // namespace block



#endif // _BLOCK_KI