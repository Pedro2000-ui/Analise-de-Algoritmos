# Huffman Compressor e Descompressor em C

Este projeto implementa um **compressor e descompressor de arquivos baseado no algoritmo de Huffman**, utilizando uma estratégia eficiente de codificação binária baseada na frequência dos caracteres.

## 📦 Arquivos

- `entrada.txt`: Arquivo original de texto a ser compactado.
- `compactado.bin`: Arquivo binário gerado após a compactação.
- `saida.txt`: Arquivo resultante após a descompactação.

## ⚙️ Como Usar

### 1. Compile o programa (Dentro da pasta Ex-08)

```bash
gcc huffman.c -o huffman
```

### 2. Compactar
- Crie um arquivo chamado entrada.txt com o conteúdo desejado.
- Execute:
```bash
./huffman
```
Escolha a opção 1 - Compactar.

### 3. Descompactar
Após a compactação, execute novamente:
```bash
./huffman
``` 
Escolha a opção 2 - Descompactar.

## 🧠 Sobre o Algoritmo de Huffman
- Codificação de Huffman é uma técnica de compressão sem perdas baseada em árvores binárias.
- Caracteres mais frequentes recebem códigos binários menores.
- A árvore é construída com base nas frequências dos caracteres e permite decodificação sem ambiguidade.

