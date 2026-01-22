#ifndef BUCKETSORT_H
#define BUCKETSORT_H

#define TAM 100

typedef struct {
    int balde[TAM];
    int topo;
} Balde;

void bubbleSortParada (int* vet, int tam, int* troca, int* comp);
int encontrarMax(int* vet, int tam);
void bucketSort (int* vet, int tam, int numeroBaldes, int* comp, int* troca);

#endif