#pragma once
#include "GameOBJ.h"


GameOBJ::GameOBJ(const char *texSheet, int x, int y) : x(x), y(y) {
    objTexture = TextureLoader::LoadTexture(texSheet);
}

GameOBJ::~GameOBJ() {}

void GameOBJ::Update() {
     x ++;
     y ++;

     srcRect.h = 100;
     srcRect.w = 100;
     srcRect.x = 0;
     srcRect.y = 0;

     destRect.y = y;
     destRect.x = x;
     destRect.w = srcRect.w * 2;
     destRect.h = srcRect.h * 2;
}

void GameOBJ::Render() {
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

