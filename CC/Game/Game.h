#pragma once

#include "SDL2/SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>

class Game{
private:
    bool isRunning;
    SDL_Window* window;

public:

    static SDL_Renderer * renderer;

    Game();
    ~Game();


    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() { return isRunning; };

//    SDL_Renderer* getRenderer() const { return renderer;}
    SDL_Window* getWindow() const { return window;}

};
