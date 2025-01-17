#include <stdio.h>
#include <stdlib.h>

// Estrutura para a célula da tabela hash (lista encadeada)
typedef struct celula {
    int dado;               // Dado armazenado (chave)
    struct celula *prox;    // Ponteiro para a próxima célula
} celula;

// Estrutura para a tabela hash
typedef struct {
    celula *tb; // Vetor de células para as listas encadeadas
    int M;      // Tamanho da tabela (número de posições possíveis)
    int N;      // Número total de elementos armazenados na tabela
} TH;

// Função hash para calcular o índice baseado na chave e no tamanho da tabela
static int hash(int chave, int M) {
    return chave % M; // Retorna o índice calculado como o resto da divisão da chave por M
}

// Função para buscar uma chave na tabela hash
int THbusca(TH *h, int ch) {
    int idx = hash(ch, h->M); // Calcula o índice da chave usando a função hash
    celula *atual = &h->tb[idx]; // Acessa a lista encadeada no índice calculado

    // Percorre a lista encadeada buscando a chave
    while (atual != NULL) {
        if (atual->dado == ch) { // Verifica se encontrou a chave
            return 1; // Retorna 1 se a chave está na tabela
        }
        atual = atual->prox; // Avança para a próxima célula
    }
    return 0; // Retorna 0 se a chave não está na tabela
}

// Função para inserir uma chave na tabela hash
void THinsere(TH *h, int ch) {
    if (THbusca(h, ch)) { // Verifica se a chave já está na tabela
        return; // Não insere duplicatas
    }

    int idx = hash(ch, h->M); // Calcula o índice da chave usando a função hash
    celula *novo = malloc(sizeof(celula)); // Aloca memória para uma nova célula
    if (novo == NULL) { // Verifica se a alocação foi bem-sucedida
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }

    // Insere a nova célula no início da lista encadeada correspondente
    novo->dado = ch;
    novo->prox = h->tb[idx].prox;
    h->tb[idx].prox = novo;
    h->N++; // Incrementa o número total de elementos na tabela
}

// Função para remover uma chave da tabela hash
int THremove(TH *h, int ch) {
    int idx = hash(ch, h->M); // Calcula o índice da chave usando a função hash
    celula *atual = &h->tb[idx]; // Acessa a lista encadeada no índice calculado
    celula *anterior = NULL; // Ponteiro para armazenar a célula anterior na lista

    // Percorre a lista encadeada buscando a chave
    while (atual != NULL) {
        if (atual->dado == ch) { // Verifica se encontrou a chave
            // Remove a célula da lista encadeada
            if (anterior == NULL) { // Caso especial: a chave está na primeira célula
                h->tb[idx].prox = atual->prox;
            } else { // Caso geral: a chave está no meio ou no final da lista
                anterior->prox = atual->prox;
            }
            free(atual); // Libera a memória da célula removida
            h->N--; // Decrementa o número total de elementos na tabela
            return 0; // Retorna 0 para indicar que a remoção foi bem-sucedida
        }
        anterior = atual; // Atualiza o ponteiro anterior
        atual = atual->prox; // Avança para a próxima célula
    }
    return -1; // Retorna -1 se a chave não foi encontrada
}
