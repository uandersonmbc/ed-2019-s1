#include <stdio.h>
#include <stdbool.h>
#include "xpaint.h"
#include "xvet.h"

#define SWAP(a, b, type) do{type SWAP = a; a = b; b = SWAP;}while(0)

void bubble(int vector[], int size){
    bool swapped=true;
    while (swapped){
        swapped = false;
        for (int i = 0; i < size-2; i++){
            xd_vet(vector, size, "ry", i+1, i);
            if (vector[i] > vector[i+1]){ 
                SWAP(vector[i], vector[i+1], int); 
                swapped = true; 
                xd_vet(vector, size, "ry", i, i+1);
            }
        }
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
    int vector[] = {3,2,3,4,5,6,7,5,9}; 
    int size = sizeof(vector)/sizeof(vector[0]);

    x_open(800, 500);
    xs_log("img/bubble/");

    bubble(vector, size);
    print_vector(vector, size);

    xd_vet(vector, size, "");
    x_close();
}