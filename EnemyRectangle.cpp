#include "raylib.h"
#include "PlayerCircle.h"
#include "EnemyRectangle.h"

EnemyRectangle::EnemyRectangle(int axe_x, int axe_y, int axe_length) 
{
    this->axe_x = axe_x;
    this->axe_y = axe_y;
    this->axe_length = axe_length;
    this->speed = 15;
    this->color = BLACK;
}


void EnemyRectangle::TryMove(int screenheight)
{
    // Move the rectangle up or down based on its speed
    this->axe_y += this->speed;
    if (this->axe_y + this->axe_length > screenheight || this->axe_y < 0) {
        this->speed = -this->speed;
    }
}

int EnemyRectangle::GetAxeX() const
{
    return this->axe_x;
}

int EnemyRectangle::GetAxeY() const
{
    return this->axe_y;
}

int EnemyRectangle::GetAxeLength() const
{
    return this->axe_length;
}

int EnemyRectangle::GetSpeed() const
{
    return this->speed;
}

CLITERAL(Color) EnemyRectangle::GetColor() const
{
    return this->color;
}

void EnemyRectangle::SetAxeX(int new_axe_x)
{
    this->axe_x = new_axe_x;
}

void EnemyRectangle::SetAxeY(int new_axe_y)
{
    this->axe_y = new_axe_y;
}

void EnemyRectangle::SetAxeLength(int new_axe_length)
{
    this->axe_length = new_axe_length;
}

void EnemyRectangle::SetSpeed(int new_speed)
{
    this->speed = new_speed;
}

void EnemyRectangle::SetColor(CLITERAL(Color) new_color)
{
    this->color = new_color;
}
