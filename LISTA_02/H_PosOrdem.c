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

// Função para realizar o percurso pós-ordem (não recursivo)
void pos_ordem(no *raiz) {
    if (raiz == NULL) return; // Retorna imediatamente se a árvore estiver vazia

    stack *pilha1 = criar_pilha(100); // Pilha principal para armazenar nós durante o percurso
    stack *pilha2 = criar_pilha(100); // Pilha auxiliar para garantir a ordem pós-ordem

    empilhar(pilha1, raiz); // Empilha a raiz na primeira pilha

    // Percorre a árvore
    while (!esta_vazia(pilha1)) {
        no *atual = desempilhar(pilha1); // Remove o nó do topo da primeira pilha
        empilhar(pilha2, atual);         // Armazena na segunda pilha

        // Empilha os filhos na primeira pilha
        if (atual->esq != NULL) empilhar(pilha1, atual->esq); // Filho esquerdo
        if (atual->dir != NULL) empilhar(pilha1, atual->dir); // Filho direito
    }

    // Desempilha da segunda pilha e processa os nó
