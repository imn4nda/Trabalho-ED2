#include <stdio.h>
#include <stdlib.h>
#include "bucketsort.h"
#include "balde.h"

void bubbleSortParadaInterno(int* vet, int tam, long* troca, long* comp) {
    int i, j, aux;
    int houveTroca;
    
    for(i = 0; i < tam - 1; i++) {
        houveTroca = 0;
        for(j = 0; j < tam - 1 - i; j++) {
            (*comp)++;
            if(vet[j] > vet[j+1]) {
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
                (*troca)++;
                houveTroca = 1;
            }
        }
        if(!houveTroca) break;
    }
}

int encontrarMaximo(int* vet, int tam) {
    int max = vet[0];
    for(int i = 1; i < tam; i++) {
        if(vet[i] > max) {
            max = vet[i];
        }
    }
    return max;
}

void bucketSort(int* vet, int tam, int numeroBaldes, long* comp, long* troca) {
    Balde* baldes = (Balde*)malloc(numeroBaldes * sizeof(Balde));
    int i, j, indice;
    int maxValor = encontrarMaximo(vet, tam);
    
    for(i = 0; i < numeroBaldes; i++) {
        inicializarBalde(&baldes[i]);
    }
    
    for(i = 0; i < tam; i++) {
        indice = (vet[i] * numeroBaldes) / (maxValor + 1);
        if(indice >= numeroBaldes) indice = numeroBaldes - 1;
        inserirNoBalde(&baldes[indice], vet[i]);
    }
    
    for(i = 0; i < numeroBaldes; i++) {
        int tamanho = tamanhoBaldes(&baldes[i]);
        if(tamanho > 0) {
            bubbleSortParadaInterno(baldes[i].balde, tamanho, troca, comp);
        }
    }
    
    indice = 0;
    for(i = 0; i < numeroBaldes; i++) {
        int tamanho = tamanhoBaldes(&baldes[i]);
        for(j = 0; j < tamanho; j++) {
            vet[indice++] = obterElemento(&baldes[i], j);
        }
    }
    
    free(baldes);
}