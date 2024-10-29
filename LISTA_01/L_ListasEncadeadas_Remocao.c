#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p) {
    if (p == NULL || p->prox == NULL) return 0; 

    celula *aux = p->prox; 
    p->prox = aux->prox;  
    int valor_removido = aux->dado; 
    free(aux);

    return valor_removido;
}

void remove_elemento(celula *le, int x) {
    celula *ant = le;
    celula *pro = le->prox;

    while (pro != NULL && pro->dado != x) {  
        ant = pro;
        pro = pro->prox;
    }
    
    if (pro != NULL) {  
        ant->prox = pro->prox; 
        free(pro);         
    }
}

void remove_todos_elementos(celula *le, int x) {
    celula *ant = le;
    celula *pro = le->prox;

    while (pro != NULL) {
        if (pro->dado == x) {
            ant->prox = pro->prox;
            celula *aux = pro;
            pro = pro->prox;
            free(aux);
        } else {
            ant = pro;
            pro = pro->prox;
        }
    }
}
