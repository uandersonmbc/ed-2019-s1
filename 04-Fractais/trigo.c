#include "../xpaint/xpaint.h"

void trigo(int x, int y, float ang, int tamanho, int cont){
    if(tamanho < 25)
        return;
    if(cont > 4)
        return;
    int xf = x + tamanho * xm_cos(ang);
    int yf = y - tamanho * xm_sin(ang);
    
    xs_color((XColor){92,64,51});
    xd_thick_line(x, y, xf, yf, 3);
    
    x_step("trigo");

    trigo(xf, yf, ang - 30, tamanho -25, cont + 1);
    trigo(xf, yf, 90, tamanho, cont + 1);
    trigo(xf, yf, ang + 30, tamanho -25, cont + 1);
         
}

int main(){
    int largura = 1200, altura = 1200;
    x_open(largura, altura); 
    x_clear(BLACK);
    float ang = 90;
    int x = largura / 2;
    int y = altura - 10;
    float tamanho = 150;
    trigo(x, y, ang, tamanho, 0);
    x_save("trigo");
    x_close();
    return 0;
}