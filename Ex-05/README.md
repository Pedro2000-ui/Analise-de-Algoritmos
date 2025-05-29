# Problema da Mochila Fracionária — Algoritmo Guloso

O **problema da mochila fracionária** é uma variação do problema clássico da mochila, onde é permitido levar **frações de itens**, em vez de apenas o item inteiro.

## Objetivo

Dado:
- Uma lista de itens, cada um com um **peso** e um **valor**.
- A **capacidade máxima** da mochila.

Queremos **maximizar o valor total** que pode ser colocado na mochila, mesmo que para isso levemos apenas parte de alguns itens.

## Estratégia Usada

Este programa usa um **algoritmo guloso (greedy)**:

1. Calcula a **razão valor/peso** de cada item.
2. Ordena os itens de forma decrescente por essa razão.
3. Insere os itens na mochila começando pelos mais "valiosos por peso".
4. Se o item inteiro não couber, coloca apenas a fração que cabe.

## Exemplo

### Entrada:

```c
Quantidade de itens: 3
Capacidade da mochila: 50
Item 1 (peso valor): 10 60
Item 2 (peso valor): 20 100
Item 3 (peso valor): 30 120
```

## Saída

```c
Valor máximo que pode ser obtido: 240.00
```

### Explicação:

- Leva-se o item 1 inteiro (10kg, R$60).
- Depois o item 2 inteiro (20kg, R$100).
- Por fim, metade do item 3 (15kg, R$60).
- Total: **R$60 + R$100 + R$60 = R$220**.
