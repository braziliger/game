#include "raylib.h"
#include <stdio.h>

class EnemyRectangle {

    private:
        int axe_x;
        int axe_y;
        int axe_length;
        int speed;
        CLITERAL(Color) color;

    public:

        EnemyRectangle(int axe_x,int axe_y,int axe_length); 

        void TryMove(int screenheight);
        int GetAxeX() const;
        int GetAxeY() const;
        int GetAxeLength() const;
        int GetSpeed() const;

        CLITERAL(Color) GetColor() const;
        void SetAxeX(int new_axe_x);
        void SetAxeY(int new_axe_y);
        void SetAxeLength(int new_axe_length);
        void SetSpeed(int new_speed);
        void SetColor(CLITERAL(Color) new_color);




};
