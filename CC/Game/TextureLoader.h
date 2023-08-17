#ifndef CLASSROOM_CORRUPTION_TEXTURELOADER_H
#define CLASSROOM_CORRUPTION_TEXTURELOADER_H

#endif //CLASSROOM_CORRUPTION_TEXTURELOADER_H

#pragma once
#include "Game.h"

struct TextureLoader{
    static SDL_Texture* LoadTexture(const char* filename);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};
