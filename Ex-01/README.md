# Gerador de Subconjuntos com Backtracking em C

Este projeto em C demonstra a geração de **todos os subconjuntos possíveis** de um conjunto de inteiros usando a técnica de **backtracking**.

## 🧠 Lógica

A cada posição do vetor de entrada, o algoritmo decide:

- **Incluir** ou
- **Não incluir** o elemento no subconjunto atual.

Esse processo é feito recursivamente, gerando todas as combinações possíveis (inclusive o subconjunto vazio `{}`).
