#include "raylib.h"
#include <iostream>
#include <unistd.h>
#include "PlayerCircle.h"

int main() 
{
    int width = 800;
    int height = 800;

    PlayerCircle player = PlayerCircle(25, 25, 20);

    SetTargetFPS(60);
    InitWindow(width, height, "Game");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        player.TryMove(width, height);

        DrawCircleV(player.GetPosition(), player.GetRadius(), player.GetColor());
        EndDrawing();
    }
}