#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int vetor[N];
    int soma = 0;

    // Lê os elementos do vetor e calcula a soma
    for (int i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }

    // Calcula a média inteira
    int media = soma / N;

    // Verifica os elementos maiores que a média e exibe-os
    int encontrou = 0;
    for (int i = 0; i < N; i++) {
        if (vetor[i] > media) {
            if (encontrou) {
                printf(" ");
            }
            printf("%d", vetor[i]);
            encontrou = 1;
        }
    }

    // Se não houver elementos maiores que a média, imprime 0
    if (!encontrou) {
        printf("0");
    }

    printf("\n");
    return 0;
}
