#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* shellSort (int* vet, int tam, int* troca, int* comp) {
    int h = 1, i, j, aux;
    while (h < tam) {
        h = 3*h + 1;
    }
    while (h >= 1) {
        for (i = h; i < tam; i++) {
            aux = vet[i];
            j = i - h;
            while (j >= 0 && aux < vet[j]) {
                (*comp)++;
                vet[j + h] = vet[j];
                (*troca)++;
                j = j - h;
            }
            vet[j + h] = aux;
            (*troca)++;
        }
        h = h/3;
    }
    return vet;
}

int main() {
    int vetor[] = {4, 2, 9, 3, 5, 7}, troca = 0, comp = 0;
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    double tempo;
    clock_t inicio, fim;

    inicio = clock();
    int* novoVetor = shellSort(vetor, tamanho, &troca, &comp);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Novo vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", novoVetor[i]);
    }
    printf("\nTempo execucao\tTrocas\tComparacoes\n");
    printf("%lf\t%d\t%d", tempo, troca, comp);
}

