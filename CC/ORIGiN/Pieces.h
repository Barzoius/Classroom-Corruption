=#ifndef CLASSROOM_CORRUPTION_PIECES_H
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
    ~Piece();


    void setRenderer(SDL_Renderer* ren);
    void setImage(const std::string& filename);
    void setTexture();

    void setSize(int width, int height);
    void setPosition(int x_coordinate, int y_coordinate , int z);

    int getPosition_X() const;
    int getPosition_Y() const;
    int getPosition_W() const;
    int getPosition_H() const;

    SDL_Rect getRect() const;

};

class Furniture : public Piece{};
//class Desk : public Furniture{};


class Player : public Piece{
private:

public:
    void MOVE(int x, int y);
};
