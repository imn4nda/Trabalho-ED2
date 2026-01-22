#include "selectionsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* selectionSort (int* vet, int tam, int* troca, int* comp) {
    int i, j, menor, aux;
    for (i = 0; i < tam - 1; i++) {
        menor = i;
        for (j = i + 1; j < tam; j++) {
            (*comp)++;
            if (vet[j] < vet[menor]) {
                menor = j;
            }
        }
        if (i != menor) {
            aux = vet[i];
            vet[i] = vet[menor];
            (*troca)++;
            vet[menor] = aux;
            (*troca)++;
        }
    }
    return vet;
}
