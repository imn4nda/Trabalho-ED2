#include "balde.h"

void inicializarBalde(Balde* b) {
    b->topo = 0;
}

void inserirNoBalde(Balde* b, int valor) {
    if(b->topo < TAM) {
        b->balde[b->topo++] = valor;
    }
}

int obterElemento(Balde* b, int indice) {
    return b->balde[indice];
}

int tamanhoBaldes(Balde* b) {
    return b->topo;
}