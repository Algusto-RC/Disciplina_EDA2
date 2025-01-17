#include <stdio.h>
#include <stdlib.h>

// Definição de uma estrutura de nó para representar uma árvore binária
typedef struct no {
    int chave;      // Valor armazenado no nó
    struct no *esq; // Ponteiro para o filho à esquerda
    struct no *dir; // Ponteiro para o filho à direita
} no;

// Função para remover um valor x de uma árvore binária
no *remover(no *r, int x) {
    if (r == NULL) { // Caso base: se o nó for NULL, não há nada a fazer
        return NULL;
    }
    
    if (x < r->chave) { // Se o valor x for menor que o valor do nó atual
        r->esq = remover(r->esq, x); // Chama recursivamente a remoção na subárvore esquerda
    } else if (x > r->chave) { // Se o valor x for maior que o valor do nó atual
        r->dir = remover(r->dir, x); // Chama recursivamente a remoção na subárvore direita
    } else { // Quando o valor x é igual ao valor do nó atual (nó a ser removido)
        if (r->esq == NULL) { // Se o nó a ser removido não tem filho à esquerda
            no *temp = r->dir; // Armazena o filho à direita
            free(r); // Libera a memória do nó atual
            return temp; // Retorna o filho à direita, que substitui o nó removido
        } else if (r->dir == NULL) { // Se o nó a ser removido não tem filho à direita
            no *temp = r->esq; // Armazena o filho à esquerda
            free(r); // Libera a memória do nó atual
            return temp; // Retorna o filho à esquerda, que substitui o nó removido
        } else { // Caso o nó tenha dois filhos
            no *antecessor = r->esq; // O antecessor é o maior valor da subárvore esquerda
            no *pai_antecessor = r; // Ponteiro para o pai do antecessor

            // Encontra o maior valor da subárvore à esquerda
            while (antecessor->dir != NULL) {
                pai_antecessor = antecessor;
                antecessor = antecessor->dir;
            }

            r->chave = antecessor->chave; // Substitui a chave do nó a ser removido pela chave do antecessor

            // Remover o antecessor da subárvore à esquerda
            if (pai_antecessor->dir == antecessor) {
                pai_antecessor->dir = antecessor->esq; // O filho esquerdo do antecessor (se houver) substitui o antecessor
            } else {
                pai_antecessor->esq = antecessor->esq; // O filho esquerdo do antecessor (se houver) substitui o antecessor
            }

            free(antecessor); // Libera a memória do antecessor
        }
    }
    return r; // Retorna a raiz atualizada da árvore
}
