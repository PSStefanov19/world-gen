#include "map.h"
#include <raylib.h>

int main()
{
    srand(time(NULL));

    const int screenX = 1280;
    const int screenY = 720;
    int scaling = 1;
    InitWindow(screenX, screenY, "Title");
    SetTargetFPS(60);

    Map gameMap(screenX, screenY, 60, scaling);

    bool softwareRendererToggle = false;

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ENTER))
            gameMap.recreateMap();
        else if (IsKeyPressed(KEY_TAB))
            softwareRendererToggle = !softwareRendererToggle;

        BeginDrawing();
            ClearBackground(BLACK);
            gameMap.displayMap(softwareRendererToggle);
            DrawFPS(0, 0);
        EndDrawing();
    }

    CloseWindow();
}