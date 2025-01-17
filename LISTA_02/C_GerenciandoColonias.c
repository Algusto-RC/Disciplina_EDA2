#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLONIAS 1048576 // Define o tamanho máximo da tabela hash (número de colônias)

// Estrutura que representa o estoque de uma colônia
typedef struct {
    int id_colonia;         // Identificador único da colônia
    char alimento[11];      // Nome do alimento armazenado (máximo de 10 caracteres + '\0')
} Estoque;

// Estrutura para as células da lista encadeada usada na tabela hash
typedef struct Celula {
    Estoque estoque;        // Dados do estoque armazenados na célula
    struct Celula *prox;    // Ponteiro para a próxima célula na lista
} Celula;

// Estrutura da tabela hash
typedef struct {
    Celula **tabela;        // Vetor de ponteiros para listas de células
} TabelaHash;

// Função de hash para calcular o índice baseado no id da colônia
unsigned int hash(int id_colonia) {
    return id_colonia % MAX_COLONIAS; // Retorna o índice dentro do intervalo [0, MAX_COLONIAS-1]
}

// Cria e inicializa uma tabela hash
TabelaHash* criaTabela() {
    TabelaHash *tabela = (TabelaHash*)malloc(sizeof(TabelaHash));      // Aloca memória para a estrutura da tabela
    tabela->tabela = (Celula**)calloc(MAX_COLONIAS, sizeof(Celula*));  // Inicializa o vetor de listas como NULL
    return tabela;
}

// Insere um novo estoque na tabela hash
void insereTabela(TabelaHash *tabela, int id_colonia, const char *alimento) {
    unsigned int index = hash(id_colonia); // Calcula o índice na tabela hash usando a função de hash
    Celula *atual = tabela->tabela[index]; // Obtém o início da lista encadeada no índice calculado

    // Verifica se o estoque já existe na tabela
    while (atual != NULL) {
        if (atual->estoque.id_colonia == id_colonia && strcmp(atual->estoque.alimento, alimento) == 0) {
            printf("%d\n", id_colonia); // Se o estoque já existe, imprime o id da colônia
            return;                    // Retorna sem inserir novamente
        }
        atual = atual->prox;           // Avança para a próxima célula na lista
    }

    // Cria uma nova célula para armazenar o estoque
    Celula *novaCelula = (Celula*)malloc(sizeof(Celula));
    novaCelula->estoque.id_colonia = id_colonia;    // Define o id da colônia
    strcpy(novaCelula->estoque.alimento, alimento); // Copia o nome do alimento
    novaCelula->prox = tabela->tabela[index];       // Aponta para o início da lista atual
    tabela->tabela[index] = novaCelula;            // Insere a nova célula no início da lista
}

// Função principal
int main() {
    TabelaHash *tabela = criaTabela(); // Cria a tabela hash
    int id_colonia;
    char alimento[11];

    // Lê os dados de entrada (id_colonia e alimento) até o final do arquivo (EOF)
    while (scanf("%d %s", &id_colonia, alimento) != EOF) {
        insereTabela(tabela, id_colonia, alimento); // Insere os dados na tabela hash
    }

    return 0; // Finaliza o programa
}
