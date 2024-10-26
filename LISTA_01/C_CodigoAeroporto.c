#include <stdio.h>
#include <string.h>

int validaSigla(char *nome, char *sigla) {
    int i = 0, j = 0;
    int nomeLen = strlen(nome);
    int siglaLen = strlen(sigla);

    // Caso especial: se a última letra da sigla é 'X', ignore a última letra e considere apenas as duas primeiras letras
    if (sigla[2] == 'X') {
        siglaLen = 2;
    }

    // Percorre o nome do aeroporto e tenta encontrar os caracteres da sigla em ordem
    while (i < nomeLen && j < siglaLen) {
        if (nome[i] == sigla[j]) {
            j++; // Avança na sigla ao encontrar a letra correspondente
        }
        i++; // Avança no nome do aeroporto
    }

    // Se todos os caracteres da sigla foram encontrados, então a sigla é válida
    return j == siglaLen;
}

int main() {
    char nome[100001];
    char sigla[4];

    // Leitura da entrada
    scanf("%s", nome);
    scanf("%s", sigla);

    // Verificação e impressão do resultado
    if (validaSigla(nome, sigla)) {
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }

    return 0;
}
