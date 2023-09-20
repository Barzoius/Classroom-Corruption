#include "Pieces.h"


void Piece::INIT() {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
}
void Piece::QUIT() {
    SDL_Quit();
    IMG_Quit();
}


Piece::Piece() : image(nullptr), texture(nullptr) {}

Piece::~Piece() {
    if(texture != nullptr){
        SDL_DestroyTexture(texture);
        image = nullptr;
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

///--------------------------------SETTERS--------------------------------///

void Piece::setRenderer(SDL_Renderer *ren) {
    renderer = ren;
}

void Piece::setImage(const std::string& filename) {

    if(image != nullptr){
        SDL_FreeSurface(image);
    }
    IMG_Load(filename.c_str());
}

void Piece::setTexture() {

    if(image != nullptr){
        SDL_FreeSurface(image);
    }
    texture = SDL_CreateTextureFromSurface(renderer, image);
}

void Piece::setSize(int width, int height) {
    position.w = width;
    position.h = height;
}

void Piece::setPosition(int x, int y, int z) {
    position.x = x;
    position.y = y;
}


///--------------------------------GETTERS--------------------------------///

int Piece::getPosition_X() const { return position.x; }
int Piece::getPosition_Y() const { return position.y; }
int Piece::getPosition_W() const { return position.w; }
int Piece::getPosition_H() const { return position.h; }

SDL_Rect Piece::getRect() const { return position; }


///-----------------------------------------------------------------------///
