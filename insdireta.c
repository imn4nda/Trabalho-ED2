#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int* insercaoDireta(int* vet, int tam, int* troca, int* comp) {
    int i, j, aux;
    for (i = 1; i < tam; i++) {
        aux = vet[i];
        j = i-1;
        while (j >= 0 && aux < vet[j]) {
            (*comp)++;
            (*troca)++;
            vet[j+1] = vet[j];
            j = j-1;
        }

        if (j >= 0) {
            (*comp)++;
        }
        if (j != (i-1)) {
            vet[j+1] = aux;
            (*troca)++;
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
    int* vetorNovo = insercaoDireta(vetor, tamanho, &trocas, &comp);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Novo vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetorNovo[i]);
    }
    printf("\nTempo Execucao\tTrocas\tComparacoes\n");
    printf("%lf\t%d\t%d", tempo, trocas, comp);
}