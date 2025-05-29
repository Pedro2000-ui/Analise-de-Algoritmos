# 🏁 Descrição do Problema — Seleção de Paradas
Um veículo quer percorrer uma distância D com um tanque que permite viajar no máximo M unidades de distância. Existem N postos de abastecimento ao longo da estrada, e queremos escolher o menor número de paradas possíveis para reabastecimento e completar o trajeto.

## 🧠 Estratégia Gulosa
Sempre vá o mais longe possível sem ficar sem combustível. Pare somente no último posto que ainda está dentro do alcance.

## 📥 Exemplo de Entrada
```c
Capacidade máxima do tanque (km): 400
Número de postos: 6
Postos: 0, 200, 375, 550, 750, 950
```

## 📤 Saída Esperada
```c
Parada em: 375 km
Parada em: 750 km
Total de paradas necessárias: 2
```