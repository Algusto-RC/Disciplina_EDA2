#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da árvore binária
typedef struct no {
   int chave;            // Valor armazenado no nó
   struct no *esq;       // Ponteiro para o filho à esquerda
   struct no *dir;       // Ponteiro para o filho à direita
} no;

// Função para encontrar o nó com o maior valor em uma árvore binária
no *maximo(no *r) {
    // Percorre os nós à direita até encontrar o nó mais à direita
    // (o maior valor em uma árvore binária de busca)
    while (r != NULL && r->dir != NULL) {
        r = r->dir; // Avança para o próximo nó à direita
    }
    return r; // Retorna o nó com o maior valor ou NULL se a árvore estiver vazia
}
