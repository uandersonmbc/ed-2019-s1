#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int MORTO = 0;

int direcao_andar(int direcao,int tamanho,int inicio){
    if(direcao == 1){
        int pos = (inicio + 1) % tamanho;
        return pos;
    }else{
        int pos = (inicio + (tamanho-1)) % tamanho;
        return pos;
    }

}

int achar_vivo(int vetor[],int tamanho,int escolhido, int direcao){
    int pos = direcao_andar(direcao, tamanho, escolhido);
    while(vetor[pos] == MORTO){
        pos = direcao_andar(direcao, tamanho, pos);
    }
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
    int npaticipantes=0, escolhido=0, fase=0;

    scanf("%d%d%d", &npaticipantes,&escolhido,&fase);

    int pessoas[npaticipantes];

    for (int i = 0; i < npaticipantes;i++){
            pessoas[i] = (i + 1) * fase;
            fase *= -1;
    }

    escolhido -= 1;

    int size = npaticipantes-1;

    printf("Escolhido: %d\n\n", escolhido);

    mostar_vivos(pessoas,npaticipantes,escolhido);
    
    for(int i = 0; i < size; i++){
        int direcao = pessoas[escolhido] > 0 ? 1 : -1;
        int andar = pessoas[escolhido] > 0 ? pessoas[escolhido] : -pessoas[escolhido];
        int morre = achar_vivo(pessoas, npaticipantes, escolhido, direcao);
        pessoas[morre] = MORTO;
        for(int i = 0; i < andar; i++){
            escolhido = achar_vivo(pessoas, npaticipantes, escolhido, direcao);
            printf("Escolhido - 2: %d\n", escolhido);
        }


        mostar_vivos(pessoas,npaticipantes,escolhido);

    }
}
