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

// Função para criar a pilha
stack *criar_pilha(int capacidade) {
    stack *pilha = (stack *)malloc(sizeof(stack));
    pilha->data = (no **)malloc(capacidade * sizeof(no *)); // Aloca memória para o vetor
    pilha->topo = -1;  // Inicializa o topo como vazio
    pilha->capacidade = capacidade; // Define a capacidade máxima
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
    return pilha->data[pilha->topo--]; // Retorna o nó do topo e decrementa o índice
}

// Libera a memória alocada para a pilha
void liberar_pilha(stack *pilha) {
    free(pilha->data); // Libera o vetor de ponteiros
    free(pilha);       // Libera a estrutura da pilha
}

// Função para realizar o percurso pré-ordem (não recursivo)
void pre_ordem(no *raiz) {
    if (raiz == NULL) return; // Retorna se a árvore estiver vazia

    // Cria uma pilha com capacidade inicial suficiente
    stack *pilha = criar_pilha(100);
    empilhar(pilha, raiz);

    while (!esta_vazia(pilha)) {
        no *atual = desempilhar(pilha);
        printf("%d ", atual->dado); // Processa o nó atual (imprime o dado)

        // Empilha o filho direito primeiro, pois o esquerdo deve ser processado antes
        if (atual->dir != NULL) empilhar(pilha, atual->dir);
        if (atual->esq != NULL) empilhar(pilha, atual->esq);
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
