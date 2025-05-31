#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_VERTICES];
} Graph;

// Função para criar nó da lista de adjacência
Node* criarNo(int v) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->vertex = v;
    novoNo->next = NULL;
    return novoNo;
}

// Cria grafo dirigido
Graph* criarGrafo(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
    return graph;
}

// Adiciona aresta dirigida src -> dest
void adicionarAresta(Graph* graph, int src, int dest) {
    Node* novoNo = criarNo(dest);
    novoNo->next = graph->adjLists[src];
    graph->adjLists[src] = novoNo;
}

// Imprime grafo (lista de adjacência)
void imprimirGrafo(Graph* graph) {
    printf("Grafo (lista de adjacencia):\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        Node* temp = graph->adjLists[i];
        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Pilha para Kosaraju
typedef struct Stack {
    int items[MAX_VERTICES];
    int top;
} Stack;

void criarPilha(Stack* s) {
    s->top = -1;
}

int pilhaVazia(Stack* s) {
    return s->top == -1;
}

void empilhar(Stack* s, int value) {
    if (s->top < MAX_VERTICES - 1)
        s->items[++s->top] = value;
}

int desempilhar(Stack* s) {
    if (!pilhaVazia(s))
        return s->items[s->top--];
    return -1;
}

// DFS para preencher pilha pela ordem de término
void dfs1(Graph* graph, int v, int* visitado, Stack* s) {
    visitado[v] = 1;
    Node* temp = graph->adjLists[v];
    while (temp) {
        if (!visitado[temp->vertex])
            dfs1(graph, temp->vertex, visitado, s);
        temp = temp->next;
    }
    empilhar(s, v);
}

// DFS para visitar o grafo transposto e imprimir SCC
void dfs2(Graph* graphT, int v, int* visitado) {
    visitado[v] = 1;
    printf("%d ", v);
    Node* temp = graphT->adjLists[v];
    while (temp) {
        if (!visitado[temp->vertex])
            dfs2(graphT, temp->vertex, visitado);
        temp = temp->next;
    }
}

// Cria grafo transposto
Graph* transporGrafo(Graph* graph) {
    Graph* graphT = criarGrafo(graph->numVertices);
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            adicionarAresta(graphT, temp->vertex, i);
            temp = temp->next;
        }
    }
    return graphT;
}

// Algoritmo Kosaraju para encontrar SCCs
void kosaraju(Graph* graph) {
    int* visitado = (int*)calloc(graph->numVertices, sizeof(int));
    Stack s;
    criarPilha(&s);

    // 1ª passagem: DFS para preencher a pilha de ordem de término
    for (int i = 0; i < graph->numVertices; i++) {
        if (!visitado[i])
            dfs1(graph, i, visitado, &s);
    }

    // Transpor o grafo
    Graph* graphT = transporGrafo(graph);

    // 2ª passagem: DFS no grafo transposto na ordem da pilha
    for (int i = 0; i < graph->numVertices; i++)
        visitado[i] = 0;

    printf("Componentes fortemente conexos (SCCs):\n");
    while (!pilhaVazia(&s)) {
        int v = desempilhar(&s);
        if (!visitado[v]) {
            dfs2(graphT, v, visitado);
            printf("\n");
        }
    }

    // Libera memória do grafo transposto
    for (int i = 0; i < graphT->numVertices; i++) {
        Node* temp = graphT->adjLists[i];
        while (temp) {
            Node* aux = temp;
            temp = temp->next;
            free(aux);
        }
    }
    free(graphT);
    free(visitado);
}

// Libera memória do grafo original
void liberarGrafo(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* aux = temp;
            temp = temp->next;
            free(aux);
        }
    }
    free(graph);
}

int main() {
    Graph* graph = criarGrafo(8);

    adicionarAresta(graph, 0, 1);
    adicionarAresta(graph, 1, 2);
    adicionarAresta(graph, 2, 0);
    adicionarAresta(graph, 2, 3);
    adicionarAresta(graph, 3, 4);
    adicionarAresta(graph, 4, 5);
    adicionarAresta(graph, 5, 3);
    adicionarAresta(graph, 6, 5);
    adicionarAresta(graph, 6, 7);
    adicionarAresta(graph, 7, 6);

    imprimirGrafo(graph);

    kosaraju(graph);

    liberarGrafo(graph);

    return 0;
}
