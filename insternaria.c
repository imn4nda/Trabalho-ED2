#include "insternaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* insertionSortTer (int* vet, int tam, int* troca, int* comp) {
    int i, j, dir, esq, terco1, terco2, aux;

    for (i = 1; i < tam; i++) {
        aux = vet[i];
        esq = 0;
        dir = i;

        while (esq < dir) {
            terco1 = esq + (dir - esq) / 3;
            terco2 = dir - (dir - esq) / 3;

            (*comp)++;
            if (aux < vet[terco1]) {
                dir = terco1;
            }
            else {
                (*comp)++;
                if (aux > vet[terco2]) {
                    esq = terco2 + 1;
                }
                else {
                    esq = terco1 + 1;
                    dir = terco2;
                }
            }
        }
        for (j = i; j > esq; j--) {
            vet[j] = vet[j-1];
            (*troca)++;
        }
        vet[esq] = aux;
        (*troca)++;
    }
    return vet;
}