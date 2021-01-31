#include "block_texture_loader.h"
#include "SDL2/SDL_image.h"

block::TextureLoader::TextureLoader() :
_texture() {

}

block::TextureLoader::~TextureLoader() {
    if(_texture != NULL) {
        free(_texture);
    }
}

void block::TextureLoader::Load(SDL_Renderer* renderer, const std::string& path) {
    SDL_Surface* surface = IMG_Load(path.c_str());
    if(surface == NULL){
        throw BlockException(
            std::string("Could not load file "+path).c_str(),
            __PRETTY_FUNCTION__,
            __LINE__,
            0,
            IMG_GetError()
        );
    }
    auto texture = SDL_CreateTextureFromSurface(renderer, surface);

    if(texture == NULL){
        throw BlockException(
            "Could not create texture from surface",
            __PRETTY_FUNCTION__,
            __LINE__,
            0,
            SDL_GetError()
        );
    }
    SDL_FreeSurface(surface);
    _texture = texture;
}

SDL_Texture* block::TextureLoader::Get() const {
    return _texture;
}