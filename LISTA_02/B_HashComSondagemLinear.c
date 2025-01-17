#include <stdlib.h>
#include <stdio.h>

// Estrutura da Tabela Hash
typedef struct {
    int *tb; // Vetor que representa a tabela hash
    int M;   // Tamanho da tabela hash
    int N;   // Número total de chaves presentes na tabela
} TH;

// Protótipo da função fornecida pelo juiz para calcular o novo tamanho da tabela
int aumentaTamanho(int M);

// Função hash usando o operador módulo
int hash(int chave, int M) {
    return chave % M;
}

// Função para inserir uma chave na tabela hash
void THinsere(TH *h, int ch) {
    // Verifica se a chave já está presente na tabela
    if (THbusca(h, ch)) return;

    // Redimensiona a tabela caso esteja mais que metade preenchida
    if (h->N > h->M / 2) {
        int novoM = aumentaTamanho(h->M); // Obtém o novo tamanho da tabela
        int *novaTabela = (int *)malloc(novoM * sizeof(int));
        for (int i = 0; i < novoM; i++) novaTabela[i] = -1; // Inicializa nova tabela com -1 (indicando posições vazias)

        // Reinsere as chaves existentes na nova tabela
        for (int i = 0; i < h->M; i++) {
            if (h->tb[i] != -1) {
                int pos = hash(h->tb[i], novoM);
                // Resolve colisões usando o método de sondagem linear
                while (novaTabela[pos] != -1) {
                    pos = (pos + 1) % novoM;
                }
                novaTabela[pos] = h->tb[i];
            }
        }
        free(h->tb); // Libera a memória da tabela antiga
        h->tb = novaTabela; // Atualiza a tabela para a nova estrutura
        h->M = novoM; // Atualiza o tamanho da tabela
    }

    // Insere a nova chave usando sondagem linear
    int pos = hash(ch, h->M);
    while (h->tb[pos] != -1) {
        pos = (pos + 1) % h->M;
    }
    h->tb[pos] = ch;
    h->N++; // Incrementa o número de chaves na tabela
}

// Função para remover uma chave da tabela hash
int THremove(TH *h, int ch) {
    int pos = hash(ch, h->M); // Calcula a posição inicial usando a função hash
    int start = pos; // Marca a posição inicial para detectar ciclos

    // Busca pela chave na tabela
    while (h->tb[pos] != -1) {
        if (h->tb[pos] == ch) {
            h->tb[pos] = -1; // Remove a chave, marcando a posição como vazia
            h->N--; // Decrementa o número de chaves

            // Reinsere elementos subsequentes que possam estar desalinhados
            pos = (pos + 1) % h->M;
            while (h->tb[pos] != -1) {
                int chaveReinserir = h->tb[pos];
                h->tb[pos] = -1;
                h->N--;
                THinsere(h, chaveReinserir);
                pos = (pos + 1) % h->M;
            }
            return 0; // Chave removida com sucesso
        }
        pos = (pos + 1) % h->M;
        if (pos == start) break; // Evita ciclos infinitos
    }
    return -1; // Retorna erro caso a chave não seja encontrada
}

// Função para buscar uma chave na tabela hash
int THbusca(TH *h, int ch) {
    int pos = hash(ch, h->M); // Calcula a posição inicial usando a função hash
    int start = pos; // Marca a posição inicial para detectar ciclos

    // Busca pela chave na tabela
    while (h->tb[pos] != -1) {
        if (h->tb[pos] == ch) return 1; // Chave encontrada
        pos = (pos + 1) % h->M;
        if (pos == start) break; // Evita ciclos infinitos
    }
    return 0; // Retorna 0 se a chave não for encontrada
}
