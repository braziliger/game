    #include "MovingScreen.h"
    #include "raylib.h"
    #include <string>

    MovingScreen::MovingScreen(float x, float y, float w, float h, float s) {
        positionX = x;
        initialPositionX = x;
        positionY = y;
        screenWidth = w;
        screenHeight = h;
        speed = s;
        distanceTraveled = 0.0f;
        isMovingLeft = false; // initialize isMovingLeft to false
        
    }

    void MovingScreen::Update(float playerX, bool isMovingLeft) {
        this->isMovingLeft = isMovingLeft;

        if (isMovingLeft) {
            if (playerX < positionX) {
                positionX = playerX;
            }
        } else {
            if (playerX > positionX + screenWidth) {
                positionX = playerX - screenWidth;
            }
        }
        distanceTraveled = abs(positionX - initialPositionX);
    }

    void MovingScreen::DrawBackground() {
        ClearBackground(WHITE);
        DrawRectangle(0, 0, screenWidth, screenHeight, GRAY);

        std::string distanceStr = "Distance Traveled: " + std::to_string((int)distanceTraveled);
        DrawText(distanceStr.c_str(), 10, 10, 20, BLACK);
    }

    float MovingScreen::GetPositionX() const {
        return positionX;
    }

    float MovingScreen::GetPositionY() const {
        return positionY;
    }

    float MovingScreen::GetDistanceTraveled() const {
        return distanceTraveled;
    }

    float MovingScreen::GetScreenHeight() const {
        return screenHeight;
    }

    float MovingScreen::GetScreenWidth() const {
    return screenWidth;
}