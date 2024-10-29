#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int valores[N];
    long long soma = 0;

    // Lê os valores e calcula a soma
    for (int i = 0; i < N; i++) {
        scanf("%d", &valores[i]);
        soma += valores[i];
    }

    // Calcula a média aritmética inteira
    int media = soma / N;
    int encontrou_maior = 0;

    // Verifica e imprime os elementos maiores que a média
    for (int i = 0; i < N; i++) {
        if (valores[i] > media) {
            if (encontrou_maior) {
                printf(" ");
            }
            printf("%d", valores[i]);
            encontrou_maior = 1;
        }
    }

    // Caso não tenha encontrado nenhum elemento maior que a média
    if (!encontrou_maior) {
        printf("0");
    }
    
    printf("\n");
    return 0;
}
