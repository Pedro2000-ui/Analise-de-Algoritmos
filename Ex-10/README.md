# 📈 Maior Subsequência Crescente (LIS) em C

Este projeto apresenta três formas diferentes de resolver o clássico problema da **Maior Subsequência Crescente (LIS - Longest Increasing Subsequence)** usando a linguagem C.

O problema consiste em encontrar a maior sequência **estritamente crescente** dentro de um vetor de inteiros.

---

## 🧠 Abordagens implementadas

1. ✅ Recursiva simples  
2. ✅ Programação dinâmica - Top-Down (com memorização)  
3. ✅ Programação dinâmica - Bottom-Up (iterativa)

---

## 📌 Exemplo do problema

Dado o vetor:
```c
[10, 22, 9, 33, 21, 50, 41, 60]
```

A maior subsequência crescente é:
```c
[10, 22, 33, 50, 60] (tamanho 5)
```

### ❓ Por que não [9, 10, 21, 22, 33, 41, 50, 60]?
Apesar de essa sequência conter todos os elementos em ordem crescente, ela não é uma subsequência válida, pois não respeita a ordem original dos elementos no vetor.

- Uma subsequência é formada eliminando elementos, mas mantendo a ordem original dos restantes. Ou seja, você não pode reordenar os elementos do vetor original.
- Portanto, entre todas as subsequências crescentes possíveis, a de maior tamanho respeitando a ordem é:

```c
[10, 22, 33, 50, 60] (tamanho 5)
```

# ⏱️ Comparação de desempenho

| Versão    | Tempo | Espaço |
| --------- | ----- | ------ |
| Recursiva | O(2ⁿ) | O(n)   |
| Top-Down  | O(n²) | O(n²)  |
| Bottom-Up | O(n²) | O(n)   |

# Observações

- A versão recursiva é intuitiva, mas ineficiente para vetores grandes.
- A versão Top-Down melhora a eficiência com memorização.
- A versão Bottom-Up é geralmente a mais usada, por ser simples e eficiente.