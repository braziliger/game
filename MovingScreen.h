#ifndef MOVING_SCREEN_H
#define MOVING_SCREEN_H

class MovingScreen {
private:
    float positionX;
    float initialPositionX; // store the initial position of the screen
    float positionY;
    float screenWidth;
    float screenHeight;
    float speed;
    float distanceTraveled; // add distanceTraveled variable
    bool isMovingLeft; 
    
public:
    MovingScreen(float x, float y, float w, float h, float s);
    float GetScreenHeight() const;
    void Update(float playerPositionX, bool isMovingLeft);
    void DrawBackground();
    float GetPositionX() const;
    float GetPositionY() const;
    float GetDistanceTraveled() const;
    float GetScreenWidth() const; // add GetScreenWidth method
};

#endif