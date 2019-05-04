#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "xpaint.h"
#include "xvet.h"

#define SWAP(a, b, type) do{type SWAP = a; a = b; b = SWAP;}while(0)

void selection(int vector[], int size) { 
    int i, j, min, aux;
    for (i = 0; i < (size-1); i++){
        xs_partition(i, size-1);
        xd_vet(vector, size, "y", i);
        min = i;
        for (j = (i+1); j < size; j++) {
            xd_vet(vector, size, "yrb", i, min, j);
            if(vector[j] < vector[min]) 
                min = j;
        }
        aux = vector[i];
        vector[i] = vector[min];
        vector[min] = aux;
        xd_vet(vector, size, "y", i);
    }
}

void print_vector(int vector[], int size){ 
    int i; 
    printf("["); 
    for (i=0; i < size; i++) 
        printf("%d ", vector[i]); 
    printf("] \n"); 
} 

int main(){
    srand(1);
    int size = 20;
    int vector[size]; 

    for(int i = 0; i < size; i++)
        vector[i] = rand() % 191 + 10;

    x_open(800, 500);
    xs_log("img/selection/");

    selection(vector, size);
    print_vector(vector, size);

    xd_vet(vector, size, "");
    x_close();
}