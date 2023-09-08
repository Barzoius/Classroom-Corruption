#pragma once

#include "SDL.h"

class Collision
{
private:

public:

    static bool AABB(const SDL_Rect& rectA, const SDL_Rect& rectB);
};
