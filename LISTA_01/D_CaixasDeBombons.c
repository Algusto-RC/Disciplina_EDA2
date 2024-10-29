#include <stdio.h>

int main() {
    long int amendoim, chocolate_branco, chocolate_ao_leite;

    scanf("%ld %ld %ld", &amendoim, &chocolate_branco, &chocolate_ao_leite);

    const int crocante_amendoim = 5 * 30;
    const int crocante_choco_branco = 25 * 30;
    const int crocante_choco_leite = 20 * 30;

    const int predileta_amendoim = 5 * 10;
    const int predileta_choco_branco = 25 * 10 + 25 * 20;
    const int predileta_choco_leite = 20 * 10 + 25 * 20;

    const int sortida_amendoim = 5 * 10;
    const int sortida_choco_branco = 25 * 10 + 25 * 10;
    const int sortida_choco_leite = 20 * 10 + 25 * 10 + 50 * 10;

    int sol_especial = 0, sol_predileta = 0, sol_sortida = 0;
    int solucao_encontrada = 0;

    for (int especial = 0; especial <= 109 && !solucao_encontrada; especial++) {
        for (int predileta = 0; predileta <= 109 && !solucao_encontrada; predileta++) {
            for (int sortida = 0; sortida <= 109 && !solucao_encontrada; sortida++) {
                long int total_amendoim = especial * crocante_amendoim + predileta * predileta_amendoim + sortida * sortida_amendoim;
                long int total_choco_branco = especial * crocante_choco_branco + predileta * predileta_choco_branco + sortida * sortida_choco_branco;
                long int total_choco_leite = especial * crocante_choco_leite + predileta * predileta_choco_leite + sortida * sortida_choco_leite;

                if (total_amendoim == amendoim && total_choco_branco == chocolate_branco && total_choco_leite == chocolate_ao_leite) {
                    sol_especial = especial;
                    sol_predileta = predileta;
                    sol_sortida = sortida;
                    solucao_encontrada = 1;
                }
            }
        }
    }

    printf("%d %d %d\n", sol_especial, sol_predileta, sol_sortida);

    return 0;
}
