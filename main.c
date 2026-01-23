#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "bolhadireta.h"
#include "bolhacparada.h"
#include "bucketsort.h"
#include "heapsort.h"
#include "insbinaria.h"
#include "insdireta.h"
#include "insternaria.h"
#include "mergesort.h"
#include "quicksortfim.h"
#include "quicksortmediana.h"
#include "quicksortmeio.h"
#include "radixsort.h"
#include "selectionsort.h"
#include "shellsort.h"

int* lerArquivo(int* tamanho) {
    FILE* arquivo = fopen("entrada.txt", "r");
    if(arquivo == NULL) {
        printf("Erro ao abrir arquivo de entrada!\n");
        return NULL;
    }
    int count = 0;
    int temp;
    while(fscanf(arquivo, "%d", &temp) == 1) {
        count++;
    }
    rewind(arquivo);
    int* vetor = (int*)malloc(count * sizeof(int));
    for(int i = 0; i < count; i++) {
        fscanf(arquivo, "%d", &vetor[i]);
    }
    *tamanho = count;
    fclose(arquivo);
    return vetor;
}

void escreverArquivo(int* vetor, int tamanho) {
    FILE* arquivo = fopen("saida.txt", "w");
    if(arquivo == NULL) {
        printf("Erro ao criar arquivo de saida!\n");
        return;
    }
    
    for(int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d\n", vetor[i]);
    }
    
    fclose(arquivo);
}

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("Uso: %s <algoritmo>\n", argv[0]);
        printf("\nAlgoritmos disponiveis:\n");
        printf("  bolha             - Bubble Sort\n");
        printf("  bolhaparada       - Bubble Sort com criterio de parada\n");
        printf("  insercaodireta    - Insercao Direta\n");
        printf("  insercaobinaria   - Insercao Binaria\n");
        printf("  insercaoternaria  - Insercao Ternaria\n");
        printf("  shellsort         - Shell Sort\n");
        printf("  selecaodireta     - Selecao Direta\n");
        printf("  heapsort          - Heap Sort\n");
        printf("  quicksortcentro   - Quick Sort (pivo no centro)\n");
        printf("  quicksortfim      - Quick Sort (pivo no fim)\n");
        printf("  quicksortmediana  - Quick Sort (pivo mediana de 3)\n");
        printf("  mergesort         - Merge Sort\n");
        printf("  radixsort         - Radix Sort\n");
        printf("  bucketsort        - Bucket Sort\n");
        printf("\nO programa le de 'entrada.txt' e gera 'saida.txt'\n");
        return 1;
    }
    char* algoritmo = argv[1];
    int tamanho;
    int* vetor = lerArquivo(&tamanho);
    if(vetor == NULL) {
        return 1;
    }

    int comp = 0, troca = 0;
    double tempo;
    clock_t inicio, fim;

    inicio = clock();
    if(strcmp(algoritmo, "bolha") == 0) {
        bubbleSort(vetor, tamanho, &troca, &comp);
    }
    else if(strcmp(algoritmo, "bolhaparada") == 0) {
        bubbleSortParada(vetor, tamanho, &troca, &comp);
    }
    else if(strcmp(algoritmo, "insercaodireta") == 0) {
        insercaoDireta(vetor, tamanho, &troca, &comp);
    }
    else if(strcmp(algoritmo, "insercaobinaria") == 0) {
        insertionSortBin(vetor, tamanho, &troca, &comp);
    }
    else if(strcmp(algoritmo, "insercaoternaria") == 0) {
        insertionSortTer(vetor, tamanho, &troca, &comp);
    }
    else if(strcmp(algoritmo, "shellsort") == 0) {
        shellSort(vetor, tamanho, &troca, &comp);
    }
    else if(strcmp(algoritmo, "selecaodireta") == 0) {
        selectionSort(vetor, tamanho, &troca, &comp);
    }
    else if(strcmp(algoritmo, "heapsort") == 0) {
        heapSort(vetor, tamanho, &troca, &comp);
    }
    else if(strcmp(algoritmo, "quicksortcentro") == 0) {
        quickSortMeio(vetor, 0, tamanho - 1, &comp, &troca);
    }
    else if(strcmp(algoritmo, "quicksortfim") == 0) {
        quickSortFim(vetor, 0, tamanho - 1, &comp, &troca);
    }
    else if(strcmp(algoritmo, "quicksortmediana") == 0) {
        quickSortMediana(vetor, 0, tamanho - 1, &comp, &troca);
    }
    else if(strcmp(algoritmo, "mergesort") == 0) {
        mergeSort(vetor, 0, tamanho - 1, &comp, &troca);
    }
    else if(strcmp(algoritmo, "radixsort") == 0) {
        radixSort(vetor, tamanho, &comp, &troca);
    }
    else if(strcmp(algoritmo, "bucketsort") == 0) {
        int numeroBaldes = tamanho / 100;
        if(numeroBaldes < 10) numeroBaldes = 10;
        bucketSort(vetor, tamanho, numeroBaldes, &comp, &troca);
    }
    else {
        printf("Algoritmo '%s' nao reconhecido!\n", algoritmo);
        free(vetor);
        return 1;
    }
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    escreverArquivo(vetor, tamanho);
    printf("\n=== Resultados ===\n");
    printf("Algoritmo: %s\n", algoritmo);
    printf("Elementos: %d\n", tamanho);
    printf("Tempo: %.6f segundos\n", tempo);
    printf("Comparacoes: %d\n", comp);
    printf("Trocas: %d\n", troca);
    printf("\nArquivo 'saida.txt' gerado com sucesso!\n");
    
    free(vetor);
    return 0;
}