#include <stdio.h>

int main() {
    int D, A, N;
    
    // Leitura dos valores de entrada
    scanf("%d", &D);
    scanf("%d", &A);
    scanf("%d", &N);

    // Calcula o número de diárias restantes
    int dias_restantes = 32 - N;
    
    // Calcula o valor da diária no dia de chegada
    int diaria = D + (N - 1) * A;
    
    // Calcula o valor total a ser pago
    int total = dias_restantes * diaria;
    
    // Imprime o resultado
    printf("%d\n", total);

    return 0;
}
