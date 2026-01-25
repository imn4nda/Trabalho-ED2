#include "heapsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void criaHeap (int* vet, int ini, int fim, long long* comp, long long* troca) {
    int aux, j;
    aux = vet[ini]; //guarda o pai
    j = ini * 2 + 1;
    while (j <= fim) {
        if (j < fim) {
            (*comp)++;
            if (vet[j] < vet[j+1]) {
                j = j + 1;
            }
        }
        (*comp)++;
        if (aux < vet[j]) {
            vet[ini] = vet[j];
            (*troca)++; 
            ini = j;
            j = 2 * ini + 1;
        }
        else {
            j = fim + 1;
        }
    }
    vet[ini] = aux;
    (*troca)++; 
}

void heapSort (int* vet, int tam, long long* troca, long long* comp) {
    int aux, i;
    for (i = ((tam-1)/2); i >= 0; i--) {
        criaHeap(vet, i, tam-1, comp, troca);
    }
    
    for (i = tam-1; i >= 1; i--) {
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        (*troca)++;
        criaHeap(vet, 0, i-1, comp, troca);
    }
}