#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 10
#define AGUA 0
#define NAVIO 3
#define AFETADO 5

#define TAMANHO_CONE 5
#define TAMANHO_CRUZ 5
#define TAMANHO_OCTAEDRO 5

void criarCone(int matriz[TAMANHO_CONE][TAMANHO_CONE]) {
    int centro = TAMANHO_CONE / 2;
    for (int i = 0; i < TAMANHO_CONE; i++) {
        for (int j = 0; j < TAMANHO_CONE; j++) {
            if (i >= centro && j >= centro - i + centro && j <= centro + i - centro) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

void criarCruz(int matriz[TAMANHO_CRUZ][TAMANHO_CRUZ]) {
    int centro = TAMANHO_CRUZ / 2;
    for (int i = 0; i < TAMANHO_CRUZ; i++) {
        for (int j = 0; j < TAMANHO_CRUZ; j++) {
            if (i == centro || j == centro) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

void criarOctaedro(int matriz[TAMANHO_OCTAEDRO][TAMANHO_OCTAEDRO]) {
    int centro = TAMANHO_OCTAEDRO / 2;
    for (int i = 0; i < TAMANHO_OCTAEDRO; i++) {
        for (int j = 0; j < TAMANHO_OCTAEDRO; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                      int habilidade[TAMANHO_CONE][TAMANHO_CONE],
                      int linhaOrigem, int colunaOrigem, int tamanhoHabilidade) {
    int centroHabilidade = tamanhoHabilidade / 2;
    for (int i = 0; i < tamanhoHabilidade; i++) {
        for (int j = 0; j < tamanhoHabilidade; j++) {
            int linhaTabuleiro = linhaOrigem - centroHabilidade + i;
            int colunaTabuleiro = colunaOrigem - centroHabilidade + j;

            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO &&
                colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO &&
                habilidade[i][j] == 1 && tabuleiro[linhaTabuleiro][colunaTabuleiro] != NAVIO) {
                tabuleiro[linhaTabuleiro][colunaTabuleiro] = AFETADO;
            }
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("  0123456789\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    tabuleiro[0][3] = NAVIO;
    tabuleiro[1][3] = NAVIO;
    tabuleiro[2][0] = NAVIO;
    tabuleiro[2][1] = NAVIO;
    tabuleiro[2][2] = NAVIO;
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;
    tabuleiro[3][3] = NAVIO;
    tabuleiro[3][7] = 2; // Parece haver um '2' na imagem, mantendo para referência
    tabuleiro[3][8] = 0;
    tabuleiro[3][9] = 0;
    tabuleiro[4][3] = NAVIO;
    tabuleiro[4][6] = 2;
    tabuleiro[4][7] = 2;
    tabuleiro[4][8] = 2;
    tabuleiro[5][1] = 1; // Parece haver um '1' na imagem, mantendo para referência
    tabuleiro[5][4] = 2;
    tabuleiro[5][5] = 2;
    tabuleiro[5][6] = 2;
    tabuleiro[5][7] = 2;
    tabuleiro[5][8] = 2;
    tabuleiro[6][1] = 1;
    tabuleiro[6][2] = 1;
    tabuleiro[6][3] = 1;
    tabuleiro[6][6] = 2;
    tabuleiro[6][7] = 2;
    tabuleiro[6][8] = 0;
    tabuleiro[7][0] = 1;
    tabuleiro[7][1] = 1;
    tabuleiro[7][2] = 1;
    tabuleiro[7][3] = 1;
    tabuleiro[7][4] = 1;
    tabuleiro[7][7] = 2;
    tabuleiro[7][8] = 0;
    tabuleiro[7][9] = 0;
    tabuleiro[8][0] = 0;
    tabuleiro[8][1] = 0;
    tabuleiro[8][2] = 0;
    tabuleiro[8][3] = 0;
    tabuleiro[8][4] = 0;
    tabuleiro[8][5] = 0;
    tabuleiro[8][6] = 0;
    tabuleiro[8][7] = 0;
    tabuleiro[8][8] = 0;
    tabuleiro[8][9] = 0;
    tabuleiro[9][0] = 0;
    tabuleiro[9][1] = 0;
    tabuleiro[9][2] = 0;
    tabuleiro[9][3] = 0;
    tabuleiro[9][4] = 0;
    tabuleiro[9][5] = 0;
    tabuleiro[9][6] = 0;
    tabuleiro[9][7] = 0;
    tabuleiro[9][8] = 0;
    tabuleiro[9][9] = 0;

    int cone[TAMANHO_CONE][TAMANHO_CONE] = {0};
    int cruz[TAMANHO_CRUZ][TAMANHO_CRUZ] = {0};
    int octaedro[TAMANHO_OCTAEDRO][TAMANHO_OCTAEDRO] = {0};

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    int linhaOrigemCone = 2;
    int colunaOrigemCone = 2;
    int linhaOrigemCruz = 5;
    int colunaOrigemCruz = 5;
    int linhaOrigemOctaedro = 7;
    int colunaOrigemOctaedro = 7;

    printf("Tabuleiro original:\n");
    exibirTabuleiro(tabuleiro);

    int tabuleiroComCone[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiroComCone[i][j] = tabuleiro[i][j];
        }
    }
    aplicarHabilidade(tabuleiroComCone, cone, linhaOrigemCone, colunaOrigemCone, TAMANHO_CONE);
    printf("Tabuleiro com habilidade Cone aplicada em (%d, %d):\n", linhaOrigemCone, colunaOrigemCone);
    exibirTabuleiro(tabuleiroComCone);

    int tabuleiroComCruz[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiroComCruz[i][j] = tabuleiro[i][j];
        }
    }
    aplicarHabilidade(tabuleiroComCruz, cruz, linhaOrigemCruz, colunaOrigemCruz, TAMANHO_CRUZ);
    printf("Tabuleiro com habilidade Cruz aplicada em (%d, %d):\n", linhaOrigemCruz, colunaOrigemCruz);
    exibirTabuleiro(tabuleiroComCruz);

    int tabuleiroComOctaedro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiroComOctaedro[i][j] = tabuleiro[i][j];
        }
    }
    aplicarHabilidade(tabuleiroComOctaedro, octaedro, linhaOrigemOctaedro, colunaOrigemOctaedro, TAMANHO_OCTAEDRO);
    printf("Tabuleiro com habilidade Octaedro aplicada em (%d, %d):\n", linhaOrigemOctaedro, colunaOrigemOctaedro);
    exibirTabuleiro(tabuleiroComOctaedro);

    return 0;
}