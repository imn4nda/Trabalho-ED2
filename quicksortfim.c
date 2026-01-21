#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int particao (int* vet, int esq, int dir, int* comp, int* troca) {
    int i = esq, j = dir-1, aux, pivo = vet[dir];

    while (i <= j) {
        (*comp)++;
        while (i < dir && vet[i] < pivo) {
            i++;
        }

        (*comp)++;
        while (j >= esq && vet[j] >= pivo) {
            j--;
        }
    
        if (i <= j) {
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            (*troca)++;
            i++;
            j--;
        }
    }
    aux = vet[i];
    vet[i] = vet[dir];
    vet[dir] = aux;
    (*troca)++;

    return i;
}

void quickSortFim (int* vet, int esq, int dir, int* comp, int* troca) {
    if (esq < dir) {
        int i = particao(vet, esq, dir, comp, troca);
        quickSortFim(vet, esq, i-1, comp, troca);
        quickSortFim(vet, i, dir, comp, troca);
    }
}


int main() {
    int vetor[] = {4, 2, 9, 3, 5, 7};
    int troca = 0, comp = 0;
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    double tempo;
    clock_t inicio, fim;

    inicio = clock();
    quickSortFim(vetor, 0, tamanho - 1, &comp, &troca);
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