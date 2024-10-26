#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura celula
typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Função para inserir um elemento x no início da lista encadeada
void insere_inicio(celula *le, int x) {
    celula *nova_celula = (celula *)malloc(sizeof(celula));
    if (nova_celula == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    nova_celula->dado = x;
    nova_celula->prox = le->prox; // Aponta o novo nó para o primeiro elemento
    le->prox = nova_celula;       // Atualiza o nó cabeça para apontar para o novo nó
}

// Função para inserir um elemento x antes da primeira ocorrência de y
void insere_antes(celula *le, int x, int y) {
    celula *atual = le->prox;  // Começa a partir do primeiro elemento
    celula *anterior = le;     // O nó anterior começa sendo o nó cabeça

    while (atual != NULL && atual->dado != y) {
        anterior = atual;
        atual = atual->prox;
    }

    celula *nova_celula = (celula *)malloc(sizeof(celula));
    if (nova_celula == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    nova_celula->dado = x;

    if (atual == NULL) {
        // Se y não foi encontrado, insere no final da lista
        anterior->prox = nova_celula;
        nova_celula->prox = NULL; // O novo nó é o último
    } else {
        // Insere antes do nó que contém y
        anterior->prox = nova_celula;
        nova_celula->prox = atual;
    }
}

// Função para imprimir a lista (opcional, para verificar inserções)
void imprime_lista(celula *le) {
    celula *atual = le->prox; // Começa a partir do primeiro elemento
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int main() {
    celula *lista = (celula *)malloc(sizeof(celula)); // Nó cabeça
    lista->prox = NULL; // Inicialmente, a lista está vazia

    // Inserindo elementos
    insere_inicio(lista, 10);
    insere_inicio(lista, 20);
    insere_antes(lista, 15, 10); // Inserindo 15 antes do primeiro 10
    insere_antes(lista, 25, 30);  // Inserindo 25 no final, pois 30 não existe

    // Imprimindo a lista
    imprime_lista(lista);

    // Liberar a memória (não implementado aqui)
    return 0;
}
