#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da árvore
typedef struct no {
    int dado;          // Valor armazenado no nó
    struct no *esq;    // Ponteiro para o filho esquerdo
    struct no *dir;    // Ponteiro para o filho direito
} no;

// Estrutura para implementar uma pilha
typedef struct stack {
    no **data;         // Vetor que armazena os ponteiros para os nós
    int topo;          // Índice do topo da pilha
    int capacidade;    // Capacidade máxima da pilha
} stack;

// Função para criar uma pilha
stack *criar_pilha(int capacidade) {
    stack *pilha = (stack *)malloc(sizeof(stack));           // Aloca memória para a estrutura da pilha
    pilha->data = (no **)malloc(capacidade * sizeof(no *));  // Aloca memória para o vetor de ponteiros
    pilha->topo = -1;                                        // Inicializa o topo como vazio
    pilha->capacidade = capacidade;                         // Define a capacidade máxima da pilha
    return pilha;
}

// Verifica se a pilha está vazia
int esta_vazia(stack *pilha) {
    return pilha->topo == -1; // Retorna 1 (verdadeiro) se o topo for -1
}

// Empilha um nó na pilha
void empilhar(stack *pilha, no *n) {
    if (pilha->topo + 1 < pilha->capacidade) {
        pilha->data[++pilha->topo] = n; // Incrementa o topo e armazena o nó
    }
}

// Desempilha um nó da pilha
no *desempilhar(stack *pilha) {
    if (esta_vazia(pilha)) return NULL; // Retorna NULL se a pilha estiver vazia
    return pilha->data[pilha->topo--];  // Retorna o nó do topo e decrementa o índice do topo
}

// Libera a memória alocada para a pilha
void liberar_pilha(stack *pilha) {
    free(pilha->data); // Libera o vetor de ponteiros
    free(pilha);       // Libera a estrutura da pilha
}

// Função para realizar o percurso em ordem (não recursivo)
void em_ordem(no *raiz) {
    stack *pilha = criar_pilha(100); // Cria uma pilha com capacidade suficiente
    no *atual = raiz;                // Inicia o percurso a partir da raiz

    // Percorre a árvore em ordem
    while (atual != NULL || !esta_vazia(pilha)) {
        // Navega para a subárvore esquerda até alcançar um nó nulo
        while (atual != NULL) {
            empilhar(pilha, atual);  // Armazena o nó atual na pilha
            atual = atual->esq;      // Move para o filho esquerdo
        }

        // Processa o nó no topo da pilha
        atual = desempilhar(pilha);
        printf("%d ", atual->dado);  // Imprime o valor do nó

        // Move para o filho direito
        atual = atual->dir;
    }

    liberar_pilha(pilha); // Libera a memória alocada para a pilha
}

// Função auxiliar para criar um novo nó
no *criar_no(int dado) {
    no *novo = (no *)malloc(sizeof(no));
    novo->dado = dado;       // Define o valor do nó
    novo->esq = NULL;        // Inicializa o ponteiro esquerdo como NULL
    novo->dir = NULL;        // Inicializa o ponteiro direito como NULL
    return novo;
}
