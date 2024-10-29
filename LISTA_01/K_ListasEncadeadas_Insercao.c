#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *le, int x) {
    celula *novo = malloc(sizeof(celula));
    if (novo == NULL) return;
    novo->dado = x;
    novo->prox = le->prox;
    le->prox = novo;
}

void insere_antes(celula *le, int x, int y) {
    celula *novo = malloc(sizeof(celula));
    if (novo == NULL) return;  
    novo->dado = x;

    celula *aux = le;

    while (aux->prox != NULL && aux->prox->dado != y) {
        aux = aux->prox;
    }

    novo->prox = aux->prox;
    aux->prox = novo;
}
