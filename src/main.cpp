#include "map.h"
#include <raylib.h>

int main()
{
    srand(time(NULL));
    
    const int screenY = 1280;
    const int screenX = 720;

    InitWindow(screenY, screenX, "Title");

    Map gameMap(screenX / 4, screenY / 4, 60);
    gameMap.recreateMap();

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ENTER))
            gameMap.recreateMap();

        BeginDrawing();
            ClearBackground(BLACK);
            gameMap.displayMap(4);
        EndDrawing();
    }

    CloseWindow();
}