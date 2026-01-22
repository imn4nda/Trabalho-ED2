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
    int i, j, aux;
    int houveTroca;
    for(i = 0; i < tam - 1; i++) {
        houveTroca = 0;
        for(j = 0; j < tam - i - 1; j++) {
            (*comp)++;
            if (vet[j] > vet[j+1]) {
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
                (*troca)++;
                houveTroca = 1;
            }
        }
        if (!houveTroca) break;
    }
}

int encontrarMax(int* vet, int tam) {
    int max = vet[0];
    for(int i = 1; i < tam; i++) {
        if(vet[i] > max) max = vet[i];
    }
    return max;
}

void bucketSort (int* vet, int tam, int numeroBaldes, int* comp, int* troca) {
    Balde* baldes = (Balde*)malloc(numeroBaldes * sizeof(Balde));
    int i, j, indice;
    int max = encontrarMax(vet, tam);

    for(i = 0; i < numeroBaldes; i++) {
        baldes[i].topo = 0;
    }

    for(i = 0; i < tam; i++) {
        indice = vet[i] * numeroBaldes / (max + 1);
        if(indice >= numeroBaldes) indice = numeroBaldes - 1;
        baldes[indice].balde[baldes[indice].topo++] = vet[i];
    }

    for(i = 0; i < numeroBaldes; i++) {
        if(baldes[i].topo > 0){
            bubbleSortParada(baldes[i].balde, baldes[i].topo, troca, comp);
        }
    }

    indice = 0;
    for(i = 0; i < numeroBaldes; i++) {
        for(j = 0; j < baldes[i].topo; j++) {
            vet[indice++] = baldes[i].balde[j];
        }
    }

    free(baldes);
}

int main() {
    int vetor[] = {4, 2, 9, 3, 5, 7};
    int troca = 0, comp = 0;
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    double tempo;
    clock_t inicio, fim;

    inicio = clock();
    bucketSort(vetor, tamanho, 20, &comp, &troca);
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
