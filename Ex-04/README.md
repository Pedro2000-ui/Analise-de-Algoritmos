# Problema do Troco — Algoritmo Guloso

O **problema do troco** consiste em, dado um valor, determinar a menor quantidade de moedas necessárias para compô-lo, utilizando um conjunto fixo de moedas disponíveis.

## Estratégia

Este programa utiliza um **algoritmo guloso (greedy)**, que escolhe sempre a **maior moeda possível** para cada passo. Embora essa abordagem não garanta a solução ótima em todos os cenários (em moedas não padronizadas), **funciona perfeitamente com moedas brasileiras ou americanas**.

### Exemplo de moedas utilizadas:
- 1 real (100 centavos)
- 50 centavos
- 25 centavos
- 10 centavos
- 5 centavos
- 1 centavo

## Funcionamento

1. Recebe do usuário o valor do troco (em centavos).
2. Para cada tipo de moeda, calcula quantas podem ser usadas sem ultrapassar o valor.
3. Subtrai esse valor e repete até o troco ser 0.

## Exemplo de Entrada
```c
Digite o valor do troco (em centavos): 287
```

## Saída
```c
Troco para 287 centavos:
2 moeda(s) de 100 centavo(s)
1 moeda(s) de 50 centavo(s)
1 moeda(s) de 25 centavo(s)
1 moeda(s) de 10 centavo(s)
0 moeda(s) de 5 centavo(s)
2 moeda(s) de 1 centavo(s)
```