#include "GameOBJ.h"
#include "Map.h"

GameOBJ* Player1;
GameOBJ* Player2;
Map* map1;

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{

}

Game::~Game()
{

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;

    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if (window)
        {
            std::cout << "WINDOW CREATED" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);

        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 27, 27, 27, 255);
            std::cout << "RENDERER CREATED" << std::endl;
        }

        isRunning = true;
    }
    else {
        isRunning = false;
    }

    Player2 = new GameOBJ(R"(C:\Users\mecca\CLionProjects\ClassRoom_Corruption\CRT.png)", 0, 0);
    Player1 = new GameOBJ(R"(C:\Users\mecca\CLionProjects\ClassRoom_Corruption\CRT.png)", 50, 50 );
    map1 = new Map();
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;

        default: break;
    }
}

void Game::update(){
    Player2->Update();
    Player1 ->Update();
//    map1 ->
}

void Game::render()
{

    SDL_RenderClear(renderer);
    map1 -> DrawMap();
    Player2 -> Render();
    Player1 -> Render();

    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);

    SDL_DestroyRenderer(renderer);

    SDL_Quit();
    IMG_Quit();

    std::cout << "GAME CLEANED" << std::endl;
}
