#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* selectionSort (int* vet, int tam, int* troca, int* comp) {
    int i, j, menor, aux;
    for (i = 0; i < tam - 1; i++) {
        menor = i;
        for (j = i + 1; j < tam; j++) {
            (*comp)++;
            if (vet[j] < vet[menor]) {
                menor = j;
            }
        }
        if (i != menor) {
            aux = vet[i];
            vet[i] = vet[menor];
            (*troca)++;
            vet[menor] = aux;
            (*troca)++;
        }
    }
    return vet;
}

int main() {
    int vetor[] = {4, 2, 9, 3, 5, 7}, troca = 0, comp = 0;
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    double tempo;
    clock_t inicio, fim;

    inicio = clock();
    int* novoVetor = selectionSort(vetor, tamanho, &troca, &comp);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Novo vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", novoVetor[i]);
    }
    printf("\nTempo execucao\tTrocas\tComparacoes\n");
    printf("%lf\t%d\t%d", tempo, troca, comp);
}
