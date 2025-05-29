# Algoritmos de Fibonacci em C

Este projeto contém **quatro versões** do cálculo da sequência de Fibonacci, utilizando diferentes abordagens computacionais.

## 📘 O que é a sequência de Fibonacci?

A sequência de Fibonacci é uma série de números onde cada número é a soma dos dois anteriores. Os primeiros termos são:
```c
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
```

Ou seja:
```c
F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2), para n > 1
```

---

## 🔢 Versões Implementadas

### 1. Recursiva Simples

```c
int fibonacci_recursivo(int n) {
    if (n <= 1) return n;
    return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2);
}
```

- Vantagens: Código simples e direto.
- Desvantagens: Recalcula muitos valores; ineficiente para n grandes.
- Complexidade: O(2^n)

# 2. Programação Dinâmica (Top-Down com Memorização)

```c
int fibonacci_topdown(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fibonacci_topdown(n - 1) + fibonacci_topdown(n - 2);
}
```

- Vantagens: Evita recalcular valores.
- Desvantagens: Requer vetor auxiliar.
- Complexidade: O(n)
- Recurso extra: Vetor memo[] inicializado com -1.

# 3. Programação Dinâmica (Bottom-Up)

```c
int fibonacci_bottomup(int n) {
    if (n <= 1) return n;
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    return fib[n];
}
```

- Vantagens: Muito eficiente.
- Desvantagens: Usa vetor do tamanho de n.
- Complexidade: O(n)

# 4. Iterativa com Três Variáveis
```c
int fibonacci_iterativo(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
```
- Vantagens: Espaço constante (O(1)), eficiente.
- Desvantagens: Código um pouco menos intuitivo para iniciantes.
- Complexidade: O(n)

# 📊 Comparação de desempenho

| Versão       | Tempo  | Espaço |
|--------------|--------|--------|
| Recursiva    | O(2^n) | O(n)   |
| Top-Down     | O(n)   | O(n)   |
| Bottom-Up    | O(n)   | O(n)   |
| Iterativa 3v | O(n)   | O(1)   |

# ✅ Conclusão
Cada abordagem possui suas vantagens dependendo do contexto. Para aplicações práticas com muitos cálculos de Fibonacci, recomenda-se a versão iterativa com três variáveis por ser mais eficiente em tempo e memória.