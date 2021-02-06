#ifndef _BLOCK_PLAYER_H
#define _BLOCK_PLAYER_H
#include "SDL2/SDL.h"
#include "logging_manager.h"
#include "vector2d.h"
#include "block_actiontarget.h"
#include "block_entity.h"


using  Vector = vector::Vector2D;

namespace block
{
    class Player : public Entity, ActionTarget<int> {
    private:
        bool _is_moving;
        int _rotation;
        float _angle;
        Uint32 _shoot_cooldown;
        ActionMap<int> _inputs;
    public:
        Player(const Player&) = delete;
        Player& operator=(const Player&) = delete;
        Player(SDL_Texture* texture);

        enum class PlayerInputs : int {
            Up,
            Left,
            Right,
        };
        virtual bool IsCollide(const Entity& other) const override; 
        virtual void Update(const Uint32 delta_time_ms) override;
        virtual void OnDestroy() override;

        void SetDefaultInputs();
        void SetPosition(const Vector& vector);
        virtual void ProcessEvents() override;
        bool IsMoving() const;
        void Moving(bool is_moving);
        void Rotation(int rotation);
        virtual void Render(SDL_Renderer* renderer) const override;
        void SetTexture(SDL_Texture* texture);
        const Vector& GetPosition();
    };
    
} // namespace block



#endif //_BLOCK_PLAYER_H