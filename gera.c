#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
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

int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("Uso: %s -<opcao> <quantidade>\n", argv[0]);
        printf("Opcoes:\n");
        printf("\t-a: gera numeros aleatorios\n");
        printf("\t-c: gera numeros crescentes\n");
        printf("\t-d: gera numeros decrescentes\n");
        printf("\nExemplo: %s -c 5\n", argv[0]);
        return 1;
    }

    char* opcao = argv[1];
    int n = atoi(argv[2]);

    if(n <= 0) {
        printf("Erro: quantidade deve ser maior que zero\n");
        return 1;
    }

    if(strcmp(opcao, "-a") == 0) {
        geraAleatorio(n);
        printf("Arquivo 'entrada.txt' gerado com %d numeros aleatorios\n", n);
    }
    else if(strcmp(opcao, "-c") == 0) {
        geraCrescente(n);
        printf("Arquivo 'entrada.txt' gerado com %d numeros crescentes\n", n);
    }
    else if(strcmp(opcao, "-d") == 0) {
        geraDecrescente(n);
        printf("Arquivo 'entrada.txt' gerado com %d numeros decrescentes\n", n);
    }
    else {
        printf("Opcao invalida: %s\n", opcao);
        printf("Use -a, -c ou -d\n");
        return 1;
    }

    return 0;
}
