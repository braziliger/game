#include "raylib.h"

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
        void TryMove(int screenwidth, int screenheight);
        Vector2 GetPosition();
        int GetRadius();
        CLITERAL(Color) GetColor();
};