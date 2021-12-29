#include "map.h"
#include <raylib.h>
using namespace std;

int main()
{
    srand(time(NULL));
    
    const int screenY = 800;
    const int screenX = 440;

    InitWindow(screenY, screenX, "Title");

    Map gameMap(screenX / 1, screenY / 1, 60);
    gameMap.recreateMap();

    // BeginDrawing();
        // ClearBackground(BLACK);
        // gameMap.displayMap();
    // EndDrawing();

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ENTER))
            gameMap.recreateMap();

        BeginDrawing();
            ClearBackground(BLACK);
            gameMap.displayMap(1);
        EndDrawing();
    }

    CloseWindow();
}