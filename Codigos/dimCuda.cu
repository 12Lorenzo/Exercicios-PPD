#include <stdio.h>
#include <cuda_runtime.h>

//Esse código exibe as dimensões maximas da placa de video,
// para a execução de operações em CUDA
int main() {
    int deviceID = 0;  // ID da GPU em uso
    cudaDeviceProp deviceProp;

    // Obter propriedades do dispositivo
    cudaGetDeviceProperties(&deviceProp, deviceID);

    printf("Dimensões máximas da grid:\n");
    printf("Eixo x: %d\n", deviceProp.maxGridSize[0]);
    printf("Eixo y: %d\n", deviceProp.maxGridSize[1]);
    printf("Eixo z: %d\n", deviceProp.maxGridSize[2]);

    return 0;
}
