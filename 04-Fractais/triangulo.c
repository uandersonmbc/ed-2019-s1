#include "../xpaint/xpaint.h"

void fractal(float x, float y, float lado, float ang){
    if(lado < 5)
        return;
    int i;
    xs_color(RED);
    for(i = 0; i < 3; i++){
        fractal(x, y, lado / 2, ang);
        
        float x0 = x, y0 = y; /* salva x e y */
        x += lado * xm_cos(ang); /* translada x e y */
        y -= lado * xm_sin(ang);
        xs_color((XColor){xm_rand(0, 255), xm_rand(0, 255), xm_rand(0, 255)});
        xd_filled_triangle(x, y, x+1, y-1, x+2, y);      
        ang -= 120;
    }
}
int main(){
    x_open(400, 350);
    xs_font_size(30);
    fractal(25, 325, 350, 60);
    x_save("triangulo");
    x_close();
    return 0;
}