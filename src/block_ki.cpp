#include "block_ki.h"
#include "block_configuration.h"

block::IdleBrain::IdleBrain() :
_timer(),
_angle(random_range(0, 360)) {
    _timer.Start();
}

/**
 * @brief std::sin/cos expect angle in radians
 * 
 * @return const Vector 
 */
const Vector block::IdleBrain::Think() {
    const auto delta_time = _timer.GetTicks();

    if(delta_time >= static_cast<Uint32>(random_range(2000, 5000))) {
        _angle += random_range(0, 360);
        _timer.Start();
    }
    float angle = _angle / 180 * block::PI - block::PI / 2;
    return Vector(std::cos(angle), std::sin(angle));

}

/**
 * @brief Saucer PNG has 180 degree offset
 * 
 * @return float 
 */
float block::IdleBrain::GetAngle() const {
    return _angle + 180;
}