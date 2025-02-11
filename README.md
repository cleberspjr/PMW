## Autor: Cleber Santos Pinto Júnior - https://github.com/cleberspjr

## PMW
Este projeto implementa o controle de um servomotor utilizando o microcontrolador Raspberry Pi Pico e o módulo PWM (Pulse Width Modulation).
O sistema também inclui um LED RGB que tem seu brilho ajustado com base na posição do servo. 
A implementação foi realizada em linguagem C com o Pico SDK e pode ser simulada no ambiente Wokwi.

## Componentes Utilizados

• Microcontrolador Raspberry Pi Pico W

• Servomotor padrão (simulado no Wokwi)

• LED RGB (GPIO 12)

• Simulador Wokwi

## Configuração do PWM

• Frequência do PWM: 50Hz (Período de 20ms) na GPIO 22 para controle do servomotor.

• Movimentação Suave: Incrementos de 5µs com atraso de 10ms entre cada ajuste.

• Controle do LED RGB: O brilho do LED é ajustado proporcionalmente ao nível do PWM do servo.


## Funcionalidade do Código

1. Configura a GPIO 22 para gerar um sinal PWM de 50Hz.

2. Ajusta o servomotor para as posições de 180°, 90° e 0°, aguardando 5 segundos em cada uma.

3. Inicia um loop infinito que move suavemente o servo entre 0° e 180°.

4. LED RGB ajusta sua intensidade conforme a posição do servo.

## MODO DE EXECUÇÃO

1. Clonar o Repositório: git clone https://github.com/cleberspjr/PMW.git

2. Configure o ambiente de desenvolvimento PICO SDK

3. Abra o projeto no VS Code e importe o projeto através da extensão Raspberry Pi 

4. Execute a simulação na placa Bitdoglab


## LINK PARA O VÍDEO DA TAREFA: 

https://drive.google.com/file/d/1F6G54c6PtD72qr3I0AVE-wA8UN7ya5ex/view?usp=sharing


