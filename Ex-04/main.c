#include <stdio.h>

#define TAM 6

// Moedas disponíveis (em centavos)
int moedas[TAM] = {100, 50, 25, 10, 5, 1};

void darTroco(int valor) {
    printf("Troco para %d centavos:\n", valor);

    for (int i = 0; i < TAM; i++) {
        int qtd = valor / moedas[i];
        if (qtd > 0) {
            printf("%d moeda(s) de %d centavo(s)\n", qtd, moedas[i]);
            valor -= qtd * moedas[i];
        }
    }
}

int main() {
    int valor;

    printf("Digite o valor do troco (em centavos): ");
    scanf("%d", &valor);

    if (valor > 0)
        darTroco(valor);
    else
        printf("Valor inválido.\n");

    return 0;
}
