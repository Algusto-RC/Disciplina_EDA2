#include <stdio.h>
#include <stdlib.h>

// Estrutura que representa uma célula de uma lista encadeada
typedef struct celula {
    int dado; // Valor armazenado na célula
    struct celula *prox; // Ponteiro para a próxima célula
} celula;

// Função para remover o elemento logo após o nó fornecido
// Retorna 1 se conseguiu remover o elemento e 0 se não
int remove_depois(celula *p) {
    if (p == NULL || p->prox == NULL) { // Verifica se o nó é nulo ou se não há um próximo nó
        return 0; // Não pode remover, pois não existe elemento após p
    }
    celula *remover = p->prox; // A célula que será removida
    p->prox = remover->prox; // Faz o ponteiro p->prox apontar para o próximo nó do nó a ser removido
    free(remover); // Libera a memória da célula removida
    return 1; // Sucesso na remoção
}

// Função para remover a primeira ocorrência de um elemento x na lista
void remove_elemento(celula *le, int x) {
    celula *aux = le; // Auxiliar para percorrer a lista
    while (aux->prox != NULL && aux->prox->dado != x) { // Procura o elemento x
        aux = aux->prox; // Avança na lista até encontrar o elemento ou chegar ao fim
    }
    if (aux->prox != NULL) { // Se encontrou o elemento x
        celula *remover = aux->prox; // A célula que será removida
        aux->prox = remover->prox; // Faz o ponteiro da célula anterior apontar para a próxima célula
        free(remover); // Libera a memória da célula removida
    }
}

// Função para remover todas as ocorrências de um elemento x na lista
void remove_todos_elementos(celula *le, int x) {
    celula *aux = le; // Auxiliar para percorrer a lista
    while (aux->prox != NULL) { // Enquanto houver elementos após o atual
        if (aux->prox->dado == x) { // Se o próximo elemento for igual a x
            celula *remover = aux->prox; // A célula que será removida
            aux->prox = remover->prox; // Faz o ponteiro da célula anterior apontar para a próxima célula
            free(remover); // Libera a memória da célula removida
        } else {
            aux = aux->prox; // Caso contrário, avança para o próximo elemento
        }
    }
}
