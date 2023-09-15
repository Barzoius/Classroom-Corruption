#include "Game.h"
#include "Map.h"
#include "ECS/ECS.h"
#include "ECS/Components.h"
#include "Vector2D.h"
#include "Collision.h"

Map* map1;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

Manager manager;

auto& player(manager.addEntity());
auto& wall(manager.addEntity());

Game::Game(){}

Game::~Game(){}

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


    player.addComponent<TransformComponent>(0.0f, 0.0f, 64, 64, 2);
    player.addComponent<SpriteComponent>(R"(C:\Users\mecca\CLionProjects\ClassRoom_Corruption\CRT.png)");
    player.addComponent<KeyBoardContols>();
    player.addComponent<CollisionComponent>("player");

    wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
    wall.addComponent<SpriteComponent>(R"(C:\Users\mecca\CLionProjects\ClassRoom_Corruption\desk.png)");
    wall.addComponent<CollisionComponent>("wall");


}

void Game::handleEvents()
{

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

    if(Collision::AABB(player.getComponent<CollisionComponent>().collider,
                       wall.getComponent<CollisionComponent>().collider))
    {
        player.getComponent<TransformComponent>().scale = 1;
        player.getComponent<TransformComponent>().velocity * -1;
        std::cout<<"wall hit"<<std::endl;
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
