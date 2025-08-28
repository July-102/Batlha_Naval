#include <stdio.h>
#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5
void criarCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++)
        for (int j = 0; j < TAM_HABILIDADE; j++)
            matriz[i][j] = 0;
    matriz[0][2] = 3;
    matriz[1][1] = matriz[1][2] = matriz[1][3] = 3;
    for (int j = 0; j < TAM_HABILIDADE; j++) matriz[2][j] = 3;
}
void criarCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++)
        for (int j = 0; j < TAM_HABILIDADE; j++)
            matriz[i][j] = 0;
    int c = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        matriz[i][c] = 2;
        matriz[c][i] = 2;
    }
}
void criarOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++)
        for (int j = 0; j < TAM_HABILIDADE; j++)
            matriz[i][j] = 0;
    int c = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++)
        for (int j = 0; j < TAM_HABILIDADE; j++)
            if ((i >= c ? i - c : c - i) + (j >= c ? j - c : c - j) <= c)
                matriz[i][j] = 1;
}
// Inicializa o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++)
        for (int j = 0; j < TAM_TABULEIRO; j++)
            tabuleiro[i][j] = 0;
}
// Aplica habilidade sem sobrepor
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemLinha, int origemColuna) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int x = origemLinha - TAM_HABILIDADE / 2 + i;
            int y = origemColuna - TAM_HABILIDADE / 2 + j;
            if (x >= 0 && x < TAM_TABULEIRO && y >= 0 && y < TAM_TABULEIRO)
                if (habilidade[i][j] != 0 && tabuleiro[x][y] == 0)
                    tabuleiro[x][y] = habilidade[i][j];
        }
    }
}
// Exibe o tabuleiro com eixos
void exibirTabuleiroComEixos(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("   ");
    for (int j = 0; j < TAM_TABULEIRO; j++) printf("%d ", j);
    printf("\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%d  ", i);
        for (int j = 0; j < TAM_TABULEIRO; j++)
            printf("%d ", tabuleiro[i][j]);
        printf("\n");
    }
    printf("\n");
}
int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    inicializarTabuleiro(tabuleiro);
    criarCone(cone);
    aplicarHabilidade(tabuleiro, cone, 2, 2);       // Cone com vértice visível
    criarCruz(cruz);
    aplicarHabilidade(tabuleiro, cruz, 2, 7);       // Cruz no canto superior direito
    criarOctaedro(octaedro);
    aplicarHabilidade(tabuleiro, octaedro, 7, 2);   // Octaedro no canto inferior esquerdo
    exibirTabuleiroComEixos(tabuleiro);
    return 0;
}