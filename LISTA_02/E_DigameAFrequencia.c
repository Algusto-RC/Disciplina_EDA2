#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar um par chave-valor
typedef struct {
    char chave; // Caracter
    int valor;  // Frequência do caracter
} par;

// Função de comparação para ordenação dos pares
int comparar(const void* a, const void* b) {
    par* parA = (par*)a;
    par* parB = (par*)b;

    // Caso os valores (frequências) sejam iguais, ordena pela chave (caracter) em ordem crescente
    if (parA->valor == parB->valor) {
        return parA->chave - parB->chave;
    }
    // Ordena pela frequência em ordem crescente
    return parA->valor - parB->valor;
}

int main() {
    char s[1001]; // Buffer para armazenar a linha de entrada (até 1000 caracteres)
    int t = 0;    // Variável para controlar a separação entre conjuntos de saída

    // Lê cada linha da entrada padrão até EOF
    while (fgets(s, 1001, stdin)) {
        int mp[128] = {0}; // Vetor para armazenar a frequência de cada caracter ASCII (0-127)

        // Imprime uma linha em branco antes do próximo conjunto de saída, exceto no primeiro
        if (t) {
            printf("\n");
        }
        t = 1;

        int len = strlen(s); // Comprimento da string lida
        // Conta a frequência de cada caracter, ignorando o '\n'
        for (int i = 0; i < len; i++) {
            if (s[i] != '\n') {
                mp[(int)s[i]]++; // Incrementa a frequência do caracter correspondente
            }
        }

        par mpp[128]; // Vetor para armazenar os pares (caracter e frequência)
        int cont = 0; // Contador para os pares válidos
        // Cria pares (caracter e frequência) para os caracteres com frequência maior que 0
        for (int i = 0; i < 128; i++) {
            if (mp[i] > 0) {
                mpp[cont].chave = i;    // Armazena o caracter
                mpp[cont].valor = mp[i]; // Armazena a frequência
                cont++;
            }
        }

        // Ordena os pares pela frequência (em ordem crescente) e, em caso de empate, pelo caracter
        qsort(mpp, cont, sizeof(par), comparar);

        // Imprime os pares ordenados: caracter (como inteiro) e sua frequência
        for (int i = 0; i < cont; i++) {
            printf("%d %d\n", mpp[i].chave, mpp[i].valor);
        }
    }

    return 0; // Finaliza o programa
}
