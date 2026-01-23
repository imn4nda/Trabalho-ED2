#include "bolhadireta.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int* vet, int tam, int* troca, int* comp) {
    int i, j, aux;
    for (i = tam - 1; i >= 1; i--) {
        for (j = 0; j < i; j++) {
            (*comp)++;
            if (vet[j] > vet[j+1]) {
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
                (*troca)++;
            }
        }
    }
}
