#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "xpaint.h"
#include "xvet.h"

#define SWAP(a, b, type) do{type SWAP = a; a = b; b = SWAP;}while(0)

void insertion(int vector[], int size){

    int escolhido, j;

    for (int i = 1; i < size; i++){
		escolhido = vector[i];
		j = i - 1;
		xs_partition(i, size-1);
        xd_vet(vector, size, "y", i);
		while ((j >= 0) && (vector[j] > escolhido)){
			vector[j + 1] = vector[j];
            xd_vet(vector, size, "yr", i,j);
			j--;
		}
		
		vector[j + 1] = escolhido;
        xd_vet(vector, size, "yr", j + 1,i);
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
    xs_log("img/insertion/");

    insertion(vector, size);
    print_vector(vector, size);

    xd_vet(vector, size, "");
    x_close();
}