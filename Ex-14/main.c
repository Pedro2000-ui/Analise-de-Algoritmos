#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int lcsRecursivo(char *X, char *Y, int m, int n) {
    if (m == 0 || n == 0)
        return 0;

    if (X[m - 1] == Y[n - 1])
        return 1 + lcsRecursivo(X, Y, m - 1, n - 1);
    else
        return lcsRecursivo(X, Y, m - 1, n) > lcsRecursivo(X, Y, m, n - 1) ?
               lcsRecursivo(X, Y, m - 1, n) : lcsRecursivo(X, Y, m, n - 1);
}


int memo[MAX][MAX];

int lcsTopDown(char *X, char *Y, int m, int n) {
    if (m == 0 || n == 0)
        return 0;

    if (memo[m][n] != -1)
        return memo[m][n];

    if (X[m - 1] == Y[n - 1])
        return memo[m][n] = 1 + lcsTopDown(X, Y, m - 1, n - 1);
    else
        return memo[m][n] = (lcsTopDown(X, Y, m - 1, n) > lcsTopDown(X, Y, m, n - 1) ?
                             lcsTopDown(X, Y, m - 1, n) : lcsTopDown(X, Y, m, n - 1));
}


int lcsBottomUp(char *X, char *Y, int m, int n, char *lcs) {
    int dp[m + 1][n + 1];

    // Construindo a tabela
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
        }
    }

    // Reconstruindo a LCS
    int len = dp[m][n];
    lcs[len] = '\0'; 

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[len - 1] = X[i - 1];
            i--; j--; len--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return dp[m][n];
}


int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);

    printf("Recursiva: \n");
    printf("Tamanho da LCS: %d\n\n", lcsRecursivo(X, Y, m, n));

    printf("Top-Down: \n");
    memset(memo, -1, sizeof(memo));
    printf("Tamanho da LCS: %d\n\n", lcsTopDown(X, Y, m, n));

    printf("Bottom-Up: \n");
    char resultadoLCS[MAX];
    int len = lcsBottomUp(X, Y, m, n, resultadoLCS);
    printf("Tamanho da LCS: %d\n", len);
    printf("Subsequencia comum: %s\n", resultadoLCS);

    return 0;
}
