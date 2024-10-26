#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da célula
typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Função iterativa para imprimir a lista encadeada
void imprime(celula *le) {
    if (le == NULL) {
        printf("NULL\n");
        return;
    }
    
    celula *temp = le;
    while (temp != NULL) {
        printf("%d", temp->dado);
        temp = temp->prox;
        if (temp != NULL) {
            printf(" -> ");
        }
    }
    printf(" -> NULL\n");
}

// Função recursiva para imprimir a lista encadeada
void imprime_rec(celula *le) {
    if (le == NULL) {
        printf("NULL\n");
        return;
    }

    printf("%d", le->dado);
    if (le->prox != NULL) {
        printf(" -> ");
    }
    
    imprime_rec(le->prox);
}

int main() {
    // Exemplo de uso das funções
    celula *le = (celula *)malloc(sizeof(celula)); // nó cabeça
    le->dado = 0; // dado do nó cabeça (pode ser usado para outros fins, como contagem)
    le->prox = NULL;

    // Adicionando alguns elementos à lista
    celula *n1 = (celula *)malloc(sizeof(celula));
    n1->dado = 1;
    n1->prox = NULL;
    le->prox = n1;

    celula *n2 = (celula *)malloc(sizeof(celula));
    n2->dado = 2;
    n2->prox = NULL;
    n1->prox = n2;

    celula *n3 = (celula *)malloc(sizeof(celula));
    n3->dado = 3;
    n3->prox = NULL;
    n2->prox = n3;

    // Impressão da lista
    printf("Impressão iterativa:\n");
    imprime(le->prox); // passa le->prox para ignorar o nó cabeça

    printf("Impressão recursiva:\n");
    imprime_rec(le->prox); // passa le->prox para ignorar o nó cabeça

    // Liberando a memória
    free(n3);
    free(n2);
    free(n1);
    free(le);

    return 0;
}
