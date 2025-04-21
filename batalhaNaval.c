#include <stdio.h>

#define TAM 10
#define AGUA 0
#define NAVIO 3

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa todas as posições com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Posiciona o navio horizontal na linha 2 (índice 2), colunas 4, 5, 6
    for (int i = 0; i < 3; i++) {
        tabuleiro[2][4 + i] = NAVIO;
    }

    // Posiciona o navio vertical na coluna 6 (índice 6), linhas 5, 6, 7
    for (int i = 0; i < 3; i++) {
        tabuleiro[5 + i][6] = NAVIO; // sobreposição permitida
    }

    // Exibe o tabuleiro com letras A-J e linhas 1-10
    printf("  TABULEIRO  BATALHA  NAVAL\n");
    printf("  A B C D E F G H I J\n");

    for (int i = 0; i < TAM; i++) {
        printf("%-2d", i + 1); // Exibe número da linha (1 a 10)
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}


