# Sudoku em C (Backtracking)

Este projeto implementa um **resolvedor de Sudoku 9x9** usando a técnica de **backtracking** em linguagem C. Dado um tabuleiro parcialmente preenchido, o algoritmo preenche os espaços vazios de forma a satisfazer todas as regras do Sudoku, e **para na primeira solução encontrada**.

---

## 🧩 Regras do Sudoku

O Sudoku é um jogo de lógica que segue três regras principais:

1. Cada linha deve conter todos os números de 1 a 9, **sem repetições**.
2. Cada coluna deve conter todos os números de 1 a 9, **sem repetições**.
3. Cada um dos nove blocos 3x3 também deve conter todos os números de 1 a 9, **sem repetições**.

---

## 🧠 Como funciona o algoritmo

O algoritmo utiliza **backtracking** para tentar preencher os espaços vazios com valores de 1 a 9:

1. Avança célula por célula.
2. Se a célula já está preenchida, apenas passa para a próxima.
3. Se estiver vazia, testa todos os números possíveis de 1 a 9.
4. Ao encontrar um número válido (que obedece às regras), o número é colocado e o algoritmo continua.
5. Se em algum ponto não for possível prosseguir, ele faz **backtrack** (volta) e tenta outros valores.

---

## ✅ Exemplo de entrada

```c
int tabuleiro[9][9] = {
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
