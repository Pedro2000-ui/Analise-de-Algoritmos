#include <stdio.h>

#define N 9

// Imprime o tabuleiro do Sudoku
void mostrar_matriz(int m[N][N]) {
    for (int i = 0; i < N; i++) {
        if (i % 3 == 0 && i != 0) {
            printf("---------------------\n");
        }
        for (int j = 0; j < N; j++) {
            if(j % 3 == 0 && j != 0) {
                printf("| ");
            }
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

// Verifica se é possível colocar um valor na posição
int valor_valido(int valor, int m[N][N], int linha, int coluna) {
    for (int i = 0; i < N; i++) {
        if (m[linha][i] == valor || m[i][coluna] == valor)
            return 0;
    }

    int blocoLinha = (linha / 3) * 3;
    int blocoColuna = (coluna / 3) * 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (m[blocoLinha + i][blocoColuna + j] == valor)
                return 0;
        }
    }

    return 1;
}

// Resolve o Sudoku com backtracking, retornando 1 se resolveu
int sudoku(int m[N][N], int linha, int coluna) {
    if (coluna == N) {
        linha++;
        coluna = 0;
    }

    if (linha == N) {
        mostrar_matriz(m);
        return 1; // Encontrou solução
    }

    if (m[linha][coluna] != 0) {
        return sudoku(m, linha, coluna + 1);
    }

    for (int num = 1; num <= 9; num++) {
        if (valor_valido(num, m, linha, coluna)) {
            m[linha][coluna] = num;

            if (sudoku(m, linha, coluna + 1)) {
                return 1; // Parar após a primeira solução
            }

            m[linha][coluna] = 0; // backtrack
        }
    }

    return 0; // Nenhum número válido aqui
}

int main() {
    int tabuleiro[N][N] = {
        {5,0,0, 0,7,0, 0,0,0},
        {0,0,0, 1,9,5, 0,0,0},
        {0,0,0, 0,0,0, 0,6,0},

        {8,0,0, 0,6,0, 0,0,3},
        {4,0,0, 8,0,3, 0,0,1},
        {7,0,0, 0,2,0, 0,0,6},

        {1,6,0, 0,0,0, 2,8,0},
        {0,0,0, 4,1,9, 0,0,5},
        {0,0,0, 0,8,0, 0,7,9}
    };

    if (!sudoku(tabuleiro, 0, 0)) {
        printf("Nenhuma solução encontrada.\n");
    }

    return 0;
}
