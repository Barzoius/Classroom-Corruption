#pragma once
#include "Game.h"

class Map{
private:
    SDL_Rect src , dest;
    SDL_Texture* left_wall;
    SDL_Texture* right_wall;
    SDL_Texture* down_wall;
    SDL_Texture* up_wall;
    SDL_Texture* dark_bg;

    int map[20][25];

public:

    Map();
    ~Map();

    void LoadMap(int[20][25]);
    void DrawMap();
};




