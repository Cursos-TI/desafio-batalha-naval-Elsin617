#include <stdio.h>

#define TAM 10
#define AGUA 0
#define NAVIO 3

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com água
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Posicionamento dos navios
    tabuleiro[0][1] = NAVIO;
    tabuleiro[0][9] = NAVIO;

    tabuleiro[1][1] = NAVIO;
    tabuleiro[1][8] = NAVIO;

    tabuleiro[2][2] = NAVIO;
    tabuleiro[2][7] = NAVIO;

    tabuleiro[3][3] = NAVIO;
    tabuleiro[3][6] = NAVIO;

    tabuleiro[4][4] = NAVIO;
    tabuleiro[4][5] = NAVIO;

    tabuleiro[5][4] = NAVIO;
    tabuleiro[5][5] = NAVIO;

    tabuleiro[6][3] = NAVIO;
    tabuleiro[6][6] = NAVIO;

    tabuleiro[7][1] = NAVIO;
    tabuleiro[7][7] = NAVIO;

    tabuleiro[8][1] = NAVIO;
    tabuleiro[8][8] = NAVIO;

    tabuleiro[9][0] = NAVIO;
    tabuleiro[9][9] = NAVIO;

    // Impressão do tabuleiro no formato da imagem
    printf("  TABULEIRO BATALHA NAVAL\n");
    printf("  A B C D E F G H I J\n");

    for (int i = 0; i < TAM; i++) {
        printf("%d ", i); // número da linha
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

    