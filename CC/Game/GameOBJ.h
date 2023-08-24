#ifndef CLASSROOM_CORRUPTION_GAMEOBJ_H
#define CLASSROOM_CORRUPTION_GAMEOBJ_H

#endif //CLASSROOM_CORRUPTION_GAMEOBJ_H

#pragma once
#include "Game.h"
#include "TextureLoader.h"

class GameOBJ{

private:
    int x, y;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;

public:

    GameOBJ(const char* texSheet, int, int);
    ~GameOBJ();

    void Update();
    void Render();
};
