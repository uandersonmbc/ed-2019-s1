#include "../xpaint/xpaint.h"

void espiral(int x, int y, float ang, int tamanho){
    if(tamanho < 10)
        return;
    int xf = x + tamanho * xm_cos(ang);
    int yf = y - tamanho * xm_sin(ang);
    xs_color((XColor){xm_rand(0, 255), xm_rand(0, 255), xm_rand(0, 255)});
    xd_filled_rect(x-20, y-20, x+20, y+20);
    xd_thick_line(x, y, xf, yf, 10);
    x_step("espiral");
    espiral(xf, yf, ang - 75, tamanho - 30);   
}

int main(){
    int largura = 1000, altura = 1000;
    x_open(largura, altura); 
    x_clear(BLACK);
    float ang = 70;
    int x = 50;
    int y = altura - 300;
    float tamanho = altura - 400;
    espiral(x, y, ang, tamanho);
    x_save("espiral");
    x_close();
    return 0;
}