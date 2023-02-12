#include "BigBallsGame.h"
#include "raylib.h"

BigBallsGame::BigBallsGame() {}

BigBallsGame::BigBallsGame(int pos) 
{
    this->position = pos;
}

void BigBallsGame::TitleScreen() {
    const int screenWidth = 1000;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "big blue balls");\

    GameScreen currentScreen = WAIT;

    int frameCounter = 0;
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // UPDATE ----------------------
        switch(currentScreen)
        {
            case WAIT:
                frameCounter++;

                if (frameCounter > 120)
                {
                    currentScreen = BIG;
                    frameCounter = 0;
                }

                break;
            case BIG:
                frameCounter++;

                if (frameCounter > 120) 
                {
                    currentScreen = BLU;
                    frameCounter = 0;
                }
                break;
            case BLU:
                frameCounter++;

                if (frameCounter > 120) 
                {
                    currentScreen = BALLS;
                    frameCounter = 0;
                }
                break;
            case BALLS:
                frameCounter++;

                if (frameCounter > 120)
                {
                    currentScreen = TITLE;
                    frameCounter = 0;
                }
                break;
            case TITLE:
                if (IsKeyDown(KEY_ENTER)) {
                    // exit the LoadingScreen() method, start the level!
                    return;
                }
                break;
            default:
                break;
        }

        // DRAW -----------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch(currentScreen) 
        {
            case WAIT:
                DrawRectangle(0, 0, screenWidth, screenHeight, CLITERAL(Color) {0, 0, 0, (unsigned char)frameCounter*2});
                break;
            case BIG:
                DrawRectangle(0, 0, screenWidth, screenHeight, CLITERAL(Color) {0, 0, 0, (unsigned char)frameCounter*2});
                DrawText("BIG", screenWidth/4, screenHeight/8, 40, BLUE);
                break;
            case BLU:
                DrawRectangle(0, 0, screenWidth, screenHeight, CLITERAL(Color) {0, 0, 0, (unsigned char)frameCounter*2});
                DrawText("BIG", screenWidth/4, screenHeight/8, 40, BLUE);
                DrawText("BLUE", screenWidth/3, screenHeight/5, 55, BLUE);
                break;
            case BALLS:
                DrawRectangle(0, 0, screenWidth, screenHeight, CLITERAL(Color) {0, 0, 0, (unsigned char)frameCounter*2});
                DrawText("BIG", screenWidth/4, screenHeight/8, 40, BLUE);
                DrawText("BLUE", screenWidth/3, screenHeight/5, 55, BLUE);
                DrawText("BALLS", screenWidth/2, screenHeight/3, 65, BLUE);
                break;
            case TITLE:
                DrawRectangle(0, 0, screenWidth, screenHeight, GOLD);
                DrawText("BIG", screenWidth/4, screenHeight/8, 40, BLUE);
                DrawText("BLUE", screenWidth/3, screenHeight/5, 55, BLUE);
                DrawText("BALLS", screenWidth/2, screenHeight/3, 65, BLUE);
                DrawText("PRESS ENTER TO PLAY", 300, 700, 30, BLUE);
                break;
            default:
                break;
        }

        EndDrawing();
    }
}

void BigBallsGame::LoadLevelOne()
{
        // window dimensions
    int width = 1000;
    int height = 1000;
    //InitWindow(width, height, "death to circle");
    
    // circle coords
    int circle_r = 50;
    int circle_x = width/4;
    int circle_y = height/2;
    int circle_speed = 10;

    // circle edges
    int l_circle_x = circle_x - circle_r;
    int r_circle_x = circle_x + circle_r;
    int u_circle_y = circle_y - circle_r;
    int b_circle_y = circle_y - circle_r;

    // axe coords
    int axe_x = width/2;
    int axe_y = 0;
    int axe_len = 30;

    // axe edges
    int l_axe_x = axe_x;
    int r_axe_x = axe_x + axe_len;
    int u_axe_y = axe_y;
    int b_axe_y = axe_y + axe_len;

    int axe_direction = 10;

    bool collision = false;

    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (collision) {
            ClearBackground(BLACK);
            DrawText("DEAD", 400, 200, 50, RED);
        }
        else
        {
            // game logic begins here

            // update edges
            l_circle_x = circle_x - circle_r;
            r_circle_x = circle_x + circle_r;
            u_circle_y = circle_y - circle_r;
            b_circle_y = circle_y - circle_r;

            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_len;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_len;

            collision = 
                b_axe_y >= u_circle_y
                && u_axe_y <= b_circle_y
                && l_axe_x <= r_circle_x
                && r_axe_x >= l_circle_x;

            DrawCircle(circle_x, circle_y, circle_r, BLUE);
            DrawRectangle(axe_x, axe_y, axe_len, axe_len, BLACK);

            // move the axe
            axe_y += axe_direction;
            if (axe_y > height || axe_y < 0) {
                axe_direction *= -1;
            }

            if (IsKeyDown(KEY_D) && circle_x < width-circle_r) {
                circle_x += circle_speed;
            }
            else if (IsKeyDown(KEY_A) && circle_x > 0+circle_r) {
                circle_x -= circle_speed;
            }
            else if (IsKeyDown(KEY_W) && circle_y > 0+circle_r) {
                circle_y -= circle_speed;
            }
            else if (IsKeyDown(KEY_S) && circle_y < height-circle_r) {
                circle_y += circle_speed;
            }
            // game logic ends
        }

        EndDrawing();
    }
}