#include "insbinaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSortBin (int* vet, int tam, int* troca, int* comp) {
    int i, j, esq, dir, meio, aux;

    for (i = 1; i < tam; i++) {
        aux = vet[i];
        esq = 0;
        dir = i;
        while (esq < dir) {
            (*comp)++;
            meio = (esq + dir) / 2;
            if (vet[meio] <= aux) {
                esq = meio + 1;
            }
            else {
                dir = meio;
            }
        }
        for (j = i; j > esq; j--) {
            vet[j] = vet[j-1];
            (*troca)++;
        }
        vet[dir] = aux;
        (*troca)++;
    }
}