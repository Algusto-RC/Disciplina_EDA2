#include <stdio.h>
#include <string.h>
#include <ctype.h> 


int verificar_sigla(const char *nome, const char *sigla, int tamanho_sigla) {
    int i = 0, j = 0;
    int tamanho_nome = strlen(nome);

    while (i < tamanho_nome && j < tamanho_sigla) {
        if (nome[i] == sigla[j]) {
            j++;
        }
        i++;
    }
    

    return j == tamanho_sigla;
}

int main() {
    char nome[100001];
    char sigla[4];
    

    scanf("%s", nome);
    scanf("%s", sigla);
    

    for (int i = 0; nome[i] != '\0'; i++) {
        nome[i] = toupper(nome[i]);
    }
    
    int tamanho_sigla = (sigla[2] == 'X') ? 2 : 3;

    if (verificar_sigla(nome, sigla, tamanho_sigla)) {
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }

    return 0;
}
