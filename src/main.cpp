#include "map.h"
#include <raylib.h>

int main()
{
    srand(time(NULL));

    const int screenY = 1280;
    const int screenX = 720;
    int scaling = 4;
    InitWindow(screenY, screenX, "Title");

    Map gameMap(screenX / scaling, screenY / scaling, 60);
    gameMap.recreateMap();

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ENTER))
            gameMap.recreateMap();

        BeginDrawing();
        ClearBackground(BLACK);
        gameMap.displayMap(scaling);
        EndDrawing();
    }

    CloseWindow();
}