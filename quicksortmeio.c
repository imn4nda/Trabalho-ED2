#include "quicksortmeio.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void particaoMeio(int* vet, int esq, int dir, int* i, int* j, long long* comp, long long* troca) {
    *i = esq;
    *j = dir;
    int aux, pivo = vet[(*i+*j)/2];
    while (*i <= *j) {
        (*comp)++;
        while (vet[*i] < pivo && *i < dir) {
            (*i)++;
        }
        (*comp)++;
        while (vet[*j] > pivo && *j > esq) {
            (*j)--;
        }

        if (*i <= *j) {
            aux = vet[*i];
            vet[*i] = vet[*j];
            vet[*j] = aux;
            (*troca)++;
            (*i)++;
            (*j)--;
        }
    }
}

void quickSortMeio (int* vet, int esq, int dir, long long* comp, long long* troca) {
    int i, j;
    
    particaoMeio(vet, esq, dir, &i, &j, comp, troca);
    if (j > esq) {
        quickSortMeio(vet, esq, j, comp, troca);
    }
    if (i < dir) {
        quickSortMeio(vet, i, dir, comp, troca);
    }
}