#include <stdio.h>

int main() {
    // Declaração das variáveis
    long long a, b, c;
    int E, P, S;

    // Entrada de dados
    scanf("%lld %lld %lld", &a, &b, &c);

    // Resolvendo o sistema de equações através de força bruta
    // Itera o número de caixas do tipo Especial, Predileta e Sortida
    for (E = 0; E <= 1000000000; E++) {
        for (P = 0; P <= 1000000000; P++) {
            for (S = 0; S <= 1000000000; S++) {
                // Calcula o consumo de cada ingrediente para cada quantidade de caixa
                long long amendoim_usado = 150 * E + 50 * P + 50 * S;
                long long chocolate_branco_usado = 750 * E + 750 * P + 500 * S;
                long long chocolate_ao_leite_usado = 600 * E + 900 * P + 750 * S;

                // Verifica se os consumos coincidem com os dados de entrada
                if (amendoim_usado == a && chocolate_branco_usado == b && chocolate_ao_leite_usado == c) {
                    printf("%d %d %d\n", E, P, S);
                    return 0;
                }
            }
        }
    }

    // Se nenhuma solução foi encontrada, imprime um erro
    printf("Sem solução\n");
    return 0;
}
