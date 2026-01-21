#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* insertionSortBin (int* vet, int tam, int* troca, int* comp) {
    int i, j, esq, dir, meio, aux;

    for (i = 1; i < tam; i++) {
        aux = vet[i];
        esq = 0;
        dir = i;
        while (esq < dir) {
            (*comp)++;
            meio = (esq + dir) / 2;
            if (vet[meio] <= aux) {
                esq = meio + 1;
            }
            else {
                dir = meio;
            }
        }
        for (j = i; j > esq; j--) {
            vet[j] = vet[j-1];
            (*troca)++;
        }
        vet[dir] = aux;
        (*troca)++;
    }
    return vet;
}

int main() {
    int vetor[] = {4, 2, 9, 3, 5, 7}, troca = 0, comp = 0;
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    double tempo;
    clock_t inicio, fim;

    inicio = clock();
    int* novoVetor = insertionSortBin(vetor, tamanho, &troca, &comp);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Novo vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", novoVetor[i]);
    }
    printf("\nTempo execucao\tTrocas\tComparacoes\n");
    printf("%lf\t%d\t%d", tempo, troca, comp);
}