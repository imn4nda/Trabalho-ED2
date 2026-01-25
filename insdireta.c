#include "insdireta.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void insercaoDireta(int* vet, int tam, long* troca, long* comp) {
    int i, j, aux;
    for (i = 1; i < tam; i++) {
        aux = vet[i];
        j = i-1;
        while (j >= 0 && aux < vet[j]) {
            (*comp)++;
            (*troca)++;
            vet[j+1] = vet[j];
            j = j-1;
        }

        if (j >= 0) {
            (*comp)++;
        }
        if (j != (i-1)) {
            vet[j+1] = aux;
            (*troca)++;
        }
    }
}