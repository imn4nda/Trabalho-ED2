#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100

typedef struct {
    int balde[TAM];
    int topo;
} Balde;

/*
baldes[j] → um balde
baldes[j].balde → o vetor interno do balde
baldes[j].topo → quantos elementos ele tem
*/

void bubbleSortParada (int* vet, int tam, int* troca, int* comp) {
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

void bucketSort (int* vet, int tam, int numeroBaldes, int* comp, int* troca) {
    int i, j, k;
    Balde baldes[numeroBaldes];
    for (i = 0; i < numeroBaldes; i++) {
        baldes[i].topo = 0;
        if (baldes[i].topo > 0) {
            bubbleSortParada(baldes[i].balde, baldes[i].topo, troca, comp);
        }
    }
    for (i = 0; i < tam; i++) {
        j = numeroBaldes;
        while (j > 0) {
            (*comp)++;
            if (vet[i] >= j*10) {
                baldes[j].balde[baldes[j].topo] = vet[i];
                baldes[j].topo = baldes[j].topo + 1;
            }
            j--;
        }
    }
    i = 0;
    for (j = 0; j < numeroBaldes; j++) {
        for (k = 0; k < baldes[j].topo; k++) {
            vet[i] = baldes[j].balde[k];
            (*troca)++;
            i++;
        }
    }
} 

int main() {
    int vetor[] = {4, 2, 9, 3, 5, 7};
    int troca = 0, comp = 0;
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    double tempo;
    clock_t inicio, fim;

    inicio = clock();
    bucketSort(vetor, tamanho - 1, 20, &comp, &troca);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Vetor ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\nTempo execucao\tTrocas\tComparacoes\n");
    printf("%lf\t%d\t%d\n", tempo, troca, comp);

    return 0;
}