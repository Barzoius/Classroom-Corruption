#pragma once

#include "ECS.h"
#include "TransformComp.h"
#include "SDL.h"

class TileComponent : public Component{
public:
    TransformComponent* transform;
    SpriteComponent* sprite;
    SDL_Rect tileRect;
    char* path;
    
    int tileID;

    TileComponent() = default;

    TileComponent(int x, int y, int w, int h, int id){
        tileRect.x = x;
        tileRect.y = y;
        tileRect.w = w;
        tileRect.h = h;
        tileID = id;
    }
};
