#include <stdio.h>
#include <stdlib.h> //srand, rand
#include <time.h> // time()

const char PAREDE = '#';
const char EMPTY = '=';

//left, up, right, down
int deltaL[] = {0, -1, 0, 1};
int deltaC[] = {-1, 0, 1, 0};
int lados = sizeof(deltaL)/sizeof(int); 
//int delta[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

void show(int nl, int nc, char mat[nl][nc]){
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            printf("%c", mat[l][c]);
        }
        puts("");
    }
}

int qtdvizinhos(int linha, int coluna, char matriz[linha][coluna], int l, int c){
    int qtd = 0;
    if(matriz[l-1][c] == EMPTY)
        qtd++;
    if(matriz[l+1][c] == EMPTY)
        qtd++;
    if(matriz[l][c-1] == EMPTY)
        qtd++;
    if(matriz[l][c+1] == EMPTY)
        qtd++;
    return qtd;
}

int criar_labirinto(int nl, int nc, char mat[nl][nc], int l, int c){
    if((l < 0) || (l >= nl) || (c < 0) || (c >= nc))
        return 0;
    if(mat[l][c] != PAREDE)
        return 0;
    if(qtdvizinhos(nl,nc,mat,l,c) > 1)
        return 0;
    mat[l][c] = EMPTY;
    int cont = 1;
    for(int i = 0; i < lados; i++){
        cont += criar_labirinto(nl, nc, mat, l + deltaL[i], c + deltaC[i]);
    }
    return cont;
}

int main(){
    srand(time(NULL));
    int nl = 0;
    int nc = 0;
    puts("Digite dimensoes da do labirinto");
    scanf("%d %d", &nl, &nc);

    char mat[nl][nc];
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            mat[l][c] = PAREDE;
        }
    }
    show(nl, nc, mat);    
    int total = criar_labirinto(nl, nc, mat, 1, 1);
    show(nl, nc, mat);
    printf("total de paredes quebradas: %d\n", total);
}
