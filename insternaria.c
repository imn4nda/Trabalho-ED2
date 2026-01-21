#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* insertionSortTer (int* vet, int tam, int* troca, int* comp) {
    int i, j, dir, esq, terco1, terco2, aux;

    for (i = 1; i < tam; i++) {
        aux = vet[i];
        esq = 0;
        dir = i;

        while (esq < dir) {
            terco1 = esq + (dir - esq) / 3;
            terco2 = dir - (dir - esq) / 3;

            (*comp)++;
            if (aux < vet[terco1]) {
                dir = terco1;
            }
            else {
                (*comp)++;
                if (aux > vet[terco2]) {
                    esq = terco2 + 1;
                }
                else {
                    esq = terco1 + 1;
                    dir = terco2;
                }
            }
        }
        for (j = i; j > esq; j--) {
            vet[j] = vet[j-1];
            (*troca)++;
        }
        vet[esq] = aux;
        (*troca)++;
    }
    return vet;
}

int main() {
    int vetor[] = {4, 2, 9, 3, 5, 7}, troca = 0, comp = 0;
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    double tempo;
    clock_t inicio, fim;

    inicio = clock();
    int* novoVetor = insertionSortTer(vetor, tamanho, &troca, &comp);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Novo vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", novoVetor[i]);
    }
    printf("\nTempo execucao\tTrocas\tComparacoes\n");
    printf("%lf\t%d\t%d", tempo, troca, comp);
}