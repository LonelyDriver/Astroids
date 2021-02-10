#include "block_enemy.h"
#include "logging_manager.h"
#include "block_configuration.h"

block::Enemy::Enemy(SDL_Texture* texture, const Vector& position) :
Entity(texture, LogManager::GetLogger("Enemy"), Vector(SAUCERWIDTH/2, SAUCERHEIGHT/2), position) {
    const int angle = random_range(0, 2*block::PI);
    _velocity = Vector(std::cos(angle), std::sin(angle));
}

void block::Enemy::OnDestroy() {
    
}