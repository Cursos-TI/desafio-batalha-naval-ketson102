#include <stdio.h>
#include <stdbool.h>

#define TAMANHO 10   // Tamanho do tabuleiro
#define TAM_NAVIO 3  // Tamanho fixo dos navios

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    int i, j;

    // Inicializa todo o tabuleiro com 0 (água)
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas iniciais definidas no código
    // Navio 1 (horizontal)
    int linhaNavio1 = 2;  // linha inicial
    int colunaNavio1 = 4; // coluna inicial

    // Navio 2 (vertical)
    int linhaNavio2 = 5;  // linha inicial
    int colunaNavio2 = 7; // coluna inicial

    // Validação para navio horizontal caber no tabuleiro
    if (colunaNavio1 + TAM_NAVIO > TAMANHO) {
        printf("Erro: Navio 1 (horizontal) não cabe no tabuleiro.\n");
        return 1;
    }

    // Validação para navio vertical caber no tabuleiro
    if (linhaNavio2 + TAM_NAVIO > TAMANHO) {
        printf("Erro: Navio 2 (vertical) não cabe no tabuleiro.\n");
        return 1;
    }

    // Validação de sobreposição simples
    // Primeiro posiciona Navio 1 (horizontal)
    for (j = 0; j < TAM_NAVIO; j++) {
        tabuleiro[linhaNavio1][colunaNavio1 + j] = 3;
    }

    // Antes de posicionar Navio 2 (vertical), checa se já há um navio
    bool sobreposicao = false;
    for (i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaNavio2 + i][colunaNavio2] == 3) {
            sobreposicao = true;
        }
    }

    if (sobreposicao) {
        printf("Erro: Navio 2 (vertical) se sobrepõe ao Navio 1.\n");
        return 1;
    }

    // Se não há sobreposição, posiciona Navio 2 (vertical)
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaNavio2 + i][colunaNavio2] = 3;
    }

    // Exibe o tabuleiro completo
    printf("\nTabuleiro Batalha Naval:\n");
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
