#include "PlayerCircle.h"

PlayerCircle::PlayerCircle(int pos_x, int pos_y, int radius)
{
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    this->radius = radius;
    this->speed = 10;
    this->color = BLACK;
}

void PlayerCircle::TryMove(int screenwidth, int screenheight)
{
    if (IsKeyDown(KEY_D)) {
        if (pos_x+radius < screenwidth) {
            pos_x += speed;
        }
        else
        {
            color = YELLOW;
        }
    }
    else if (IsKeyDown(KEY_A) && pos_x-radius > 0) {
        pos_x -= speed;
    }
    else if (IsKeyDown(KEY_W) && pos_y-radius > 0) {
        pos_y -= speed;
    }
    else if (IsKeyDown(KEY_S) && pos_y+radius < screenheight) {
        pos_y += speed;
    }
}

Vector2 PlayerCircle::GetPosition()
{
    return Vector2{(float)pos_x, (float)pos_y};
}

int PlayerCircle::GetRadius()
{
    return this->radius;
}

CLITERAL(Color) PlayerCircle::GetColor() {
    return this->color;
}