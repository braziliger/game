#include "PlayerCircle.h"
#include "raylib.h"
#include "MovingScreen.h"

PlayerCircle::PlayerCircle(int pos_x, int pos_y, int radius) {
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    this->radius = radius;
    this->speed = 15;
    this->color = GREEN;
}

void PlayerCircle::TryMove(MovingScreen& screen) {
    if (IsKeyDown(KEY_W)) {
        pos_y -= speed;
    }
    if (IsKeyDown(KEY_S)) {
        pos_y += speed;
    }
    if (IsKeyDown(KEY_A)) {
        pos_x -= speed;
        if (pos_x < screen.GetPositionX()) {
            pos_x = screen.GetPositionX();
        }
    }
    if (IsKeyDown(KEY_D)) {
        pos_x += speed;
        if (pos_x > screen.GetPositionX() + screen.GetScreenWidth() - radius * 2) {
            pos_x = screen.GetPositionX() + screen.GetScreenWidth() - radius * 2;
        }
    }

    screen.Update(pos_x, pos_x - screen.GetPositionX() > screen.GetScreenWidth() * 0.8f);
}




Vector2 PlayerCircle::GetPosition() {
    return Vector2{(float)pos_x, (float)pos_y};
}

int PlayerCircle::GetRadius() {
    return this->radius;
}

CLITERAL(Color) PlayerCircle::GetColor() {
    return this->color;
}