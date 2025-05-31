#include <stdio.h>
#include <string.h>

int mochila_recursiva(int pesos[], int valores[], int n, int capacidade) {
    if (n == 0 || capacidade == 0) return 0;

    if (pesos[n - 1] > capacidade)
        return mochila_recursiva(pesos, valores, n - 1, capacidade);

    int inclui = valores[n - 1] + mochila_recursiva(pesos, valores, n - 1, capacidade - pesos[n - 1]);
    int exclui = mochila_recursiva(pesos, valores, n - 1, capacidade);

    return (inclui > exclui) ? inclui : exclui;
}

int mochila_topdown_aux(int pesos[], int valores[], int n, int capacidade, int memo[][capacidade + 1]) {
    if (n == 0 || capacidade == 0) return 0;

    if (memo[n][capacidade] != -1) return memo[n][capacidade];

    if (pesos[n - 1] > capacidade)
        return memo[n][capacidade] = mochila_topdown_aux(pesos, valores, n - 1, capacidade, memo);

    int inclui = valores[n - 1] + mochila_topdown_aux(pesos, valores, n - 1, capacidade - pesos[n - 1], memo);
    int exclui = mochila_topdown_aux(pesos, valores, n - 1, capacidade, memo);

    return memo[n][capacidade] = (inclui > exclui) ? inclui : exclui;
}

int mochila_topdown(int pesos[], int valores[], int n, int capacidade) {
    int memo[n + 1][capacidade + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= capacidade; j++)
            memo[i][j] = -1;

    return mochila_topdown_aux(pesos, valores, n, capacidade, memo);
}

int mochila_bottomup(int pesos[], int valores[], int n, int capacidade) {
    int dp[n + 1][capacidade + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacidade; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (pesos[i - 1] <= w)
                dp[i][w] = (valores[i - 1] + dp[i - 1][w - pesos[i - 1]] > dp[i - 1][w])
                           ? valores[i - 1] + dp[i - 1][w - pesos[i - 1]]
                           : dp[i - 1][w];
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][capacidade];
}

int main() {
    int pesos[] = {1, 3, 4, 5};
    int valores[] = {10, 40, 50, 70};
    int n = sizeof(pesos) / sizeof(pesos[0]);
    int capacidade = 8;

    printf("Recursiva: %d\n", mochila_recursiva(pesos, valores, n, capacidade));
    printf("Top-Down: %d\n", mochila_topdown(pesos, valores, n, capacidade));
    printf("Bottom-Up: %d\n", mochila_bottomup(pesos, valores, n, capacidade));

    return 0;
}
