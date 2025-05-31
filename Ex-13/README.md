# 🧮 Multiplicação de Matrizes em C

Este projeto apresenta implementações da multiplicação de matrizes em C usando diferentes abordagens:

---

## 📘 Versão Recursiva

Multiplica diretamente duas matrizes de forma recursiva, simulando os laços com chamadas aninhadas.

- Não é eficiente para grandes matrizes.
- Útil para compreensão de recursão.

---

## 🧠 Versão Top-Down (Memoização)

Aplica-se à **cadeia ótima de multiplicação de matrizes**, onde se busca a ordem ótima para multiplicar várias matrizes minimizando o número de multiplicações.

- Utiliza memoização para evitar recomputações.
- Complexidade: `O(n^3)` com `O(n^2)` de espaço.

---

## 📗 Versão Bottom-Up

Implementa a multiplicação iterativa de duas matrizes com três laços aninhados.

- Método tradicional e eficiente.
- Complexidade: `O(m × n × p)` onde:
  - `A` é m × n
  - `B` é n × p
  - `C` será m × p

---

## 🧪 Exemplo

Multiplicando:
```c
A = [1 2]
    [3 4]

B = [5 6]
    [7 8]
```

Resultado:
```c
C = [19 22]
    [43 50]
```

