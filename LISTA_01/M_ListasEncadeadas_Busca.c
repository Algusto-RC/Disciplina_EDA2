#include <stdio.h>


typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *busca(celula *le, int x) {
    celula *aux = le->prox; 
    while (aux) {
        if (aux->dado == x) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

celula *busca_rec(celula *le, int x) {
    if (!le->prox) {
        return NULL;
    }
    celula *aux = le->prox;
    if (aux->dado == x) {
        return aux;
    }
    return busca_rec(aux, x);
}
