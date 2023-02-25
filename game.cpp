#include "raylib.h"
#include <iostream>
#include "playercircle.h"
#include "EnemyRectangle.h"
#include "MovingScreen.h"

int main()
{
    int width = 800;
    int height = 800;

    PlayerCircle player(25, 25, 20);
    EnemyRectangle enemy(400, 400, 50);
    MovingScreen screen(0, 0, width, height, 5.0f);

    SetTargetFPS(60);
    InitWindow(width, height, "Game");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // Move the player
        player.TryMove(screen);
        // Move the enemy
        enemy.TryMove(height);

        // Check if the player is moving left
        bool isMovingLeft = IsKeyDown(KEY_A);

        screen.Update(player.GetPosition().x, isMovingLeft);

        // Draw the screen and background
        screen.DrawBackground();
    
        // Draw the player and enemy
        DrawCircleV(player.GetPosition(), player.GetRadius(), player.GetColor());
        DrawRectangle(enemy.GetAxeX(), enemy.GetAxeY(), enemy.GetAxeLength(), enemy.GetAxeLength(), enemy.GetColor());

        EndDrawing();
    }

    CloseWindow();
    return 0;
}