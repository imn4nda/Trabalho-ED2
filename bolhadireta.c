#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* bubbleSort(int* vet, int tam, int* troca, int* comp) {
    int i, j, aux;
    for (i = tam - 1; i >= 1; i--) {
        for (j = 0; j < i; j++) {
            (*comp)++;
            if (vet[j] > vet[j+1]) {
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
                (*troca)++;
            }
        }
    }
    return vet;
}

int main() {
    int vetor[] = {4, 2, 9, 3, 5, 7};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int trocas = 0, comp = 0;
    double tempo;
    clock_t inicio, fim;

    inicio = clock();
    int* vetorTrocado = bubbleSort(vetor, tamanho, &trocas, &comp);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Novo vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetorTrocado[i]);
    }
    printf("\nTempo Execucao\tTrocas\tComparacoes\n");
    printf("%lf\t%d\t%d", tempo, trocas, comp);
}