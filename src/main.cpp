#include "map.h"
#include <raylib.h>
using namespace std;

int main()
{
    const int screenY = 800;
    const int screenX = 440;

    InitWindow(screenY, screenX, "Title");

    Map gameMap(220, 400, 60);
    gameMap.createMap();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);
        gameMap.displayMap();
        EndDrawing();
    }

    CloseWindow();
}