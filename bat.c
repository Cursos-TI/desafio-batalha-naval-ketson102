#include <stdio.h>

#define TAM 10  // Tamanho do tabuleiro
#define NAVIO 3 // Valor representando navio

// Inicializa o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Retorna 1 (pode colocar) ou 0 (não pode colocar)
int podeColocar(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho, char orientacao) {
    // orientacao: 'H' horizontal, 'V' vertical, 'D' diagonal descendo, 'A' diagonal subindo
    for (int i = 0; i < tamanho; i++) {
        int l = linha;
        int c = coluna;
        if (orientacao == 'H') c += i;           // Horizontal
        else if (orientacao == 'V') l += i;      // Vertical
        else if (orientacao == 'D') { l += i; c += i; } // Diagonal descendo
        else if (orientacao == 'A') { l += i; c -= i; } // Diagonal subindo

        // Fora dos limites
        if (l < 0 || l >= TAM || c < 0 || c >= TAM)
            return 0;

        // Sobreposição
        if (tabuleiro[l][c] != 0)
            return 0;
    }
    return 1;
}

// Coloca o navio no tabuleiro
void colocarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho, char orientacao) {
    for (int i = 0; i < tamanho; i++) {
        int l = linha;
        int c = coluna;
        if (orientacao == 'H') c += i;
        else if (orientacao == 'V') l += i;
        else if (orientacao == 'D') { l += i; c += i; }
        else if (orientacao == 'A') { l += i; c -= i; }
        tabuleiro[l][c] = NAVIO;
    }
}

// Exibe o tabuleiro formatado
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    int tamanhoNavio = 4; // tamanho fixo para exemplo

    // Dois navios normais
    if (podeColocar(tabuleiro, 0, 0, tamanhoNavio, 'H'))
        colocarNavio(tabuleiro, 0, 0, tamanhoNavio, 'H');

    if (podeColocar(tabuleiro, 2, 5, tamanhoNavio, 'V'))
        colocarNavio(tabuleiro, 2, 5, tamanhoNavio, 'V');

    // Dois navios diagonais
    if (podeColocar(tabuleiro, 5, 0, tamanhoNavio, 'D'))
        colocarNavio(tabuleiro, 5, 0, tamanhoNavio, 'D');

    if (podeColocar(tabuleiro, 0, 9, tamanhoNavio, 'A'))
        colocarNavio(tabuleiro, 0, 9, tamanhoNavio, 'A');

    exibirTabuleiro(tabuleiro);
    return 0;
}
