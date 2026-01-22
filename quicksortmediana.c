#include "quicksortmeio.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void particao(int* vet, int esq, int dir, int* i, int* j, int* comp, int* troca) {
    *i = esq;
    *j = dir;
    int aux, pivo = vet[(*i + *j) / 2];
    
    while(*i <= *j) {
        while(vet[*i] < pivo) {
            (*comp)++;
            (*i)++;
        }
        (*comp)++; 
        
        while(vet[*j] > pivo) {
            (*comp)++;
            (*j)--;
        }
        (*comp)++;
        
        if(*i <= *j) {
            if(*i != *j) {
                aux = vet[*i];
                vet[*i] = vet[*j];
                vet[*j] = aux;
                (*troca)++;
            }
            (*i)++;
            (*j)--;
        }
    }
}

void quickSortMeio(int* vet, int esq, int dir, int* comp, int* troca) {
    int i, j;
    
    if(esq < dir) {
        particao(vet, esq, dir, &i, &j, comp, troca);
        if(j > esq) {
            quickSortMeio(vet, esq, j, comp, troca);
        }
        if(i < dir) {
            quickSortMeio(vet, i, dir, comp, troca);
        }
    }
}