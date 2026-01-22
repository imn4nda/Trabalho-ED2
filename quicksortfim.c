#include "quicksortfim.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int particao (int* vet, int esq, int dir, int* comp, int* troca) {
    int i = esq, j = dir-1, aux, pivo = vet[dir];

    while (i <= j) {
        (*comp)++;
        while (i < dir && vet[i] < pivo) {
            i++;
        }

        (*comp)++;
        while (j >= esq && vet[j] >= pivo) {
            j--;
        }
    
        if (i <= j) {
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            (*troca)++;
            i++;
            j--;
        }
    }
    aux = vet[i];
    vet[i] = vet[dir];
    vet[dir] = aux;
    (*troca)++;

    return i;
}

void quickSortFim (int* vet, int esq, int dir, int* comp, int* troca) {
    if (esq < dir) {
        int i = particao(vet, esq, dir, comp, troca);
        quickSortFim(vet, esq, i-1, comp, troca);
        quickSortFim(vet, i, dir, comp, troca);
    }
}