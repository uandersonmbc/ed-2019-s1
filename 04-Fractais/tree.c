#include "../xpaint/xpaint.h"

void tree(int x, int y, float ang, int tamanho, int esp){
    if(tamanho < 10)
        return;
    int xf = x + tamanho * xm_cos(ang);
    int yf = y - tamanho * xm_sin(ang);
    
    xs_color((XColor){92,64,51});
    xd_thick_line(x, y, xf, yf, esp);
    
    if((tamanho % 5) && esp > 3)esp-=10;
    
    if(tamanho <= 60){
        xs_color((XColor){33,94,33});
        xd_filled_circle(x, y, 7);
    }
    x_step("tree");

    tree(xf, yf, ang - 20, tamanho -8, esp);
    tree(xf, yf, ang + 20, tamanho -8, esp);     
}

int main(){
    int largura = 1200, altura = 1200;
    x_open(largura, altura); 
    x_clear(BLACK);
    float ang = 90;
    int x = largura / 2;
    int y = altura - 10;
    float tamanho = 100;
    tree(x, y, ang, tamanho, 32);
    x_save("tree");
    x_close();
    return 0;
}