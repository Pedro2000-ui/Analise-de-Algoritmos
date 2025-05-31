#include <stdio.h>
#include <string.h>

#define MAX 1000
int memo[MAX][MAX];

int lis_recursiva(int arr[], int n, int prev, int index) {
    if (index == n) return 0;

    // Ignora o elemento atual
    int exclui = lis_recursiva(arr, n, prev, index + 1);

    // Inclui o elemento atual se for maior que o anterior
    int inclui = 0;
    if (prev == -1 || arr[index] > arr[prev]) {
        inclui = 1 + lis_recursiva(arr, n, index, index + 1);
    }

    return (inclui > exclui) ? inclui : exclui;
}

int lis_topdown(int arr[], int n, int prev, int index) {
    if (index == n) return 0;

    if (memo[prev + 1][index] != -1)
        return memo[prev + 1][index];

    int exclui = lis_topdown(arr, n, prev, index + 1);

    int inclui = 0;
    if (prev == -1 || arr[index] > arr[prev]) {
        inclui = 1 + lis_topdown(arr, n, index, index + 1);
    }

    memo[prev + 1][index] = (inclui > exclui) ? inclui : exclui;
    return memo[prev + 1][index];
}

int lis_bottomup(int arr[], int n) {
    int lis[n];
    for (int i = 0; i < n; i++)
        lis[i] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    int max = lis[0];
    for (int i = 1; i < n; i++) {
        if (lis[i] > max) {
            max = lis[i];
        }
    }

    return max;
}

int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 70, 95, 104, 12, 85};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Recursiva: %d\n", lis_recursiva(arr, n, -1, 0));

    memset(memo, -1, sizeof(memo));
    printf("Top-Down: %d\n", lis_topdown(arr, n, -1, 0));

    printf("Bottom-Up: %d\n", lis_bottomup(arr, n));

    return 0;
}