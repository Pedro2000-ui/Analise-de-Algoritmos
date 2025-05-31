#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

typedef struct Graph
{
    int numVertices;
    Node *adjLists[MAX_VERTICES];
    int visited[MAX_VERTICES];
} Graph;

// Cria um novo nó da lista de adjacência
Node *criarNo(int v)
{
    Node *novoNo = (Node *)malloc(sizeof(Node));
    novoNo->vertex = v;
    novoNo->next = NULL;
    return novoNo;
}

// Cria um grafo com V vértices
Graph *criarGrafo(int vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Adiciona aresta direcionada de src para dest
void adicionarAresta(Graph *graph, int src, int dest)
{
    Node *novoNo = criarNo(dest);
    novoNo->next = graph->adjLists[src];
    graph->adjLists[src] = novoNo;
}

// Pilha para armazenar ordenação topológica
typedef struct Stack
{
    int items[MAX_VERTICES];
    int topo;
} Stack;

void criarPilha(Stack *pilha)
{
    pilha->topo = -1;
}

int pilhaVazia(Stack *pilha)
{
    return pilha->topo == -1;
}

void push(Stack *pilha, int item)
{
    pilha->items[++pilha->topo] = item;
}

int pop(Stack *pilha)
{
    if (pilhaVazia(pilha))
    {
        return -1; // pilha vazia
    }
    return pilha->items[pilha->topo--];
}

// Função recursiva DFS para ordenação topológica
void ordenarTopologicoDFS(Graph *graph, int v, Stack *pilha)
{
    graph->visited[v] = 1;

    Node *temp = graph->adjLists[v];
    while (temp != NULL)
    {
        int adjV = temp->vertex;
        if (!graph->visited[adjV])
            ordenarTopologicoDFS(graph, adjV, pilha);
        temp = temp->next;
    }

    push(pilha, v); // adiciona vértice na pilha após visitar seus adjacentes
}

// Função principal que executa a ordenação topológica
void ordenacaoTopologica(Graph *graph)
{
    Stack pilha;
    criarPilha(&pilha);

    for (int i = 0; i < graph->numVertices; i++)
    {
        if (!graph->visited[i])
            ordenarTopologicoDFS(graph, i, &pilha);
    }

    printf("Ordenacao Topologica: ");
    while (!pilhaVazia(&pilha))
    {
        printf("%d ", pop(&pilha));
    }
    printf("\n");
}

// Main para testar o algoritmo
int main()
{
    // Exemplo de grafo com 6 vértices (0 a 5)
    Graph *graph = criarGrafo(6);

    // Adicionando as arestas
    adicionarAresta(graph, 5, 2);
    adicionarAresta(graph, 5, 0);
    adicionarAresta(graph, 4, 0);
    adicionarAresta(graph, 4, 1);
    adicionarAresta(graph, 2, 3);
    adicionarAresta(graph, 3, 1);

    ordenacaoTopologica(graph);

    // Liberar memória (não obrigatório aqui, mas boa prática)
    for (int i = 0; i < graph->numVertices; i++)
    {
        Node *temp = graph->adjLists[i];
        while (temp != NULL)
        {
            Node *aux = temp;
            temp = temp->next;
            free(aux);
        }
    }
    free(graph);

    return 0;
}
