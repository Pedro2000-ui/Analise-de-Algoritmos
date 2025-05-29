#include <stdio.h>

#define MAX 100

int selecionarParadas(int distancias[], int n, int capacidade) {
    int paradas = 0;
    int atual = 0;

    while (atual < n - 1) {
        int proxima = atual;
        
        // Procura o posto mais distante possível dentro da autonomia
        while (proxima + 1 < n && distancias[proxima + 1] - distancias[atual] <= capacidade) {
            proxima++;
        }

        if (proxima == atual) {
            // Não é possível avançar
            return -1;
        }

        if (proxima < n - 1)
            printf("Parada em: %d km\n", distancias[proxima]);

        atual = proxima;
        paradas++;
    }

    return paradas;
}

int main() {
    int capacidade, n;

    printf("Capacidade máxima do tanque (km): ");
    scanf("%d", &capacidade);

    printf("Número de postos (incluindo início e destino): ");
    scanf("%d", &n);

    int distancias[MAX];
    printf("Digite as distâncias dos postos (em ordem crescente):\n");
    for (int i = 0; i < n; i++) {
        printf("Posto %d: ", i);
        scanf("%d", &distancias[i]);
    }

    int resultado = selecionarParadas(distancias, n, capacidade);

    if (resultado != -1)
        printf("Total de paradas necessárias: %d\n", resultado);
    else
        printf("Não é possível completar o trajeto com essa autonomia.\n");

    return 0;
}
