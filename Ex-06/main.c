#include <stdio.h>

int saltoDoSapo(int arr[], int n) {
    int pulos = 0;
    int alcanceAtual = 0;
    int alcanceMaximo = 0;

    for (int i = 0; i < n - 1; i++) {
        if (i > alcanceMaximo) {
            // Não é possível avançar mais
            return -1;
        }

        if (i + arr[i] > alcanceMaximo)
            alcanceMaximo = i + arr[i];

        if (i == alcanceAtual) {
            pulos++;
            alcanceAtual = alcanceMaximo;
        }
    }

    return (alcanceMaximo >= n - 1) ? pulos : -1;
}

int main() {
    int vetor[] = {2, 3, 1, 1, 4};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    int resultado = saltoDoSapo(vetor, n);

    if (resultado != -1)
        printf("Número mínimo de pulos: %d\n", resultado);
    else
        printf("Não é possível alcançar o fim do caminho.\n");

    return 0;
}
