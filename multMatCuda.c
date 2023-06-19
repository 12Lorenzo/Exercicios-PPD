#include <stdio.h>
#include <omp.h>

#define N 4096
#define M 4096
#define P 4096

__global__ void matrix_multiply(int* A, int* B, int* C) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;

    if (row < N && col < P) {
        int sum = 0;
        for (int i = 0; i < M; i++) {
            sum += A[row * M + i] * B[i * P + col];
        }
        C[row * P + col] = sum;
    }
}

void mostraMat(int *mat, int tam){
   int i, j;

   for(i = 0; i < tam; i++){
      for(j = 0; j < tam; j++){
         printf(mat[i][j]);
      }
  }

}

int main() {
    int* A;
    int* B;
    int* C;
    int* d_A;
    int* d_B;
    int* d_C;

    // Alocar memória para as matrizes na CPU
    A = (int*)malloc(N * M * sizeof(int));
    B = (int*)malloc(M * P * sizeof(int));
    C = (int*)malloc(N * P * sizeof(int));

    // Inicializar matrizes A e B com dados

    // Alocar memória para as matrizes na GPU
    cudaMalloc((void**)&d_A, N * M * sizeof(int));
    cudaMalloc((void**)&d_B, M * P * sizeof(int));
    cudaMalloc((void**)&d_C, N * P * sizeof(int));

    // Copiar dados da CPU para a GPU
    cudaMemcpy(d_A, A, N * M * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, B, M * P * sizeof(int), cudaMemcpyHostToDevice);

    // Definir tamanho dos blocos e grid
    dim3 blockSize(16, 16);
    dim3 gridSize((P + blockSize.x - 1) / blockSize.x, (N + blockSize.y - 1) / blockSize.y);

    // Chamar o kernel para a multiplicação de matrizes
    matrix_multiply<<<gridSize, blockSize>>>(d_A, d_B, d_C);

    // Copiar o resultado de volta da GPU para a CPU
    cudaMemcpy(C, d_C, N * P * sizeof(int), cudaMemcpyDeviceToHost);

    // Liberar memória na GPU
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    // Liberar memória na CPU
    mostraMat(&C, N );
    free(A);
    free(B);
    free(C);

    return 0;
}
