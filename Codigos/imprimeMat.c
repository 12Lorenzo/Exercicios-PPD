#include<stdio.h>

//Esse código esta ralizando o prencimento e impressão de uma matriz

#define SIZE 10

int main(){
    int matrizA[SIZE][SIZE];

   

    // Inicializa as matrizes com valores de exemplo
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrizA[i][j] = i + j;
        }
    } 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrizA[i][j]);
        }
        printf("\n");
    }
    return 0;
}
