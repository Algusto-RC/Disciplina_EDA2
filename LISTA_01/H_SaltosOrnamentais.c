#include <stdio.h>

int main() {
    float D, notas[7], soma = 0.0, max = 0.0, min = 10.0;

    // Lendo a dificuldade do salto
    scanf("%f", &D);

    // Lendo as 7 notas dos juízes
    for (int i = 0; i < 7; i++) {
        scanf("%f", &notas[i]);

        // Encontrando a maior e a menor nota
        if (notas[i] > max) max = notas[i];
        if (notas[i] < min) min = notas[i];

        // Somando todas as notas
        soma += notas[i];
    }

    // Subtraindo a maior e a menor nota da soma
    soma -= (max + min);

    // Calculando a média das 5 notas restantes
    float media = soma / 5.0;

    // Calculando a nota final do salto
    float N = media * D;

    // Imprimindo o resultado com uma casa decimal
    printf("%.1f\n", N);

    return 0;
}
