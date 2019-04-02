#include "../xpaint/xpaint.h"

void circulo(int x, int y, int raio){
    if(raio < 10)return;
    int ang = 45;
    int step = 360/6;
    for(int i = 0; i < 6; i++){
        xs_color((XColor){xm_rand(0, 255), xm_rand(0, 255), xm_rand(0, 255)});
        // xd_circle(x, y, raio);
        xd_filled_circle(x, y, raio/3);
        int xf = x + raio * xm_cos(ang);
        int yf = y - raio * xm_sin(ang);
        xs_color((XColor){xm_rand(0, 255), xm_rand(0, 255), xm_rand(0, 255)});
        // xd_circle(xf, yf, raio/3);
        xd_filled_circle(xf, yf, raio/3);
        circulo(xf, yf, raio/3);
        ang += step;
    }
}

int main(){
    int width = 1000, height = 1000;
    x_open(width, height);
    x_clear(BLACK);
    circulo(width/2, height/2, 300);
    x_save("circulo");
    x_close();
    return 0;
}