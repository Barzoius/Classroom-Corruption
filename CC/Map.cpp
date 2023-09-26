#include "Map.h"
#include "TextureLoader.h"

int LVL1[20][25] ={
        {0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,},
        {0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 0},
        {0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
        {0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
        {0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
        {0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
        {0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
        {0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
        {0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
        {0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
        {0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
        {0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
        {0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
        {0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
        {0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
        {0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
        {0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
        {0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
        {0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
        {0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,},
};

Map::Map() {

    down_wall= TextureLoader::LoadTexture(R"(C:\Users\mecca\CLionProjects\ClassRoom_Corruption\TILES\DOWN_WALL_TILE.png)");
    right_wall = TextureLoader::LoadTexture(R"(C:\Users\mecca\CLionProjects\ClassRoom_Corruption\TILES\RIGHT_WALL_TILE.png)");
    left_wall = TextureLoader::LoadTexture(R"(C:\Users\mecca\CLionProjects\ClassRoom_Corruption\TILES\LEFT_WALL_TILE.png)");
    up_wall = TextureLoader::LoadTexture(R"(C:\Users\mecca\CLionProjects\ClassRoom_Corruption\TILES\UP_WALL_TILE.png)");
    dark_bg = TextureLoader::LoadTexture(R"(C:\Users\mecca\CLionProjects\ClassRoom_Corruption\TILES\DARK_BLUE_BACKGROUND_TILE.png)");
    LoadMap(LVL1);

    src.x = src.y = 0;
    src.w = dest.w = 32;
    src.h = dest.h = 32;

    dest.x = dest.y = 0;

}

void Map::LoadMap(int arr[20][25]) 
{
    for(int row = 0; row < 20; row++)
    {
        for(int col = 0; col < 25; col++)
        {
            map[row][col] = arr[row][col];
        }
    }
}

void Map::DrawMap() {

    int type = 0;

    for(int row = 0; row < 20; row++){
        for(int col = 0; col < 25; col++){
            type = map[row][col];
            dest.x = col * 32;
            dest.y = row * 32;

            switch (type) {
                case 0:
                    TextureLoader::Draw(dark_bg, src, dest);
                    break;
                case 1:
                    TextureLoader::Draw(right_wall, src, dest);
                    break;
                case 2:
                    TextureLoader::Draw(left_wall, src, dest);
                    break;
                case 3:
                    TextureLoader::Draw(up_wall, src, dest);
                    break;
                case 4:
                    TextureLoader::Draw(down_wall, src, dest);
                    break;

                default:
                    break;
            }
        }
    }
}

