#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "xpaint.h"
#include "xvet.h"

#define SWAP(a, b, type) do{type SWAP = a; a = b; b = SWAP;}while(0)

void bubble(int vector[], int size){
    bool swapped=true;
    int total = size;
    while (swapped){
        swapped = false;
        for (int i = 0; i < total-1; i++){
            xs_partition(i, total-1);
            xd_vet(vector, size, "ry", i+1, i);
            if (vector[i] > vector[i+1]){ 
                SWAP(vector[i], vector[i+1], int); 
                swapped = true; 
                xd_vet(vector, size, "ry", i, i+1);
            }
        }
        total--;
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
    xs_log("img/bubble/");

    bubble(vector, size);
    print_vector(vector, size);

    xd_vet(vector, size, "");
    x_close();
}