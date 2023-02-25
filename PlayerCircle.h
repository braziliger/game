#ifndef PLAYER_CIRCLE_H
#define PLAYER_CIRCLE_H

#include "raylib.h"

class MovingScreen; // forward declaration

class PlayerCircle {
private:
    int pos_x;
    int pos_y;
    int radius;
    int speed;
    CLITERAL(Color) color;
    int test;

public:
    PlayerCircle(int pos_x, int pos_y, int radius);
    void TryMove(MovingScreen& screen);
    Vector2 GetPosition();
    int GetRadius();
    CLITERAL(Color) GetColor();
};

#endif