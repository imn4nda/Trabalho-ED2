#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mediana (int* vet, int esq, int dir, int* comp, int* troca) {
    int meio = (esq + dir) / 2, aux;

    (*comp)++;
    if (vet[esq] > vet[meio]) {
        aux = vet[esq];
        vet[esq] = vet[meio];
        vet[meio] = aux;
        (*troca)++;
    }
    (*comp)++;
    if (vet[esq] > vet[dir]) {
        aux = vet[esq];
        vet[esq] = vet[dir];
        vet[dir] = aux;
        (*troca)++;
    }
    (*comp)++;
    if (vet[meio] > vet[dir]) {
        aux = vet[meio];
        vet[meio] = vet[dir];
        vet[dir] = aux;
        (*troca)++;
    }
    return vet[meio];
}

int particao (int* vet, int esq, int dir, int* comp, int* troca) {
    int i = esq, j = dir, aux, pivo = mediana(vet, esq, dir, comp, troca);
    
    while (i <= j) {
        (*comp)++;
        while (vet[i] < pivo && i < dir) {
            i++;
        }
        (*comp)++;
        while (vet[j] > pivo && j > esq) {
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
    return i;
}

void quickSortMediana (int* vet, int esq, int dir, int* comp, int* troca) {
    if (esq < dir) {
        int i = particao(vet, esq, dir, comp, troca);
        quickSortMediana(vet, esq, i-1, comp, troca);
        quickSortMediana(vet, i, dir, comp, troca);
    }
}

int main() {
    int vetor[] = {4, 2, 9, 3, 5, 7};
    int troca = 0, comp = 0;
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    double tempo;
    clock_t inicio, fim;

    inicio = clock();
    quickSortMediana(vetor, 0, tamanho - 1, &comp, &troca);
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