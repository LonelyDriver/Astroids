#ifndef _BLOCK_PLAYER_H
#define _BLOCK_PLAYER_H
#include "SDL2/SDL.h"
#include "logging_manager.h"
#include "vector2d.h"
#include "block_actiontarget.h"


using  Vector = vector::Vector2D;

namespace block
{
    class Player : public ActionTarget<int> {
    private:
        Vector _position;
        Vector _velocity;
        Logger _logger;
        bool _is_moving;
        int _rotation;
        float _angle;
        SDL_Texture* _texture;
        ActionMap<int> _inputs;
    public:
        Player(const Player&) = delete;
        Player& operator=(const Player&) = delete;
        Player();

        enum class PlayerInputs : int {
            Up,
            Left,
            Right,
        };
        void SetDefaultInputs();

        void SetPosition(const Vector& vector);
        void Update(const Uint32 delta_time_ms);
        void ProcessEvents();
        bool IsMoving() const;
        void Moving(bool is_moving);
        void Rotation(int rotation);
        void Render(SDL_Renderer* renderer) const;
        void SetTexture(SDL_Texture* texture);
    };
    
} // namespace block



#endif //_BLOCK_PLAYER_H