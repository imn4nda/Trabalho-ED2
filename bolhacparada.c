#include "bolhacparada.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSortParada (int* vet, int tam, long long* troca, long long* comp) {
    int j, aux, indice;
    int mudou = 1;

    while (mudou) {
        mudou = 0;
        indice = tam - 1;
        for (j = 1; j < tam; j++) {
            (*comp)++;
            if (vet[j-1] > vet[j]) {
                aux = vet[j-1];
                vet[j-1] = vet[j];
                (*troca)++;
                vet[j] = aux;
                mudou = 1;
                indice = j;
            }
        }
        tam = indice;
    }
}
