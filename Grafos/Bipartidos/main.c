#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define SEMCOR 0
#define VERMELHO 1
#define AZUL 2

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_VERTICES];
} Graph;

typedef struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

// Funções para fila
void criarFila(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int filaVazia(Queue* q) {
    return q->front == -1;
}

void enfileirar(Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1)
        return; // fila cheia
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int desenfileirar(Queue* q) {
    if (filaVazia(q))
        return -1;
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

// Cria nó da lista de adjacência
Node* criarNo(int v) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->vertex = v;
    novoNo->next = NULL;
    return novoNo;
}

// Cria grafo
Graph* criarGrafo(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
    return graph;
}

// Adiciona aresta não direcionada
void adicionarAresta(Graph* graph, int src, int dest) {
    // src para dest
    Node* novoNo = criarNo(dest);
    novoNo->next = graph->adjLists[src];
    graph->adjLists[src] = novoNo;
    // dest para src
    novoNo = criarNo(src);
    novoNo->next = graph->adjLists[dest];
    graph->adjLists[dest] = novoNo;
}

// Imprime o grafo (lista de adjacência)
void imprimirGrafo(Graph* graph) {
    printf("Grafo (lista de adjacência):\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        Node* temp = graph->adjLists[i];
        while (temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Verifica se o grafo é bipartido usando BFS
int ehBipartido(Graph* graph) {
    int* cores = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++)
        cores[i] = SEMCOR;

    Queue q;
    criarFila(&q);

    for (int start = 0; start < graph->numVertices; start++) {
        if (cores[start] == SEMCOR) {
            cores[start] = VERMELHO;
            enfileirar(&q, start);

            while (!filaVazia(&q)) {
                int u = desenfileirar(&q);
                Node* temp = graph->adjLists[u];
                while (temp != NULL) {
                    int v = temp->vertex;
                    if (cores[v] == SEMCOR) {
                        cores[v] = (cores[u] == VERMELHO) ? AZUL : VERMELHO;
                        enfileirar(&q, v);
                    } else if (cores[v] == cores[u]) {
                        free(cores);
                        return 0; // não bipartido
                    }
                    temp = temp->next;
                }
            }
        }
    }

    free(cores);
    return 1; // bipartido
}

int main() {
    Graph* graph = criarGrafo(6);

    adicionarAresta(graph, 0, 1);
    adicionarAresta(graph, 1, 2);
    adicionarAresta(graph, 2, 3);
    adicionarAresta(graph, 3, 4);
    adicionarAresta(graph, 4, 5);
    adicionarAresta(graph, 5, 0); // ciclo ímpar

    imprimirGrafo(graph);

    if (ehBipartido(graph)) {
        printf("O grafo é bipartido.\n");
    } else {
        printf("O grafo NÃO é bipartido.\n");
    }

    // Libera memória
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp != NULL) {
            Node* aux = temp;
            temp = temp->next;
            free(aux);
        }
    }
    free(graph);

    return 0;
}
