#include "quicksortmeio.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void particaoMediana(int* vet, int esq, int dir, int* i, int* j, long long* comp, long long* troca) {
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

void quickSortMediana(int* vet, int esq, int dir, long long* comp, long long* troca) {
    int i, j;
    
    if(esq < dir) {
        particaoMediana(vet, esq, dir, &i, &j, comp, troca);
        if(j > esq) {
            quickSortMediana(vet, esq, j, comp, troca);
        }
        if(i < dir) {
            quickSortMediana(vet, i, dir, comp, troca);
        }
    }
}