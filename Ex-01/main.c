/*
    Escreva uma função em linguagem C que receba um vetor de inteiros representando um conjunto de elementos e
    imprima todos os subconjuntos desse conjunto. Utilize, necessariamente, a técnica de backtracking.
    Ex.:

    Entrada:  {1,5,9}

    Saída: {{}, {1}, {5}, {9}, {1, 5}, {1, 9}, {1, 5, 9}}
*/ 

#include <stdio.h>

void mostrarSubconjunto(int grupo[], int tamanho) {
    printf("{");
    for (int i = 0; i < tamanho; i++) {
        if (i != 0) printf(", ");
        printf("%d", grupo[i]);
    }
    printf("}");
}

void explorar(int entrada[], int tamEntrada, int pos, int aux[], int tamAux) {
    if (pos == tamEntrada) {
        mostrarSubconjunto(aux, tamAux);
        printf(" ");
        return;
    }

    // Tenta sem o elemento atual
    explorar(entrada, tamEntrada, pos + 1, aux, tamAux);

    // Tenta com o elemento atual
    aux[tamAux] = entrada[pos];
    explorar(entrada, tamEntrada, pos + 1, aux, tamAux + 1);
}

void subconjuntos(int dados[], int tamanho) {
    int temp[tamanho]; // Armazena subconjunto atual
    explorar(dados, tamanho, 0, temp, 0);
}

int main() {
    int numeros[] = {1, 5, 9};
    int n = sizeof(numeros) / sizeof(numeros[0]);

    printf("Subconjuntos: ");
    subconjuntos(numeros, n);
    printf("\n");

    return 0;
}
