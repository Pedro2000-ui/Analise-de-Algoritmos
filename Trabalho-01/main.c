#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXN 200005

int t[MAXN];            // t[i]: destino do planeta i
int memo[MAXN];         // memo[i]: armazena f(i) (para memoization)
int visited[MAXN];      // usado na recursiva para detectar ciclos
int result[MAXN];       // resultado final (para bottom-up)
int n;

// ------------------- Recursiva Pura -------------------
int f_rec(int i) {
    if (visited[i]) return 0; // já visitado, ciclo detectado
    visited[i] = 1;
    return 1 + f_rec(t[i]);
}

// ------------------- Top-Down com Memoization -------------------
int f_topdown(int i) {
    if (memo[i]) return memo[i];
    memo[i] = -1; // marca como em processamento
    memo[i] = 1 + f_topdown(t[i]);
    return memo[i];
}

// ------------------- Bottom-Up com Tabulação -------------------
void f_bottomup() {
    memset(result, 0, sizeof(result));
    for (int i = 1; i <= n; i++) {
        if (result[i]) continue;

        int path[MAXN], len = 0;
        int x = i;

        while (!result[x] && result[x] != -1) {
            path[len++] = x;
            result[x] = -1; // visitado em processamento
            x = t[x];
        }

        int count = result[x] == -1 ? 0 : result[x];
        for (int j = len - 1; j >= 0; j--) {
            result[path[j]] = ++count;
        }
    }
}

// ------------------- Testes e Medição de Tempo -------------------
void reset_globals() {
    memset(memo, 0, sizeof(memo));
    memset(visited, 0, sizeof(visited));
    memset(result, 0, sizeof(result));
}

void test_case(const char *label, int use_n) {
    printf("\n===== %s =====\n", label);

    reset_globals();

    clock_t start, end;

    // Recursiva pura (usando visited)
    start = clock();
    for (int i = 1; i <= use_n; i++) {
        memset(visited, 0, sizeof(int) * (use_n + 1));
        printf("%d ", f_rec(i));
    }
    end = clock();
    printf("\nRecursiva pura: %.6f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Top-down com memoization
    reset_globals();
    start = clock();
    for (int i = 1; i <= use_n; i++) {
        printf("%d ", f_topdown(i));
    }
    end = clock();
    printf("\nTop-down: %.6f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Bottom-up
    reset_globals();
    start = clock();
    f_bottomup();
    for (int i = 1; i <= use_n; i++) {
        printf("%d ", result[i]);
    }
    end = clock();
    printf("\nBottom-up: %.6f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);
}

int main() {
    // Teste pequeno
    n = 5;
    int small[] = {0, 2, 4, 3, 1, 4}; // índice começa em 1
    memcpy(t, small, sizeof(small));
    test_case("Teste Pequeno", n);

    // Teste grande
    n = 100;
    for (int i = 1; i <= n; i++) {
        t[i] = (i % n) + 1;
    }
    test_case("Teste Grande", n);

    return 0;
}