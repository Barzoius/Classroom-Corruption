#include "Game.h"
#include "Map.h"
#include "ECS.h"
#include "Components.h"
#include "Vector2D.h"

Map* map1;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;

auto& player(manager.addEntity());

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

    map1 = new Map();


    player.addComponent<TransformComponent>();
    player.addComponent<SpriteComponent>(R"(C:\Users\mecca\CLionProjects\ClassRoom_Corruption\CRT.png)");


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

    manager.refresh();
    manager.update();

    player.getComponent<TransformComponent>().position.Add(Vector2D(5, 0));

    if(player.getComponent<TransformComponent>().position.x > 100)
    {
        player.getComponent<SpriteComponent>().setTexutre(R"(C:\Users\mecca\CLionProjects\ClassRoom_Corruption\desk.png)");
    }
}

void Game::render()
{

    SDL_RenderClear(renderer);
    map1 -> DrawMap();
    manager.draw();

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
