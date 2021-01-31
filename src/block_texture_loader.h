#ifndef _BLOCK_ResourceManager_H
#define _BLOCK_ResourceManager_H
#include <string>
#include "SDL2/SDL.h"
#include "block_exeption.h"

namespace block {

    class TextureLoader {
    private:
        SDL_Texture* _texture;
    public:
        TextureLoader(const TextureLoader&) = delete;
        TextureLoader& operator=(const TextureLoader&) = delete;
        TextureLoader();
        ~TextureLoader();

        void Load(SDL_Renderer* renderer, const std::string& path);
        SDL_Texture* Get() const;
    };

}

#endif // _BLOCK_ResourceManager_H