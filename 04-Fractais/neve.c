#include "../xpaint/xpaint.h"

void neve(int x, int y, float tamanho){
    if(tamanho < 10) 
        return;
    int step = 360 / 5;
    int angulo = 45;
    for(int i = 0; i < 5; i++){
        int xf = x + tamanho * xm_cos(angulo);
        int yf = y - tamanho * xm_sin(angulo);
        XColor cor = (XColor){xm_rand(0, 255), xm_rand(0, 255), xm_rand(0, 255)};
        xs_color(cor);
        xd_thick_line(x, y, xf, yf, 4);
        x_step("neve");
        neve(xf, yf, tamanho / 2.5);
        angulo += step;
    }
}


int main(){
    int largura = 1000, altura = 1000;
    x_open(largura, altura);
    neve(largura/2, altura/2, 300);
    x_save("neve");
    x_close();
    return 0;
}