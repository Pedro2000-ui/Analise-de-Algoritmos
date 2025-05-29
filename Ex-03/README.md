# Problema das 8 Rainhas

O **problema das 8 rainhas** é um clássico da computação e do xadrez. O desafio consiste em posicionar 8 rainhas em um tabuleiro de xadrez 8x8 de forma que nenhuma delas ataque outra.

Como as rainhas podem se mover na horizontal, vertical e diagonais, a solução exige que:

- Nenhuma rainha esteja na mesma linha;
- Nenhuma rainha esteja na mesma coluna;
- Nenhuma rainha esteja na mesma diagonal.

## Estratégia Usada

Este programa em C utiliza o **backtracking** para resolver o problema. A ideia é tentar posicionar uma rainha por linha e voltar (retroceder) se uma posição levar a um estado inválido.

O algoritmo:

1. Começa na primeira linha.
2. Tenta colocar uma rainha em cada coluna da linha.
3. Se a posição for segura, coloca a rainha e vai para a próxima linha.
4. Se não conseguir colocar em nenhuma coluna, volta para a linha anterior (backtrack).
5. Repete até colocar todas as 8 rainhas no tabuleiro.

## Exemplo de Saída

```c
Q . . . . . . .
. . . . Q . . .
. . . . . . . Q
. . . . . Q . .
. . Q . . . . .
. . . . . . Q .
. Q . . . . . .
. . . Q . . . .