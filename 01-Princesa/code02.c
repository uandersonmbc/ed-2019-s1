#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int MORTO = 0;

int procurar_vivo(int vet[],int size,int inicio,int direcao){
    int pos = 0;
    if(direcao == 1)
        pos = (inicio + direcao) % size;
    else
        pos = (inicio + size - 1) % size;

    while(vet[pos] == MORTO)
        if(direcao == 1)
            pos = (pos + direcao) % size;
        else
            pos = (pos + size - 1) % size;
    return pos;
}

void mostar_vivos(int vetor[],int tam,int esc){
    bool primeiro = true;
    printf("[");
    for(int i = 0; i < tam; i++){
        if(vetor[i] != 0){
            if(primeiro){
                primeiro = false;
            }else{
                printf(" ");
            }
            if(i == esc){
                if(vetor[i] > 0){
                    printf("%d", vetor[i]);
                    printf(">");
                }else{
                    printf("<");
                    printf("%d", vetor[i]);
                }
            }else{
                printf("%d", vetor[i]);
            }
        }
    }
    printf("]\n");
}

int main(){

    int N = 1, E = 0, fase = 1;
    scanf("%d%d%d", &N,&E,&fase);
    int size = N;
    int saltos = 0;
    int dir = 0;
    int vet[size];
    for(int i = 0; i < size; i++){
        vet[i] = (i + 1) * fase;
        fase *= -1;
    }
    mostar_vivos(vet,size,E);
    for(int i = 0; i < size-1; i++){
        dir = vet[E] > 0 ? 1 : -1;
        saltos = vet[E] > 0 ? vet[E] : -vet[E];

        int morrer = procurar_vivo(vet, size, E, dir);

        vet[morrer] = MORTO;
        printf("%d %d %d\n",dir, saltos, morrer);
        getchar();
        for(int j = 0; j < saltos; j++)
            morrer = procurar_vivo(vet, size, morrer, dir);
        E = morrer;
        mostar_vivos(vet,size,E);
    }
    return 0;
}