#include "radixsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void radixSort(int* vet, int tam, long* comp, long* troca) {
    int i;
    int* b;
    int maior = vet[0];
    int exp = 1;

    b = (int *)malloc(tam* sizeof(int));

    for (i = 0; i < tam; i++) {
        (*comp)++;
        if(vet[i] > maior){
            maior = vet[i];
        }
    }
    while(maior / exp > 0) {
        int bucket[10] = {0};
        for(i = 0; i < tam; i++) {
            bucket[(vet[i] / exp) % 10]++;
        }
        for(i = 1; i < 10; i++) {
            bucket[i] += bucket[i - 1];
        }
        for(i = tam - 1; i >= 0; i--) {
            b[--bucket[(vet[i] / exp) % 10]] = vet[i];
            (*troca)++;
        }
        for(i = 0; i < tam; i++) {
            vet[i] = b[i];
        }
        exp *= 10;
    }
    free(b);
}
