#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura celula
typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Função que procura pela primeira ocorrência do elemento x na lista encadeada
celula *busca(celula *le, int x) {
    celula *atual = le->prox; // Começa a busca a partir do primeiro nó
    while (atual != NULL) {
        if (atual->dado == x) {
            return atual; // Retorna o ponteiro para a célula que contém o dado
        }
        atual = atual->prox; // Move para o próximo nó
    }
    return NULL; // Retorna NULL se o elemento não for encontrado
}

// Função recursiva que procura pela primeira ocorrência do elemento x na lista encadeada
celula *busca_rec(celula *le, int x) {
    // Se a lista estiver vazia ou chegamos ao final
    if (le == NULL) {
        return NULL;
    }
    if (le->dado == x) {
        return le; // Retorna o ponteiro se encontrar o elemento
    }
    return busca_rec(le->prox, x); // Chamada recursiva para o próximo nó
}

int main() {
    // Exemplo de uso das funções (para testes)
    celula *lista = malloc(sizeof(celula)); // Criando o nó cabeça
    lista->prox = NULL; // Inicializa a lista como vazia

    // Adicionando elementos à lista (exemplo)
    celula *novo1 = malloc(sizeof(celula));
    novo1->dado = 10;
    novo1->prox = lista->prox;
    lista->prox = novo1;

    celula *novo2 = malloc(sizeof(celula));
    novo2->dado = 20;
    novo2->prox = lista->prox;
    lista->prox = novo2;

    // Testando a busca
    int elemento = 10;
    celula *resultado = busca(lista, elemento);
    if (resultado != NULL) {
        printf("Elemento %d encontrado (busca iterativa).\n", resultado->dado);
    } else {
        printf("Elemento %d não encontrado (busca iterativa).\n", elemento);
    }

    resultado = busca_rec(lista->prox, elemento); // Passa o primeiro nó (lista->prox)
    if (resultado != NULL) {
        printf("Elemento %d encontrado (busca recursiva).\n", resultado->dado);
    } else {
        printf("Elemento %d não encontrado (busca recursiva).\n", elemento);
    }

    // Liberar memória alocada (não se esqueça de fazer isso em um código real)
    // O código aqui deve incluir a liberação dos nós da lista.

    return 0;
}
