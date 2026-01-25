#include "quicksortfim.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int particaoFim(int* vet, int esq, int dir, long long* comp, long long* troca) {
    int pivo = vet[dir]; 
    int i = esq - 1;
    int aux;
    
    for(int j = esq; j < dir; j++) {
        (*comp)++;
        if(vet[j] <= pivo) {
            i++;
            if(i != j) {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
                (*troca)++;
            }
        }
    }
    
    i++;
    aux = vet[i];
    vet[i] = vet[dir];
    vet[dir] = aux;
    (*troca)++;
    
    return i;
}

void quickSortFim(int* vet, int esq, int dir, long long* comp, long long* troca) {
    if(esq < dir) {
        int pivo = particaoFim(vet, esq, dir, comp, troca);
        quickSortFim(vet, esq, pivo - 1, comp, troca);
        quickSortFim(vet, pivo + 1, dir, comp, troca);
    }
}