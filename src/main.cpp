#include "map.h"
#include <raylib.h>

int main()
{
    srand(time(NULL));

    const int screenX = 600;
    const int screenY = 400;
    int scaling = 1;
    InitWindow(screenX, screenY, "Title");
    SetTargetFPS(60);

    Map gameMap(screenX, screenY, 60, scaling);

    bool softwareRendererToggle = false;
    bool isZoomed = false;

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ENTER))
            gameMap.recreateMap();
        if (IsKeyPressed(KEY_TAB))
            softwareRendererToggle = !softwareRendererToggle;
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            gameMap.zoom(isZoomed);

        BeginDrawing();
            ClearBackground(BLACK);
            gameMap.displayMap(softwareRendererToggle);
            DrawFPS(0, 0);
        EndDrawing();
    }

    CloseWindow();
}