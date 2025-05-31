#include <stdio.h>
#include <limits.h>
#include <string.h>
int memo[100][100];

void multiplicarRecursivo(int A[][10], int B[][10], int C[][10], int i, int j, int k, int m, int n, int p)
{
    if (i >= m)
        return;
    if (j >= p)
    {
        multiplicarRecursivo(A, B, C, i + 1, 0, 0, m, n, p);
        return;
    }
    if (k < n)
    {
        C[i][j] += A[i][k] * B[k][j];
        multiplicarRecursivo(A, B, C, i, j, k + 1, m, n, p);
    }
    else
    {
        multiplicarRecursivo(A, B, C, i, j + 1, 0, m, n, p);
    }
}

void multiplicarBottomUp(int A[][10], int B[][10], int C[][10], int m, int n, int p)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int cadeiaTopDown(int p[], int i, int j)
{
    if (i == j)
        return 0;
    if (memo[i][j] != -1)
        return memo[i][j];

    int min = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int custo = cadeiaTopDown(p, i, k) + cadeiaTopDown(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        if (custo < min)
            min = custo;
    }
    return memo[i][j] = min;
}

void imprimirMatriz(int C[][10], int m, int p)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            printf("%4d ", C[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int A[2][10] = {
        {1, 2},
        {3, 4}};
    int B[2][10] = {
        {5, 6},
        {7, 8}};

    int C[2][10] = {0};

    printf("Recursiva:\n");
    multiplicarRecursivo(A, B, C, 0, 0, 0, 2, 2, 2);
    imprimirMatriz(C, 2, 2);

    int C2[2][10] = {0};
    printf("\nBottom-Up:\n");
    multiplicarBottomUp(A, B, C2, 2, 2, 2);
    imprimirMatriz(C2, 2, 2);

    // Cadeia ótima de multiplicação (top-down)
    int dimensoes[] = {2, 3, 4, 2}; // Exemplo: A 2x3, B 3x4, C 4x2
    memset(memo, -1, sizeof(memo));
    int n = sizeof(dimensoes) / sizeof(dimensoes[0]) - 1;

    printf("\nTop-Down:\n");
    int custoMinimo = cadeiaTopDown(dimensoes, 1, n);
    printf("Custo minimo de multiplicacoes: %d\n", custoMinimo);

    return 0;
}
