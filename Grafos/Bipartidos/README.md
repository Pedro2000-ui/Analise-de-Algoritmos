# Verificação de Grafo Bipartido

## Descrição

Um grafo é considerado bipartido se seus vértices podem ser divididos em dois conjuntos disjuntos, de forma que todas as arestas conectem vértices de conjuntos diferentes. Em outras palavras, não existe nenhuma aresta que conecte dois vértices do mesmo conjunto.

Este projeto implementa a verificação de grafos bipartidos utilizando uma busca em largura (BFS) para colorir os vértices com duas cores distintas. Se durante o processo for detectada uma aresta entre vértices da mesma cor, o grafo não é bipartido.

## Como funciona

- O grafo é representado por uma lista de adjacência.
- Inicialmente, todos os vértices estão sem cor.
- Para cada componente conexa do grafo, inicia-se uma BFS, colorindo o vértice inicial com a cor RED.
- Cada vizinho recebe a cor oposta à do vértice atual.
- Se for encontrada alguma aresta que conecta vértices da mesma cor, o grafo é declarado não bipartido.

# Observações
- O algoritmo funciona para grafos não direcionados.
- Caso o grafo não contenha ciclos ímpares, será bipartido.
- É possível modificar o número de vértices e as arestas para testar diferentes grafos.
