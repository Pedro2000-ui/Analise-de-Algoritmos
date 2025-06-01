# 📘 Relatório - Atividade de Programação Dinâmica
Aluno: Pedro Henrique Oliveira Brito 
Matrícula: 1142256480

# Link e Nome do Problema
Nome: Planets Cycles
Link: https://cses.fi/problemset/task/1751

# Análise do Problema
O problema nos apresenta um jogo com **n** planetas numerados de **1** a **n**. Cada planeta possui um teletransportador que leva diretamente a outro planeta (ou a ele mesmo). A simulação inicia em cada planeta e segue usando o teletransportador até que se volte a um planeta já visitado (formando um ciclo).

Objetivo: Para cada planeta de início, determinar o número de teletransportes realizados até encontrar um planeta já visitado.

# O que se busca resolver?
Queremos, para cada planeta, descobrir quantas etapas de teletransporte são realizadas até cair em um ciclo. O número de passos pode variar dependendo do comprimento do ciclo e do caminho até ele.

# Subproblemas
Para cada planeta **i**, calcular a quantidade de saltos **f(i)** até repetir um planeta.
Os subproblemas estão ligados à reutilização de resultados previamente calculados (por exemplo, se já sabemos **f(j)** e **t[i]** = **j**, podemos usar **f(j)** para definir **f(i)**).

### Explicando o que significa:
```makefile
“Para cada planeta i, calcular a quantidade de saltos f(i) até repetir um planeta.”
```
Isso significa que precisamos descobrir quantos saltos de teletransporte são necessários a partir do planeta **i**, até que o jogador visite um planeta pela **segunda vez**. O jogador para de saltar assim que visita um planeta que já havia visitado **antes**.

```makefile
“Se já sabemos f(j) e t[i] = j, então podemos usar f(j) para definir f(i).”
```

Isso está dizendo o seguinte:

- Imagine que o planeta i teletransporta para o planeta j.
- E você já sabe que, começando do planeta j, são necessários f(j) saltos até encontrar um ciclo.
- Então, começando do planeta i, o número de saltos será 1 + f(j).

Reutilizamos o resultado já calculado para j para evitar repetir o trabalho de novo.

Essa equação é válida quando não há ciclos não tratados no caminho, ou seja, quando **j** não é parte de um ciclo ainda em processamento.

### Exemplo:
```makefile
Planetas: 1  2  3  4  5
Destino:  2  4  3  1  4
```

Queremos descobrir f(i) para cada i.

Começando do planeta 1, o caminho é:
```makefile
1 → 2 → 4 → 1 → (loop)
```

Começando do planeta 2, o caminho é:
```makefile
2 → 4 → 1 → 2 → (loop)
```

Começando do planeta 3, o caminho é:
```makefile
3 → 3 → (loop)
```

### Vamos entender a trajetória a partir de cada planeta:

#### Planeta 3:
```makefile
t[3] = 3 → Ou seja, o planeta 3 teletransporta para ele mesmo.
Já visitou o planeta 3? Sim, imediatamente.
Resultado: f(3) = 1 (apenas 1 salto e você já está de volta ao mesmo planeta).
```

#### Planeta 2:
```makefile
Começa em 2 → t[2] = 4 → vai para planeta 4.
t[4] = 1 → vai para planeta 1.
t[1] = 2 → volta para o 2 (já visitado).
Resultado: f(2) = 3 (3 saltos até estar de volta ao mesmo planeta)
```

Agora imagine que você já sabia que:
```makefile
f(4) = 2 (quantidade saltos partindo de 4 para encontrar o 2)
(caminho: 4 → 1 → 2)
```

Então ao fazer:
```makefile
f(2) = 1 + f(4)
```

Porque:

```makefile
Se de 4 até encontrar 2 são 2 saltos,
Então de 2 (que vai pra 4) até repetir são 1 (até 4) + 2 (de 4 em diante) = 3
```

➡️ f(2) = 1 + f(4)
➡️ Esse é o reaproveitamento do subproblema f(4)

# Justificativa de Programação Dinâmica
Este é um problema típico de programação dinâmica porque:
- Pode ser resolvido de forma recursiva, com memoization para evitar recomputações de subproblemas já resolvidos.
- Possui subestrutura ótima: o resultado de f(i) depende apenas de f(t[i]).
- É possível aplicar bottom-up (tabulation) percorrendo os planetas em ordem e usando uma abordagem iterativa para preencher os valores.

# Comparativo teórico das abordagens

| Versão                   | Tempo esperado                                                                  | Vantagens                             | Desvantagens                                                   |
| ------------------------ | ------------------------------------------------------------------------------- | ------------------------------------- | -------------------------------------------------------------- |
| Recursiva pura           | Muito lento em casos grandes, devido à recomputação e reexploração de estados   | Código simples, fácil de entender     | Tempo exponencial para inputs grandes                          |
| Top-Down com Memoization | Rápido, evita recomputações, usa memória para guardar resultados intermediários | Boa performance para grandes entradas | Uso de memória extra para memo e pilha                         |
| Bottom-Up (Tabulação)    | Também rápido, itera de baixo para cima, evita recursão                         | Evita overhead de chamada recursiva   | Código um pouco mais complexo, maior uso de memória temporária |

# Saída exemplo do programa para "Teste Pequeno" 
```c

n = 5; //Número de Planetas (de 1 a 5)
int small[] = {0, 2, 4, 3, 1, 4}; //Array de visitas, seguindo o indice do vetor (o indice 0 é ignorado)

===== Teste Pequeno =====
Recursiva pura: 3 3 1 3 4 
Recursiva pura: 0.000021 segundos
Top-down: 3 3 1 3 4 
Top-down: 0.000010 segundos
Bottom-up: 3 3 1 3 4 
Bottom-up: 0.000008 segundos
```

# Considerações finais
- Recursiva pura é inviável para casos maiores, pois recalcula várias vezes o mesmo estado e tem problema de sobrecarga de pilha, além de detecção simplificada de ciclo.
- Top-Down com memoization e Bottom-Up apresentam tempo de execução muito melhor e escalabilidade para milhares de planetas.
- A implementação bottom-up evita chamadas recursivas, importante em sistemas que limitam profundidade de pilha.

Em casos práticos, top-down ou bottom-up são melhores para performance e robustez.

# Link para vídeo de apresentação
[Texto do link](URL_do_vídeo)
