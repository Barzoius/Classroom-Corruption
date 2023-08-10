#ifndef CLASSROOM_CORRUPTION_TEXTURELOADER_H
#define CLASSROOM_CORRUPTION_TEXTURELOADER_H

#endif //CLASSROOM_CORRUPTION_TEXTURELOADER_H


#include "SDL.h"
#include "SDL_image.h"

class TextureLoader{
public:
    static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* ren);
};

