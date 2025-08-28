#include <stdio.h>
#define TAM 10         // Tamanho do tabuleiro (10x10)
#define NAVIO 3        // Valor que representa um navio
#define TAM_NAVIO 3    // Tamanho fixo dos navios
int main() {
    // 1. Criando o Tabuleiro
    char colunas[TAM] = {'A','B','C','D','E','F','G','H','I','J'};
    int tab[TAM][TAM];
    // 2. Inicializando o tabuleiro com água (valor 0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tab[i][j] = 0;
        }
    }
    // 3. Posicionando os navios (tamanho fixo = 3)
    // Horizontal — começa em linha 4, coluna 2 (C5)
    for (int j = 0; j < TAM_NAVIO; j++) tab[4][2 + j] = NAVIO;
    // Vertical — começa em linha 5, coluna 7
    for (int i = 0; i < TAM_NAVIO; i++) tab[5 + i][7] = NAVIO;
    // Diagonal principal (↘) — começa em (0,0)
    for (int i = 0; i < TAM_NAVIO; i++) tab[i][i] = NAVIO;
    // Diagonal secundária (↙) — começa em (0,9)
    for (int i = 0; i < TAM_NAVIO; i++) tab[i][TAM - 1 - i] = NAVIO;
    // 4. Exibindo o tabuleiro com cabeçalho alfabético
    printf("TABULEIRO BATALHA NAVAL\n\n    ");
    for (int j = 0; j < TAM; j++) {
        printf(" %c ", colunas[j]);
    }
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        printf("%2d |", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf(" %d ", tab[i][j]);
        }
        printf("\n");
    }
    return 0;
}