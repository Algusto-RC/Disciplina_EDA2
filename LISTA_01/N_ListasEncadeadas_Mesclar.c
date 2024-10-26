#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void mescla_listas(celula *l1, celula *l2, celula *l3) {
    celula *atual_l3 = l3; // Ponteiro para a cabeça da lista resultante
    atual_l3->prox = NULL; // Inicializa a lista l3

    // Enquanto houver elementos em l1 ou l2
    while (l1->prox != NULL && l2->prox != NULL) {
        if (l1->prox->dado <= l2->prox->dado) {
            atual_l3->prox = l1->prox; // Adiciona o elemento de l1 a l3
            l1->prox = l1->prox->prox; // Avança l1
        } else {
            atual_l3->prox = l2->prox; // Adiciona o elemento de l2 a l3
            l2->prox = l2->prox->prox; // Avança l2
        }
        atual_l3 = atual_l3->prox; // Avança em l3
    }

    // Conectar os restantes de l1, se existirem
    if (l1->prox != NULL) {
        atual_l3->prox = l1->prox;
    }

    // Conectar os restantes de l2, se existirem
    if (l2->prox != NULL) {
        atual_l3->prox = l2->prox;
    }

    // Finaliza a lista l3
    atual_l3->prox = NULL;
}

// Função para imprimir a lista
void imprime_lista(celula *lista) {
    celula *atual = lista->prox; // Pula o nó cabeça
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Função principal para testar a mescla
int main() {
    // Inicializa as listas
    celula *l1 = malloc(sizeof(celula));
    celula *l2 = malloc(sizeof(celula));
    celula *l3 = malloc(sizeof(celula));

    // Construindo a lista l1: 1 -> 7 -> 9 -> 10 -> NULL
    l1->prox = malloc(sizeof(celula)); l1->prox->dado = 1;
    l1->prox->prox = malloc(sizeof(celula)); l1->prox->prox->dado = 7;
    l1->prox->prox->prox = malloc(sizeof(celula)); l1->prox->prox->prox->dado = 9;
    l1->prox->prox->prox->prox = malloc(sizeof(celula)); l1->prox->prox->prox->prox->dado = 10;
    l1->prox->prox->prox->prox->prox = NULL;

    // Construindo a lista l2: 2 -> 3 -> 8 -> NULL
    l2->prox = malloc(sizeof(celula)); l2->prox->dado = 2;
    l2->prox->prox = malloc(sizeof(celula)); l2->prox->prox->dado = 3;
    l2->prox->prox->prox = malloc(sizeof(celula)); l2->prox->prox->prox->dado = 8;
    l2->prox->prox->prox->prox = NULL;

    // Mesclando as listas
    mescla_listas(l1, l2, l3);

    // Imprimindo a lista mesclada
    printf("Lista mesclada: ");
    imprime_lista(l3);

    // Libera memória (não necessário para a parte de mescla, mas é uma boa prática)
    free(l1);
    free(l2);
    free(l3);

    return 0;
}
