#include <stdio.h>
int main() {
    // 1. Criando o Tabuleiro (Matriz 10x10)
    char colunas[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int tab[10][10];
    // 2. Inicializando o tabuleiro com água (valor 0)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) { tab[i][j] = 0;}
    }
    // 3. Posicionando os navios (tamanho fixo = 3)
    for (int j = 0; j < 3; j++) tab[2][1 + j] = 3; // horizontal
    for (int i = 0; i < 3; i++) tab[5 + i][7] = 3; // vertical
    // 4. Exibindo o tabuleiro com cabeçalho numérico
    printf("TABULEIRO BATALHA NAVAL\n\n    ");
    for (int j = 0; j < 10; j++) {
        printf(" %c ", colunas[j]); // Cabeçalho com letras
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("%2d |", i + 1); // Rótulo da linha com número
        for (int j = 0; j < 10; j++) {
            printf(" %d ", tab[i][j]); // Conteúdo da célula
        }
        printf("\n");
    }
    return 0;
}
