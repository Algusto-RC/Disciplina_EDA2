#include <stdio.h>
#include <stdlib.h>

#define MAX_DISCIPLINAS 1000

int main() {
    int D;
    scanf("%d", &D); // Número total de disciplinas

    int ano, semestre, m;
    while (scanf("%d %d %d", &ano, &semestre, &m) != EOF) {
        int max_reprovacao = -1;
        int disciplinas[MAX_DISCIPLINAS];
        int qtd_disciplinas = 0;

        for (int i = 0; i < m; i++) {
            int codigo, matriculados, aprovados;
            scanf("%d %d %d", &codigo, &matriculados, &aprovados);

            int reprovados = matriculados - aprovados;

            if (reprovados > max_reprovacao) {
                max_reprovacao = reprovados;
                qtd_disciplinas = 1;
                disciplinas[0] = codigo;
            } else if (reprovados == max_reprovacao) {
                disciplinas[qtd_disciplinas++] = codigo;
            }
        }

        // Ordena os códigos das disciplinas com a maior reprovação
        for (int i = 0; i < qtd_disciplinas - 1; i++) {
            for (int j = i + 1; j < qtd_disciplinas; j++) {
                if (disciplinas[i] > disciplinas[j]) {
                    int temp = disciplinas[i];
                    disciplinas[i] = disciplinas[j];
                    disciplinas[j] = temp;
                }
            }
        }

        // Imprime o semestre e as disciplinas com mais reprovação
        printf("%d/%d\n", ano, semestre);
        for (int i = 0; i < qtd_disciplinas; i++) {
            printf("%d ", disciplinas[i]);
        }
        printf("\n\n");
    }

    return 0;
}
