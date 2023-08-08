#ifndef CLASSROOM_CORRUPTION_PIECES_H
#define CLASSROOM_CORRUPTION_PIECES_H

#endif //CLASSROOM_CORRUPTION_PIECES_H


#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <cstring>
#include <iostream>
#include <vector>

class Piece{
private:
    SDL_Window* window{};
    SDL_Renderer* renderer{};
    SDL_Rect position{};
    SDL_Texture* texture{};
    SDL_Surface* image{};

public:
    void INIT();
    void QUIT();

    Piece();

};

class Furniture : public Piece{};
//class Desk : public Furniture{};


class Player : public Piece{};
