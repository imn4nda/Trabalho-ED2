#include "mergesort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intercalacao(int* vet, int ini, int meio, int fim, int* comp, int* troca) {
    int i = ini, j = meio + 1, k = 0;
    int Tmp[fim - ini + 1];
    
    while (i <= meio || j <= fim) {
        (*comp)++;
        if (i == meio + 1 || (j <= fim && vet[j] < vet[i])) {
            Tmp[k] = vet[j];
            (*troca)++;  
            j++;
        }
        else {
            Tmp[k] = vet[i];
            (*troca)++;
            i++;
        }
        k++;
    }
    
    for (i = ini, k = 0; i <= fim; i++, k++) {
        vet[i] = Tmp[k];
        (*troca)++;
    }
}

void mergeSort(int* vet, int ini, int fim, int* comp, int* troca) {
    if (ini < fim) {
        int meio = (ini + fim) / 2;
        mergeSort(vet, ini, meio, comp, troca);
        mergeSort(vet, meio+1, fim, comp, troca);
        intercalacao(vet, ini, meio, fim, comp, troca);
    }
}