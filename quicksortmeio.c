#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void particao (int* vet, int esq, int dir, int* i, int* j, int* comp, int* troca) {
    *i = esq;
    *j = dir;
    int aux, pivo = vet[(*i+*j)/2];
    while (*i <= *j) {
        (*comp)++;
        while (vet[*i] < pivo && *i < dir) {
            (*i)++;
        }
        (*comp)++;
        while (vet[*j] > pivo && *j > esq) {
            (*j)--;
        }

        if (*i <= *j) {
            aux = vet[*i];
            vet[*i] = vet[*j];
            vet[*j] = aux;
            (*troca)++;
            (*i)++;
            (*j)--;
        }
    }
}

void quickSortMeio (int* vet, int esq, int dir, int* comp, int* troca) {
    int i, j;
    
    particao(vet, esq, dir, &i, &j, comp, troca);
    if (j > esq) {
        quickSortMeio(vet, esq, j, comp, troca);
    }
    if (i < dir) {
        quickSortMeio(vet, i, dir, comp, troca);
    }
}

int main() {
    int vetor[] = {4, 2, 9, 3, 5, 7};
    int troca = 0, comp = 0;
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    double tempo;
    clock_t inicio, fim;

    inicio = clock();
    quickSortMeio(vetor, 0, tamanho - 1, &comp, &troca);
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