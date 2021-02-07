#include "block_hyperspace.h"
#include "block_configuration.h"
#include "block_exeption.h"

block::Hyperspace::Hyperspace(
    int hyperspace_count,
    Uint32 hyperspace_cooldown) :
_hyperspace_count(hyperspace_count),
_hyperspace_cooldown(hyperspace_cooldown),
_timer() {
    _timer.Start();
}

void block::Hyperspace::SetCount(int count) {
    _hyperspace_count = count;
}

void block::Hyperspace::SetCooldown(Uint32 cooldown_ms) {
    _hyperspace_cooldown = cooldown_ms;
}

int block::Hyperspace::GetCount() const {
    return _hyperspace_count;
}

Uint32 block::Hyperspace::GetCooldown() const {
    return _hyperspace_cooldown;
}
bool block::Hyperspace::Ready() const {
    return _timer.GetTicks() >= _hyperspace_cooldown;
}
const Vector block::Hyperspace::GoToHyperspace(int dimension_width, int dimension_height) {
    const auto delta_time = _timer.GetTicks();
    if(delta_time >= _hyperspace_cooldown && _hyperspace_count) {
        _timer.Start();
        return Vector(block::random_range(0, dimension_width), block::random_range(0, dimension_height));
    }
    throw BlockException(
        "Hyperspace not ready",
        __FILE__,
        __LINE__,
        block::BLOCK_ERROR::NOT_READY,
        __PRETTY_FUNCTION__
    );
}