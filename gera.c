#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gera.h"

void geraAleatorio(int n) {
    FILE* arquivo = fopen("entrada.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        fprintf(arquivo, "%d\n", rand() % 1000000);

    }
    fclose(arquivo);
}

void geraCrescente(int n) {
    FILE* arquivo = fopen("entrada.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(arquivo, "%d\n", i);

    }
    fclose(arquivo);
}

void geraDecrescente(int n) {
    FILE* arquivo = fopen("entrada.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    for (int i = n; i >= 1; i--) {
        fprintf(arquivo, "%d\n", i);

    }
    fclose(arquivo);
}
