#include <stdio.h>
#include <string.h>
#include <limits.h>

int troco_recursivo(int moedas[], int n, int valor) {
    if (valor == 0) return 0;
    if (valor < 0) return INT_MAX;

    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        int res = troco_recursivo(moedas, n, valor - moedas[i]);
        if (res != INT_MAX && res + 1 < min) {
            min = res + 1;
        }
    }

    return min;
}

int troco_topdown(int moedas[], int n, int valor, int memo[]) {
    if (valor == 0) return 0;
    if (valor < 0) return INT_MAX;

    if (memo[valor] != -1) return memo[valor];

    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        int res = troco_topdown(moedas, n, valor - moedas[i], memo);
        if (res != INT_MAX && res + 1 < min) {
            min = res + 1;
        }
    }

    memo[valor] = min;
    return min;
}

int troco_bottomup(int moedas[], int n, int valor) {
    int dp[valor + 1];
    for (int i = 0; i <= valor; i++) dp[i] = INT_MAX;
    dp[0] = 0;

    for (int i = 1; i <= valor; i++) {
        for (int j = 0; j < n; j++) {
            if (moedas[j] <= i && dp[i - moedas[j]] != INT_MAX) {
                if (dp[i] > dp[i - moedas[j]] + 1) {
                    dp[i] = dp[i - moedas[j]] + 1;
                }
            }
        }
    }

    return dp[valor];
}

int main() {
    int moedas[] = {1, 3, 4, 5, 6};
    int n = sizeof(moedas) / sizeof(moedas[0]);
    int valor = 10;

    printf("Recursivo: %d\n", troco_recursivo(moedas, n, valor));

    int memo[valor + 1];
    for (int i = 0; i <= valor; i++) memo[i] = -1;
    printf("Top-Down: %d\n", troco_topdown(moedas, n, valor, memo));

    printf("Bottom-Up: %d\n", troco_bottomup(moedas, n, valor));

    return 0;
}
