#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 256

typedef struct No {
    unsigned char caractere;
    int frequencia;
    struct No *esq, *dir;
} No;

typedef struct {
    int tamanho;
    No* dados[TAM];
} Heap;

typedef struct {
    unsigned char bits[256];
    int tamanho;
} Codigo;

void swap(No** a, No** b) {
    No* tmp = *a;
    *a = *b;
    *b = tmp;
}

void inserirHeap(Heap* h, No* no) {
    int i = h->tamanho++;
    h->dados[i] = no;

    while (i && h->dados[i]->frequencia < h->dados[(i - 1) / 2]->frequencia) {
        swap(&h->dados[i], &h->dados[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

No* removerMinimo(Heap* h) {
    No* min = h->dados[0];
    h->dados[0] = h->dados[--h->tamanho];

    int i = 0;
    while (1) {
        int menor = i, esq = 2 * i + 1, dir = 2 * i + 2;

        if (esq < h->tamanho && h->dados[esq]->frequencia < h->dados[menor]->frequencia)
            menor = esq;
        if (dir < h->tamanho && h->dados[dir]->frequencia < h->dados[menor]->frequencia)
            menor = dir;

        if (menor == i)
            break;

        swap(&h->dados[i], &h->dados[menor]);
        i = menor;
    }

    return min;
}

No* criarNo(unsigned char caractere, int freq, No* esq, No* dir) {
    No* no = (No*)malloc(sizeof(No));
    no->caractere = caractere;
    no->frequencia = freq;
    no->esq = esq;
    no->dir = dir;
    return no;
}

void gerarCodigos(No* raiz, Codigo codigos[], unsigned char codigo[], int topo) {
    if (raiz->esq) {
        codigo[topo] = '0';
        gerarCodigos(raiz->esq, codigos, codigo, topo + 1);
    }

    if (raiz->dir) {
        codigo[topo] = '1';
        gerarCodigos(raiz->dir, codigos, codigo, topo + 1);
    }

    if (!raiz->esq && !raiz->dir) {
        codigo[topo] = '\0';
        strcpy((char*)codigos[raiz->caractere].bits, (char*)codigo);
        codigos[raiz->caractere].tamanho = topo;
    }
}

void escreverBits(FILE* out, const char* bits, int* buffer, int* pos) {
    for (int i = 0; bits[i]; i++) {
        *buffer = (*buffer << 1) | (bits[i] - '0');
        (*pos)++;
        if (*pos == 8) {
            fputc(*buffer, out);
            *buffer = 0;
            *pos = 0;
        }
    }
}

void compactar(const char* entrada, const char* saida) {
    FILE* in = fopen(entrada, "rb");
    FILE* out = fopen(saida, "wb");

    int freq[TAM] = {0};
    int c;

    while ((c = fgetc(in)) != EOF)
        freq[(unsigned char)c]++;

    rewind(in);

    Heap heap = {0};
    for (int i = 0; i < TAM; i++) {
        if (freq[i]) {
            inserirHeap(&heap, criarNo(i, freq[i], NULL, NULL));
        }
    }

    while (heap.tamanho > 1) {
        No* esq = removerMinimo(&heap);
        No* dir = removerMinimo(&heap);
        inserirHeap(&heap, criarNo(0, esq->frequencia + dir->frequencia, esq, dir));
    }

    No* raiz = removerMinimo(&heap);

    Codigo codigos[TAM] = {0};
    unsigned char codigo[256];
    gerarCodigos(raiz, codigos, codigo, 0);

    // Salvar tabela de frequências
    for (int i = 0; i < TAM; i++)
        fwrite(&freq[i], sizeof(int), 1, out);

    int buffer = 0, pos = 0;
    while ((c = fgetc(in)) != EOF)
        escreverBits(out, (char*)codigos[(unsigned char)c].bits, &buffer, &pos);

    if (pos > 0) {
        buffer <<= (8 - pos);
        fputc(buffer, out);
    }

    fclose(in);
    fclose(out);
    printf("Compactação concluída: %s\n", saida);
}

No* reconstruirArvore(int freq[]) {
    Heap heap = {0};

    for (int i = 0; i < TAM; i++) {
        if (freq[i]) {
            inserirHeap(&heap, criarNo(i, freq[i], NULL, NULL));
        }
    }

    while (heap.tamanho > 1) {
        No* esq = removerMinimo(&heap);
        No* dir = removerMinimo(&heap);
        inserirHeap(&heap, criarNo(0, esq->frequencia + dir->frequencia, esq, dir));
    }

    return removerMinimo(&heap);
}

void descompactar(const char* entrada, const char* saida) {
    FILE* in = fopen(entrada, "rb");
    FILE* out = fopen(saida, "wb");

    int freq[TAM];
    for (int i = 0; i < TAM; i++)
        fread(&freq[i], sizeof(int), 1, in);

    No* raiz = reconstruirArvore(freq);
    No* atual = raiz;

    int total = 0;
    for (int i = 0; i < TAM; i++) total += freq[i];

    int c, count = 0;
    while (count < total && (c = fgetc(in)) != EOF) {
        for (int i = 7; i >= 0; i--) {
            if (c & (1 << i))
                atual = atual->dir;
            else
                atual = atual->esq;

            if (!atual->esq && !atual->dir) {
                fputc(atual->caractere, out);
                atual = raiz;
                count++;
                if (count >= total) break;
            }
        }
    }

    fclose(in);
    fclose(out);
    printf("Descompactação concluída: %s\n", saida);
}

int main() {
    int escolha;
    printf("1 - Compactar\n2 - Descompactar\nEscolha: ");
    scanf("%d", &escolha);
    getchar();

    if (escolha == 1) {
        compactar("entrada.txt", "compactado.bin");
    } else if (escolha == 2) {
        descompactar("compactado.bin", "saida.txt");
    } else {
        printf("Opção inválida.\n");
    }

    return 0;
}
