#pragma once

#include "Components.h"
#include "SDL.h"
#include "TextureLoader.h"


class SpriteComponent : public Component
{
private:
    TransformComponent *transform;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;

public:

    SpriteComponent() = default;

    explicit SpriteComponent(const char* path)
    {
        setTexutre(path);
    }

    void setTexutre(const char* path)
    {
        texture = TextureLoader::LoadTexture(path);
    }

    void init() override
    {
        transform = &entity -> getComponent<TransformComponent>();
        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 64;

        destRect.w = destRect.h = 64;
    }

    void update() override
    {
        destRect.x = (int)transform -> position.x;
        destRect.y = (int)transform -> position.y;

    }

    void draw() override
    {
        TextureLoader::Draw(texture, srcRect, destRect );
    }
};






