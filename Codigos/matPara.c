#include <stdio.h>
#include <omp.h>
//Esse código esta realizando a multiplicação de matrizes quadradas
// usando openMP
#define SIZE 4096

void multiplicar_matrizes(int matrizA[SIZE][SIZE], int matrizB[SIZE][SIZE], int matrizC[SIZE][SIZE]) {
    #pragma omp parallel for
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int temp = 0;
            for (int k = 0; k < SIZE; k++) {
                temp += matrizA[i][k] * matrizB[k][j];
            }
            matrizC[i][j] = temp;
        }
    }
}

int main() {
    int matrizA[SIZE][SIZE];
    int matrizB[SIZE][SIZE];
    int matrizC[SIZE][SIZE];

    // Inicializa as matrizes com valores de exemplo
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrizA[i][j] = i + j;
            matrizB[i][j] = i - j;
        }
    }

    // Define o número de threads
    omp_set_num_threads(4);

    // Realiza a multiplicação das matrizes
    multiplicar_matrizes(matrizA, matrizB, matrizC);

    // Imprime a matriz resultante
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrizA[i][j]);
        }
        printf("\n");
    }

    return 0;
}
