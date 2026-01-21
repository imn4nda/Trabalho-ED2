#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void criaHeap (int* vet, int ini, int fim, int* comp, int* troca) {
    int aux, j;
    aux = vet[ini]; //guarda o pai
    j = ini * 2 + 1;
    while (j <= fim) {
        if (j < fim) {
            (*comp)++;
            if (vet[j] < vet[j+1]) {
                j = j + 1;
            }
        }
        (*comp)++;
        if (aux < vet[j]) {
            vet[ini] = vet[j];
            (*troca)++; 
            ini = j;
            j = 2 * ini + 1;
        }
        else {
            j = fim + 1;
        }
    }
    vet[ini] = aux;
    (*troca)++; 
}

void heapSort (int* vet, int tam, int* troca, int* comp) {
    int aux, i;
    for (i = ((tam-1)/2); i >= 0; i--) {
        criaHeap(vet, i, tam-1, troca, comp);
        i = i - 1;
    }
    for (i = tam-1; i >= 1; i--) {
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        (*troca)++;
        criaHeap(vet, 0, i-1, troca, comp);
    }
}

int main() {
    int vetor[] = {4, 2, 9, 3, 5, 7};
    int troca = 0, comp = 0;
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    double tempo;
    clock_t inicio, fim;

    inicio = clock();
    heapSort(vetor, tamanho, &comp, &troca);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Vetor ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\nTempo execucao\tTrocas\tComparacoes\n");
    printf("%lf\t%d\t%d", tempo, troca, comp);

    return 0;
}