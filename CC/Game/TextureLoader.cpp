#include "TextureLoader.h"

SDL_Texture* TextureLoader::LoadTexture(const char *filename, SDL_Renderer *ren) {

    SDL_Surface* surface = IMG_Load(filename);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, surface);
    SDL_FreeSurface(surface);

    return tex;
}
