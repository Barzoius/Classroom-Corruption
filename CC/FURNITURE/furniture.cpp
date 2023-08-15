#include "furniture.h"

void DeskInit(){
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
}

void DeskQuit(){
    SDL_Quit();
    IMG_Quit();
}

DESK::DESK() {
    pos.x = 50;
    pos.y = 60;

    image = SDL_CreateRGBSurface(0, 120, 60, 32, 0, 0 ,0, 0);

    pos.w = image -> clip_rect.w;
    pos.h = image -> clip_rect.h;
    SDL_FillRect(image, nullptr, 0xffff00);
};

void DESK::draw(SDL_Surface *dest) {
    if(image != nullptr){
        SDL_BlitSurface(image, nullptr, dest, &pos);
    }
}

bool DESK::LoadDesk(std::string& filename) {

    if(image != nullptr){
        SDL_FreeSurface(image);
    }

    image = IMG_Load(filename.c_str());

    if(image != nullptr){
        return true;
    }
    else {
        return false;
    }
}

SDL_Rect DESK::getPos_y() const { return this -> pos;}

void DESK::setDeskTexture(SDL_Renderer *R) {
        this -> desk_texture = SDL_CreateTextureFromSurface(R, desk_image);

}
///---scrap it---///
