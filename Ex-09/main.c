#include <stdio.h>

int fibonacci_recursivo(int n)
{
    if (n <= 1)
        return n;
    return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2);
}

int memo[1000]; // Assumindo n pequeno

int fibonacci_topdown(int n)
{
    if (n <= 1)
        return n;
    if (memo[n] != -1)
        return memo[n];
    return memo[n] = fibonacci_topdown(n - 1) + fibonacci_topdown(n - 2);
}

int fibonacci_bottomup(int n)
{
    if (n <= 1)
        return n;

    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    return fib[n];
}

int fibonacci_iterativo(int n)
{
    if (n <= 1)
        return n;

    int a = 0, b = 1, c;

    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main()
{
    int n;
    printf("Digite um valor para n: ");
    scanf("%d", &n);

    printf("Recursivo: %d\n", fibonacci_recursivo(n));

    for (int i = 0; i < 1000; i++)
        memo[i] = -1;
    printf("Top-Down: %d\n", fibonacci_topdown(n));

    printf("Bottom-Up: %d\n", fibonacci_bottomup(n));

    printf("Iterativo 3 variaveis: %d\n", fibonacci_iterativo(n));

    return 0;
}
