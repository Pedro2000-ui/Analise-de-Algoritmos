#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_ARESTAS 200

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_VERTICES];
    int grau[MAX_VERTICES];  // grau de cada vértice
} Graph;

// Criar nó para lista adjacente
Node* criarNo(int v) {
    Node* novoNo = (Node*) malloc(sizeof(Node));
    novoNo->vertex = v;
    novoNo->next = NULL;
    return novoNo;
}

// Criar grafo não dirigido
Graph* criarGrafo(int vertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->grau[i] = 0;
    }
    return graph;
}

// Adiciona aresta não dirigida v1 <-> v2
void adicionarAresta(Graph* graph, int v1, int v2) {
    Node* novoNo = criarNo(v2);
    novoNo->next = graph->adjLists[v1];
    graph->adjLists[v1] = novoNo;
    graph->grau[v1]++;

    novoNo = criarNo(v1);
    novoNo->next = graph->adjLists[v2];
    graph->adjLists[v2] = novoNo;
    graph->grau[v2]++;
}

// Remove uma aresta entre u e v (para não dirigido)
int removerAresta(Graph* graph, int u, int v) {
    // Remove v da lista de u
    Node **p = &graph->adjLists[u];
    while (*p && (*p)->vertex != v) {
        p = &((*p)->next);
    }
    if (*p == NULL) return 0; // aresta não encontrada
    Node* temp = *p;
    *p = temp->next;
    free(temp);
    graph->grau[u]--;

    // Remove u da lista de v
    p = &graph->adjLists[v];
    while (*p && (*p)->vertex != u) {
        p = &((*p)->next);
    }
    if (*p == NULL) return 0;
    temp = *p;
    *p = temp->next;
    free(temp);
    graph->grau[v]--;

    return 1;
}

// Imprime grafo como lista de adjacência
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

// Verifica se o grafo tem caminho ou circuito euleriano
// Retorna:
// 0 = não tem Euleriano
// 1 = caminho euleriano (exatamente 2 vértices de grau ímpar)
// 2 = circuito euleriano (todos graus pares)
int verificaEuleriano(Graph* graph) {
    int impares = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->grau[i] % 2 != 0)
            impares++;
    }
    if (impares == 0) return 2;  // circuito
    else if (impares == 2) return 1;  // caminho
    else return 0; // não tem
}

// Pilha para o algoritmo
typedef struct Stack {
    int items[MAX_ARESTAS * 2];
    int top;
} Stack;

void criarPilha(Stack* s) {
    s->top = -1;
}

int pilhaVazia(Stack* s) {
    return s->top == -1;
}

void empilhar(Stack* s, int value) {
    s->items[++s->top] = value;
}

int desempilhar(Stack* s) {
    if (!pilhaVazia(s))
        return s->items[s->top--];
    return -1;
}

// Algoritmo de Hierholzer para caminho/circuito euleriano
void hierholzer(Graph* graph) {
    int tipo = verificaEuleriano(graph);
    if (tipo == 0) {
        printf("O grafo não possui caminho ou circuito euleriano.\n");
        return;
    }

    // Encontrar vértice inicial
    int start = 0;
    if (tipo == 1) { // caminho euleriano: começa por vértice de grau ímpar
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->grau[i] % 2 != 0) {
                start = i;
                break;
            }
        }
    }

    Stack currPath, circuit;
    criarPilha(&currPath);
    criarPilha(&circuit);

    empilhar(&currPath, start);

    while (!pilhaVazia(&currPath)) {
        int v = currPath.items[currPath.top];
        if (graph->grau[v] == 0) {
            // sem arestas, adiciona no circuito
            desempilhar(&currPath);
            empilhar(&circuit, v);
        } else {
            // segue por uma aresta qualquer
            int u = graph->adjLists[v]->vertex;
            removerAresta(graph, v, u);
            empilhar(&currPath, u);
        }
    }

    printf("Caminho/Circuito Euleriano encontrado:\n");
    while (!pilhaVazia(&circuit)) {
        printf("%d ", desempilhar(&circuit));
    }
    printf("\n");
}

// Libera memória do grafo
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
    Graph* graph = criarGrafo(5);

    adicionarAresta(graph, 0, 1);
    adicionarAresta(graph, 1, 2);
    adicionarAresta(graph, 2, 3);
    adicionarAresta(graph, 3, 0);
    adicionarAresta(graph, 1, 3);
    adicionarAresta(graph, 3, 4);

    imprimirGrafo(graph);
    hierholzer(graph);

    liberarGrafo(graph);

    return 0;
}
