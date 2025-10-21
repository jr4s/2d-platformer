#include "raylib.h"
#include "player.h"

int main(void) {
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "GAME");
    SetTargetFPS(60);

    Player player;
    InitPlayer(&player, 100, 100);  // Starting position

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        UpdatePlayer(&player, dt);

        BeginDrawing();
        ClearBackground(RAYWHITE);
		
        DrawPlayer(&player);

        EndDrawing(); 
    }

    CloseWindow();
    return 0;
}
