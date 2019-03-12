#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

const int MORTO = 0;

int achar_vivo(int vetor[],int tam,int esc){
    int pos = (1 + esc) % tam;
    while(vetor[pos] == MORTO){
        pos = (pos + 1) % tam;
    }
    return pos;
}

void mostar_vivos(int vetor[],int tam){
    bool primeiro = true;
    printf("[");
    for(int i = 0; i < tam; i++){
        if(vetor[i] != 0){
            if(primeiro){
                primeiro = false;
            }else{
                printf(" ");
            }
            printf("%d", vetor[i]);
        }
    }
    printf("]\n");
}
int main(){
    int npaticipantes, escolhido;
    scanf("%d%d", &npaticipantes,&escolhido);

    int pessoas[npaticipantes];

    for (int i = 0; i < npaticipantes;i++)
        pessoas[i]= i+1;
    mostar_vivos(pessoas,npaticipantes);
    int size = npaticipantes-1;
    escolhido -= 1;
    for(int i = 0; i < size; i++){
        int vai_morrer = achar_vivo(pessoas, npaticipantes, escolhido);
        pessoas[vai_morrer] = MORTO;
        escolhido = achar_vivo(pessoas, npaticipantes, vai_morrer);
        mostar_vivos(pessoas,npaticipantes);
    }
}
