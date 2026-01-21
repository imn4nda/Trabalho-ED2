#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* bubbleSortParada (int* vet, int tam, int* troca, int* comp) {
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
    return vet;
}

int main() {
    int vetor[] = {4, 2, 9, 3, 5, 7};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int trocas = 0, comp = 0;
    double tempo;
    clock_t inicio, fim;

    inicio = clock();
    int* vetorTrocado = bubbleSortParada(vetor, tamanho, &trocas, &comp);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Novo vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetorTrocado[i]);
    }
    printf("\nTempo execucao\tTrocas\tComparacoes\n");
    printf("%lf\t%d\t%d", tempo, trocas, comp);
}