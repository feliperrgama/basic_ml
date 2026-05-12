# Passo a Passo: Modelo de ML em C++

## Visão Geral

Você vai implementar uma regressão linear simples sem intercepto, treinada via **gradiente descendente**.

---

## 1. Entenda o modelo

O modelo é simplesmente:

$$\hat{y} = x \cdot w$$

Onde:
- $x$ → entrada (dado conhecido)
- $w$ → peso (parâmetro que o modelo vai aprender)
- $\hat{y}$ → saída prevista pelo modelo

---

## 2. Defina a função de perda (Loss Function)

Você precisa medir o quão errado o modelo está. Use o **Erro Quadrático Médio (MSE)**:

$$L(w) = \frac{1}{N} \sum_{i=1}^{N} (\hat{y}_i - y_i)^2 = \frac{1}{N} \sum_{i=1}^{N} (x_i \cdot w - y_i)^2$$

Onde $N$ é o número de amostras e $y_i$ é o valor real esperado.

---

## 3. Calcule o gradiente

O gradiente indica a direção em que $L$ cresce em relação a $w$. Você quer o oposto disso. Derive $L$ em relação a $w$:

$$\frac{\partial L}{\partial w} = \frac{2}{N} \sum_{i=1}^{N} x_i \cdot (x_i \cdot w - y_i)$$

---

## 4. Atualize o peso com Gradiente Descendente

A cada iteração de treino, ajuste $w$ na direção oposta ao gradiente:

$$w \leftarrow w - \alpha \cdot \frac{\partial L}{\partial w}$$

Onde $\alpha$ (alpha) é a **taxa de aprendizado** — um número pequeno como $0.01$ que controla o tamanho do passo.

---

## 5. Monte o loop de treinamento

O processo completo de treino é:

```
1. Inicialize w com um valor aleatório pequeno (ou 0)
2. Repita por N_epochs vezes:
   a. Para cada amostra (x, y) do dataset:
      - Calcule ŷ = x * w
      - Calcule o erro = ŷ - y
   b. Calcule o gradiente médio sobre todas as amostras
   c. Atualize w ← w - α * gradiente
   d. (Opcional) Calcule e registre o valor da Loss
3. Ao final, w contém o parâmetro aprendido
```

---

## 6. Estrutura do código C++

Organize seu programa em blocos separados:

| Bloco | Responsabilidade |
|---|---|
| **Dataset** | Estrutura ou vetores para guardar os pares $(x_i, y_i)$ |
| **Forward pass** | Calcula $\hat{y} = x \cdot w$ |
| **Loss** | Calcula o MSE dado $w$ e o dataset |
| **Gradiente** | Calcula $\frac{\partial L}{\partial w}$ |
| **Treino** | Loop que chama gradiente e atualiza $w$ |
| **Main** | Inicializa tudo, chama treino, imprime resultado |

---

## 7. Validação e verificação

Após o treino, você pode verificar se funcionou:

- Escolha um $x$ de teste e calcule $\hat{y} = x \cdot w$
- Compare com o valor real esperado
- A Loss deve ter **diminuído monotonicamente** ao longo das épocas — se estiver subindo, $\alpha$ está muito alto

---

## Hiperparâmetros para começar

| Parâmetro | Valor sugerido |
|---|---|
| $\alpha$ (learning rate) | $0.01$ |
| Épocas | $1000$ |
| $w$ inicial | $0.0$ ou aleatório pequeno |
