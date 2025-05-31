# Algoritmo de Kosaraju para Componentes Fortemente Conexos (SCC)

## Descrição

Este projeto implementa o algoritmo de Kosaraju para encontrar os componentes fortemente conexos (SCCs) em um grafo dirigido. 

Um **componente fortemente conexo** é um subconjunto de vértices de um grafo dirigido, onde cada vértice é alcançável a partir de qualquer outro vértice do mesmo subconjunto.

O algoritmo de Kosaraju consiste em:

1. Realizar uma DFS no grafo original para obter a ordem dos vértices baseada no tempo de término.
2. Gerar o grafo transposto (inverter todas as arestas).
3. Realizar DFS no grafo transposto, visitando os vértices na ordem inversa da pilha obtida na etapa 1, para identificar as SCCs.

## Exemplo de Saída

```c
Grafo (lista de adjacência):
0: 1
1: 2
2: 3 0
3: 4
4: 5
5: 3
6: 7 5
7: 6

Componentes fortemente conexos (SCCs):
0 2 1
3 5 4
6 7
```