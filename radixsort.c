#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void radixSort(int* vet, int tam, int* comp, int* troca) {
    int i;
    int* b;
    int maior = vet[0];
    int exp = 1;

    b = (int *)malloc(tam* sizeof(int));

    for (i = 0; i < tam; i++) {
        (*comp)++;
        if(vet[i] > maior){
            maior = vet[i];
        }
    }
    while(maior / exp > 0) {
        int bucket[10] = {0};
        for(i = 0; i < tam; i++) {
            bucket[(vet[i] / exp) % 10]++;
        }
        for(i = 1; i < 10; i++) {
            bucket[i] += bucket[i - 1];
        }
        for(i = tam - 1; i >= 0; i--) {
            b[--bucket[(vet[i] / exp) % 10]] = vet[i];
            (*troca)++;
        }
        for(i = 0; i < tam; i++) {
            vet[i] = b[i];
        }
        exp *= 10;
    }
    free(b);
}

int main() {
    int vetor[] = {4, 2, 9, 3, 5, 7, 8, 123, 5, 10, 100, 1000, 10000, 100000, 1000000, 2415};
    int troca = 0, comp = 0;
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    double tempo;
    clock_t inicio, fim;

    inicio = clock();
    radixSort(vetor, tamanho, &comp, &troca);
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
