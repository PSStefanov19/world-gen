#include "map.h"
#include <raylib.h>

// Stop warnings from raygui that stop compilation
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#pragma GCC diagnostic ignored "-Wenum-compare"

#define RAYGUI_IMPLEMENTATION
#include <extras/raygui.h>

#pragma GCC diagnostic pop

int main()
{
    srand(time(NULL));

    const int screenX = 600;
    const int screenY = 400;
    int scaling = 1;
    InitWindow(screenX, screenY, "Title");
    SetTargetFPS(60);
    float rChannel = 0.5;
    float gChannel = 0.5;
    float bChannel = 0.5;
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
            gameMap.displayMap(softwareRendererToggle, rChannel, gChannel, bChannel);
            DrawFPS(0, 0);
            rChannel = GuiSliderBar({0, 30, 100, 20}, "", "Red color channel", rChannel, 0, 1);
            gChannel = GuiSliderBar({0, 50, 100, 20}, "", "Blue color channel", gChannel, 0, 1);
            bChannel = GuiSliderBar({0, 70, 100, 20}, "", "Green color channel", bChannel, 0, 1);
        EndDrawing();
    }

    CloseWindow();
}