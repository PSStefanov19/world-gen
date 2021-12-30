#include "map.h"
#include <raylib.h>

int main()
{
    srand(time(NULL));

    const int screenX = 1280;
    const int screenY = 720;
    int scaling = 1;
    InitWindow(screenX, screenY, "Title");

    Map gameMap(screenX / scaling, screenY / scaling, 60);

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