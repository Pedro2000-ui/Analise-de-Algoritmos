# 🐸 Descrição do Problema — Salto do Sapo

Dado um vetor onde cada posição contém a distância máxima que o sapo pode pular a partir dali, determine o número mínimo de pulos para o sapo sair da primeira posição e alcançar ou ultrapassar o final do vetor.

# 📌 Exemplo:
```c
Entrada: [2, 3, 1, 1, 4]
Explicação:
- Pulo 1: posição 0 → pulo de 2 → chega na posição 1 ou 2.
- Melhor escolha: pular até posição 1 (pois ela permite salto de até 3).
- Pulo 2: posição 1 → pulo de 3 → chega ao final.

Saída esperada: 2 pulos.
```

# Estratégia Gulosa
A ideia é:
- Em cada posição, verificar até onde é possível ir.
- Controlar o "alcance máximo" possível até o momento.
- Sempre que alcançamos o limite do salto atual, fazemos um novo pulo para continuar progredindo.

# Objetivo
Determinar o número mínimo de pulos necessários para o sapo alcançar ou ultrapassar o final do vetor.