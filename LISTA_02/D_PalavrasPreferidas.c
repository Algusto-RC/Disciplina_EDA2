#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PALAVRA 17 // Tamanho máximo de uma palavra (16 caracteres + '\0')

// Estrutura que representa uma palavra na tabela hash
typedef struct Palavra {
    char palavra[MAX_PALAVRA]; // A palavra em si
    int votos;                 // Número de votos associados à palavra
    struct Palavra *prox;      // Ponteiro para a próxima palavra (em caso de colisões)
} Palavra;

// Função para buscar uma palavra na tabela hash
Palavra* buscarPalavra(Palavra *tabela[], const char *p) {
    unsigned int hash = 0;

    // Calcula o valor do hash usando a fórmula hash = (hash * 31 + caractere) % 1048576
    for (int i = 0; p[i] != '\0'; i++) {
        hash = (hash * 31 + p[i]) % 1048576;
    }

    // Percorre a lista encadeada no índice calculado da tabela hash
    Palavra *pAtual = tabela[hash];
    while (pAtual) {
        if (strcmp(pAtual->palavra, p) == 0) { // Verifica se a palavra é encontrada
            return pAtual; // Retorna o ponteiro para a palavra encontrada
        }
        pAtual = pAtual->prox; // Avança para o próximo nó
    }
    return NULL; // Retorna NULL se a palavra não for encontrada
}

// Função para adicionar uma nova palavra à tabela hash
void adicionarPalavra(Palavra *tabela[], const char *p) {
    unsigned int hash = 0;

    // Calcula o valor do hash
    for (int i = 0; p[i] != '\0'; i++) {
        hash = (hash * 31 + p[i]) % 1048576;
    }

    // Cria uma nova célula para armazenar a palavra
    Palavra *novaPalavra = (Palavra *)malloc(sizeof(Palavra));
    strcpy(novaPalavra->palavra, p); // Copia a palavra para a célula
    novaPalavra->votos = 1;         // Inicializa os votos como 1
    novaPalavra->prox = tabela[hash]; // Aponta para o início da lista encadeada atual
    tabela[hash] = novaPalavra;      // Insere a nova palavra no início da lista
}

// Função para incrementar o número de votos de uma palavra
void incrementarVoto(Palavra *tabela[], const char *p) {
    Palavra *palavra = buscarPalavra(tabela, p); // Busca a palavra na tabela hash
    if (palavra) {
        palavra->votos++; // Incrementa os votos se a palavra for encontrada
    } else {
        adicionarPalavra(tabela, p); // Adiciona a palavra se ela não existir na tabela
    }
}

// Função para obter o número de votos de uma palavra
int obterVotos(Palavra *tabela[], const char *p) {
    Palavra *palavra = buscarPalavra(tabela, p); // Busca a palavra na tabela hash
    return palavra ? palavra->votos : 0; // Retorna os votos ou 0 se a palavra não for encontrada
}

// Função para resetar os votos de uma palavra
void resetarVotos(Palavra *tabela[], const char *p) {
    Palavra *palavra = buscarPalavra(tabela, p); // Busca a palavra na tabela hash
    if (palavra) {
        palavra->votos = 0; // Reseta os votos para 0 se a palavra for encontrada
    }
}

// Função principal
int main() {
    Palavra *tabela[1048576] = {NULL}; // Inicializa a tabela hash com NULL
    int comando;
    char palavra[MAX_PALAVRA];

    // Lê comandos e palavras até o final da entrada (EOF)
    while (scanf("%d %s", &comando, palavra) != EOF) {
        if (comando == 1) { // Comando 1: Incrementar votos
            incrementarVoto(tabela, palavra);
        } else if (comando == 2) { // Comando 2: Consultar votos
            printf("%d\n", obterVotos(tabela, palavra));
        } else if (comando == 3) { // Comando 3: Resetar votos
            resetarVotos(tabela, palavra);
        }
    }

    return 0; // Finaliza o programa
}
