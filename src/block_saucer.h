#ifndef _BLOCK_SAUCER_H
#define _BLOCK_SAUCER_H
#include "block_enemy.h"
#include "logging_manager.h"

namespace block {

    class Saucer : public Enemy {
    private:
        Logger _logger;
    public:
        Saucer(const Saucer&) = delete;
        Saucer& operator=(const Saucer&) = delete;
        Saucer(SDL_Texture* texture, const Vector& position, Logger logger);

        virtual bool IsCollide(const Entity& other) const override;
        virtual void Update(Uint32 time_ms) override;
        virtual void OnDestroy() override;
        virtual void Render(SDL_Renderer* renderer) const override;
        virtual int GetPoints() const override;
        virtual void ProcessEvents() override;
        
    };
}


#endif // _BLOCK_SAUCER_H