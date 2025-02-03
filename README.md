# Display Numérico com Matriz de LEDs 5x5 e Controle via Botões

Aluno: Inacio Oliveira Borges

link para o video da execucao do projeto: [Projeto em execucao](https://www.youtube.com/watch?v=9hfwMPLom70)
## Descrição do Projeto

Este projeto implementa um contador numérico interativo utilizando uma matriz de LEDs 5x5 WS2812 e um LED RGB comum, controlados por uma placa BitDogLab. A interação é feita através de dois botões que permitem incrementar ou decrementar o número exibido na matriz. Além disso, o LED vermelho do LED RGB pisca continuamente, proporcionando um efeito visual adicional.

## Funcionalidades

1. Piscar do LED Vermelho:
   - O LED vermelho pisca continuamente a uma frequência de 5 Hz (5 vezes por segundo).

2. Controle Interativo:
   - Botão A: Incrementa o número na matriz a cada pressionamento.
   - Botão B: Decrementa o número na matriz a cada pressionamento.

3. Exibição na Matriz de LEDs 5x5:
   - Apresenta números de 0 a 9 em formato fixo ou criativo, com os dígitos claramente identificáveis.

4. Implementação de Interrupções e Debounce:
   - Utiliza interrupções para resposta eficiente aos botões.
   - Implementa debounce por software para evitar leituras falsas devido ao bouncing mecânico.

## Materiais Necessários

- Placa BitDogLab
- Matriz de LEDs 5x5 WS2812 (endereçáveis)
  - Conectada à GPIO 7
- LED RGB Comum
  - Pinos conectados às GPIOs:
    - Vermelho: GPIO 11
    - Verde: GPIO 12
    - Azul: GPIO 13
- Botão A
  - Conectado à GPIO 5
- Botão B
  - Conectado à GPIO 6
- Cabos Jumpers
- Fonte de Alimentação (se necessário)
- Computador com IDE Arduino instalada

## Esquema de Conexão

Componente           - GPIO da BitDogLab
- Matriz de LEDs     - 7
- LED RGB - Vermelho - 11
- LED RGB - Verde    - 12
- LED RGB - Azul     - 13
- Botão A            - 5
- Botão B            - 6

Observações:

- Certifique-se de conectar os pinos de alimentação (VCC) e terra (GND) adequadamente.
- A matriz de LEDs WS2812 requer uma alimentação estável de 5V e deve compartilhar o GND com a placa.
- Os botões devem ser conectados com resistores pull-up internos ou externos, se necessário.