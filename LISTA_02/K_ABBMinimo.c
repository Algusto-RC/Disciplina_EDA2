#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da árvore binária
typedef struct no {
   int chave;            // Valor armazenado no nó
   struct no *esq;       // Ponteiro para o filho à esquerda
   struct no *dir;       // Ponteiro para o filho à direita
} no;

// Função para encontrar o nó com o menor valor em uma árvore binária
no *minimo(no *r) {
    // Percorre os nós à esquerda até encontrar o nó mais à esquerda
    // (o menor valor em uma árvore binária de busca)
    while (r != NULL && r->esq != NULL) {
        r = r->esq; // Avança para o próximo nó à esquerda
    }
    return r; // Retorna o nó com o menor valor ou NULL se a árvore estiver vazia
}
