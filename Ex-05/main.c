#include <stdio.h>

#define MAX 100

typedef struct {
    int peso;
    int valor;
} Item;

void ordenarPorRazao(Item itens[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            float r1 = (float)itens[i].valor / itens[i].peso;
            float r2 = (float)itens[j].valor / itens[j].peso;
            if (r1 < r2) {
                Item temp = itens[i];
                itens[i] = itens[j];
                itens[j] = temp;
            }
        }
    }
}

float mochilaFracionaria(Item itens[], int n, int capacidade) {
    ordenarPorRazao(itens, n);

    float valorTotal = 0.0;
    int pesoAtual = 0;

    for (int i = 0; i < n && pesoAtual < capacidade; i++) {
        if (pesoAtual + itens[i].peso <= capacidade) {
            valorTotal += itens[i].valor;
            pesoAtual += itens[i].peso;
        } else {
            int restante = capacidade - pesoAtual;
            valorTotal += (float)itens[i].valor * restante / itens[i].peso;
            pesoAtual = capacidade;
        }
    }

    return valorTotal;
}

int main() {
    int n, capacidade;
    Item itens[MAX];

    printf("Quantidade de itens: ");
    scanf("%d", &n);

    printf("Capacidade da mochila: ");
    scanf("%d", &capacidade);

    for (int i = 0; i < n; i++) {
        printf("Item %d (peso valor): ", i + 1);
        scanf("%d %d", &itens[i].peso, &itens[i].valor);
    }

    float resultado = mochilaFracionaria(itens, n, capacidade);
    printf("Valor máximo que pode ser obtido: %.2f\n", resultado);

    return 0;
}
