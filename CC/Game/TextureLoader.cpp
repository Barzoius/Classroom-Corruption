#pragma once
#include "TextureLoader.h"

SDL_Texture* TextureLoader::LoadTexture(const char *filename) {

    SDL_Surface* surface = IMG_Load(filename);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, surface);
    SDL_FreeSurface(surface);

    return tex;
}

void TextureLoader::Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest) {
    SDL_RenderCopy(Game::renderer, tex, &src, & dest);
}
