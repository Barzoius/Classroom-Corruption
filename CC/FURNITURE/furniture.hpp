#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class DESK{
private:
    SDL_Surface* image;
    SDL_Rect pos;
    SDL_Surface* desk_image;
    SDL_Texture* desk_texture;

public:


    DESK();

    void draw(SDL_Surface* dest);

    bool LoadDesk(std::string& filename);

    SDL_Rect getPos_y() const;

    SDL_Texture getDeskTexture() const;
    void setDeskTexture(SDL_Renderer* R);

};

class TEACHERS_DESK : public DESK{
private:

public:
    TEACHERS_DESK()= default;
};

void DeskInit();
void DeskQuit();

///---scrap it---///
