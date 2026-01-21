#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intercalacao (int* vet, int ini, int meio, int fim, int* comp) {
    int i = ini, j = meio + 1, k = 0;
    int Tmp[fim - ini + 1];
    while (i <= meio || j <= fim) {
        (*comp)++;
        if (i == meio + 1 || (vet[j] < vet[i] && j <= fim)) {
            Tmp[k] = vet[j]; //vetor temporario
            j++;
        }
        else {
            Tmp[k] = vet[i];
            i++;
        }
        k++;
    }
    for (i = ini, k = 0; i <= fim; i++, k++) {
        vet[i] = Tmp[k];
    }
}

int* mergeSort (int* vet, int ini, int fim, int* comp) {
    if (ini < fim) {
        int meio = (ini + fim) / 2;
        mergeSort(vet, ini, meio, comp);
        mergeSort(vet, meio+1, fim, comp);
        intercalacao(vet, ini, meio, fim, comp);
    }
    return vet;
}

int main() {
    int vetor[] = {4, 2, 9, 3, 5, 7};
    int troca = 0, comp = 0;
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    double tempo;
    clock_t inicio, fim;

    inicio = clock();
    int* vetorNovo = mergeSort(vetor, 0, tamanho - 1, &comp);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Vetor ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetorNovo[i]);
    }

    printf("\nTempo execucao\tTrocas\tComparacoes\n");
    printf("%lf\t%d\t%d\n", tempo, troca, comp);

    return 0;
}