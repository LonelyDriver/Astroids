#ifndef _BLOCK_PLAYER_H
#define _BLOCK_PLAYER_H
#include <memory>
#include "SDL2/SDL.h"
#include "logging_manager.h"
#include "vector2d.h"
#include "block_actiontarget.h"
#include "block_entity.h"
#include "block_world.h"
#include "block_hyperspace.h"


namespace block
{
    class Player : public Entity, ActionTarget<int> {
        static const Uint32 _shoot_cooldown = 500;
    private:
        bool _is_moving;
        int _rotation;
        float _angle;
        Uint32 _shoot_dt;
        Hyperspace _hyperspace;
        ActionMap<int> _inputs;
        std::shared_ptr<World> _world;
    public:
        Player(const Player&) = delete;
        Player& operator=(const Player&) = delete;
        Player(SDL_Texture* texture, std::shared_ptr<World> world, const Vector& position);

        enum class PlayerInputs : int {
            Up,
            Left,
            Right,
            Shoot,
            Hyperspace
        };

        virtual bool IsCollide(const Entity& other) const override; 
        virtual void Update(const Uint32 delta_time_ms) override;
        virtual void OnDestroy() override;
        virtual void ProcessEvents() override;
        virtual void Render(SDL_Renderer* renderer) const override;

        void HyperSpace();
        void Shoot();
        void SetDefaultInputs();
        void SetPosition(const Vector& vector);
        bool IsMoving() const;
        void Moving(bool is_moving);
        void Rotation(int rotation);
        void SetTexture(SDL_Texture* texture);
        const Vector& GetPosition();
    };
    
} // namespace block



#endif //_BLOCK_PLAYER_H