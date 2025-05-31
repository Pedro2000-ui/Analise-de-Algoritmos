# Algoritmo de Hierholzer - Caminho e Circuito Euleriano em Grafos

## Descrição

Este projeto implementa o algoritmo de Hierholzer para encontrar um caminho ou circuito euleriano em grafos **não dirigidos**.

- Um **circuito euleriano** é um ciclo que percorre todas as arestas exatamente uma vez e retorna ao vértice inicial.
- Um **caminho euleriano** percorre todas as arestas uma única vez, mas não necessariamente retorna ao ponto inicial.

## Como funciona o algoritmo

1. Verifica se o grafo possui caminho ou circuito euleriano:
   - Circuito euleriano: todos os vértices têm grau par.
   - Caminho euleriano: exatamente dois vértices têm grau ímpar.
2. Inicia no vértice adequado (um vértice de grau ímpar se houver caminho euleriano, ou qualquer vértice se for circuito).
3. Percorre as arestas, removendo-as do grafo conforme vai passando por elas.
4. Usa uma pilha para armazenar o caminho atual e outra para o circuito final.
5. Ao final, imprime o caminho/circuito euleriano encontrado.

## Exemplo de saída
```c
Grafo (lista de adjacência):
0: 3 1 
1: 3 2 0 
2: 3 1 
3: 4 1 2 0 
4: 3 

Caminho/Circuito Euleriano encontrado:
0 1 2 3 4 3 1 0 
```

# Observações
- Este código considera grafos não dirigidos.
- Para grafos dirigidos, o algoritmo deve ser adaptado para verificar grau de entrada e saída.