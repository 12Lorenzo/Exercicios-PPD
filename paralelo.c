#include <stdio.h>
#include <omp.h>

//Esse código esta realizando a multiplicação de
// matrizes quadradas usando openMP

int main() {
    int num_threads = 4;
    int my_id;
    int soma1 = 0, soma2 = 0;
    int a, b;
     /*
    //omp_set_num_threads(8);
    
    #pragma omp parallel num_threads(num_threads)
    {
        my_id = omp_get_thread_num();
        
        #pragma omp if (my_id % 2 == 0)
        {
            //printf("Thread %d executando código dentro do if.\n", my_id);
        }
        #pragma omp else
        {
            //printf("Thread %d executando código dentro do else.\n", my_id);
        }
    }
    */
    /*
    printf("SOma de 0 a 9 usando paralelismo:\n");
    omp_set_num_threads(10);
    #pragma omp parallel for
    for(int a = 0; a < 10; a++){
        //#pragma omp parallel for
        //for( b = 0; b < 10; b++){
            soma1 += a;
            //printf("Numero da thread: %d ", omp_get_thread_num());
            //printf("Soma: %d\n", soma);
        //}
    }

    for(int a = 0; a < 10; a++){
        //#pragma omp parallel for
        //for( b = 0; b < 10; b++){
            soma2 += a;
            //printf("Numero da thread: %d ", omp_get_thread_num());
            //printf("Soma: %d\n", soma);
        //}
    }

    printf("\nSoma paralela final: %d", soma1);
    printf("\nSOma sequencial final: %d", soma2);
    */
    /*
    omp_set_num_threads(10);
    #pragma omp parallel for
    for(int i = 0; i < 10; i++){
        printf("\nnumero da thread: %d interacao: %d", omp_get_thread_num(), i);
    }
    */
    int soma = 0;
   // #pragma omp parallel num_threads(20) private(soma)
   #pragma parallel for num_threads(20) atomic // reduction(+: soma)
   for(int i = 0; i <= 10; i++)
   {
        int a = 2;
       // printf("\nThread: %d quantidade de threads: %d", omp_get_thread_num(), omp_get_num_threads());
       soma += a;
       printf("Soma: %d\n", soma);
    }
     return 0;
}
