#include "shellsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* shellSort (int* vet, int tam, long* troca, long* comp) {
    int h = 1, i, j, aux;
    while (h < tam) {
        h = 3*h + 1;
    }
    while (h >= 1) {
        for (i = h; i < tam; i++) {
            aux = vet[i];
            j = i - h;
            while (j >= 0 && aux < vet[j]) {
                (*comp)++;
                vet[j + h] = vet[j];
                (*troca)++;
                j = j - h;
            }
            if(j >= 0) {
                (*comp)++;
            }
            vet[j + h] = aux;
            (*troca)++;
        }
        h = h/3;
    }
    return vet;
}

