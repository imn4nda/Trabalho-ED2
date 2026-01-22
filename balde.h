#ifndef BALDE_H
#define BALDE_H

#define TAM 100

typedef struct {
    int balde[TAM];
    int topo;
} Balde;

void inicializarBalde(Balde* b);
void inserirNoBalde(Balde* b, int valor);
int obterElemento(Balde* b, int indice);
int tamanhoBaldes(Balde* b);

#endif