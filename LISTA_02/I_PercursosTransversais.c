#include <stdio.h>
#include <string.h>

// Função recursiva para construir a representação pós-fixa (posfixo) de uma árvore binária
// a partir das representações pré-fixa (prefixo) e infixa (infixo)
void posfixo(char *prefixo, char *infixo, int n, char *resultado) {
    if (n == 0) return; // Caso base: se o tamanho for 0, não há nada para processar

    char raiz = prefixo[0]; // O primeiro elemento do prefixo é sempre a raiz da árvore
    int i, index;

    // Encontrar a posição da raiz no infixo
    for (i = 0; i < n; i++) {
        if (infixo[i] == raiz) { // Localiza a raiz no infixo
            index = i; // Índice que divide as subárvores esquerda e direita
            break;
        }
    }

    // Processa a subárvore esquerda
    posfixo(prefixo + 1, infixo, index, resultado);

    // Processa a subárvore direita
    posfixo(prefixo + index + 1, infixo + index + 1, n - index - 1, resultado);

    // Adiciona a raiz no final do resultado (pós-fixa)
    resultado[strlen(resultado)] = raiz;
}

int main() {
    int C; // Número de casos de teste
    scanf("%d", &C);

    while (C--) { // Itera sobre cada caso de teste
        int N;                // Tamanho das sequências
        char S1[55], S2[55];  // Arrays para as representações pré-fixa e infixa
        char resultado[55] = ""; // Array para armazenar o resultado pós-fixo, inicializado vazio

        // Lê o tamanho da árvore e as sequências prefixo e infixo
        scanf("%d %s %s", &N, S1, S2);

        // Gera a sequência pós-fixa a partir das entradas
        posfixo(S1, S2, N, resultado);

        // Imprime o resultado
        printf("%s\n", resultado);
    }

    return 0;
}
