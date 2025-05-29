#include <stdio.h>

#define TAM 8

int tabuleiro[TAM][TAM];

// Verifica se é possível colocar uma rainha na posição (linha, coluna)
int podeColocar(int linha, int coluna) {
    int i, j;

    // Verificar coluna acima
    for (i = 0; i < linha; i++)
        if (tabuleiro[i][coluna])
            return 0;

    // Verificar diagonal superior esquerda
    for (i = linha - 1, j = coluna - 1; i >= 0 && j >= 0; i--, j--)
        if (tabuleiro[i][j])
            return 0;

    // Verificar diagonal superior direita
    for (i = linha - 1, j = coluna + 1; i >= 0 && j < TAM; i--, j++)
        if (tabuleiro[i][j])
            return 0;

    return 1;
}

// Tenta resolver o problema a partir de uma linha
int resolver(int linha) {
    if (linha == TAM)
        return 1;

    for (int col = 0; col < TAM; col++) {
        if (podeColocar(linha, col)) {
            tabuleiro[linha][col] = 1;

            if (resolver(linha + 1))
                return 1;

            // Backtrack
            tabuleiro[linha][col] = 0;
        }
    }

    return 0;
}

// Exibe o tabuleiro na tela
void mostrarTabuleiro() {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j])
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

int main() {
    if (resolver(0))
        mostrarTabuleiro();
    else
        printf("Não foi possível encontrar uma solução.\n");

    return 0;
}
