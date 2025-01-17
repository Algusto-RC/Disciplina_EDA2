#include <stdio.h>
#include <stdlib.h>

// Definição de uma estrutura de nó para representar uma árvore binária
typedef struct no{
    int chave;      // Valor armazenado no nó
    struct no *esq; // Ponteiro para o filho à esquerda
    struct no *dir; // Ponteiro para o filho à direita
} no;

// Função para inserir um valor x na árvore binária
no *inserir(no *r, int x) {
    if (r == NULL) { // Caso a árvore esteja vazia ou o nó esteja vazio
        no *novo = malloc(sizeof(no)); // Aloca memória para um novo nó
        novo->esq = novo->dir = NULL; // Inicializa os filhos do novo nó como NULL
        novo->chave = x; // Atribui o valor x à chave do novo nó
        return novo; // Retorna o novo nó, que será inserido na árvore
    }
    else if (x < r->chave) { // Se o valor x for menor que o valor armazenado no nó atual
        r->esq = inserir(r->esq, x); // Chama recursivamente para inserir na subárvore à esquerda
    }
    else if (x > r->chave) { // Se o valor x for maior que o valor armazenado no nó atual
        r->dir = inserir(r->dir, x); // Chama recursivamente para inserir na subárvore à direita
    }
    return r; // Retorna o nó atual (não modificado) após a inserção
}
