# Ordenação Topológica em Grafos (Topological Sort)

## Descrição

A ordenação topológica é um algoritmo aplicado em grafos direcionados acíclicos (DAG) que produz uma sequência linear dos vértices, respeitando as dependências representadas pelas arestas. Ou seja, para cada aresta (u → v), o vértice u aparece antes de v na ordenação.

Este projeto implementa a ordenação topológica utilizando uma busca em profundidade (DFS) e uma pilha para armazenar a sequência dos vértices.

## Como funciona

- O grafo é representado por uma lista de adjacência.
- Fazemos uma visita DFS para cada vértice não visitado.
- Após visitar todos os vértices adjacentes de um nó, o nó é empilhado.
- No final, ao desempilhar, obtemos a ordenação topológica.

# Observações
- O algoritmo só funciona corretamente se o grafo não contiver ciclos.
- É possível adaptar a estrutura para trabalhar com grafos maiores alterando a constante MAX_VERTICES.