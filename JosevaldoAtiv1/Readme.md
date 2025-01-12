Projeto: Controle de LED com Raspberry Pi Pico

Descrição

Este projeto implementa o controle de um LED RGB utilizando um Raspberry Pi Pico. O programa alterna as cores do LED a cada 3 segundos, seguindo a ordem: vermelho, azul e verde.

Hardware Necessário

Raspberry Pi Pico

LED RGB de ânodo comum ou catodo comum

Resistores apropriados (se necessário)

Jumpers e protoboard

Conexão dos Pinos

Os LEDs devem ser conectados aos seguintes pinos do Raspberry Pi Pico:

Pino 13 - LED Vermelho

Pino 12 - LED Azul

Pino 11 - LED Verde

Funcionamento

O programa utiliza um timer para alternar as cores do LED a cada 3 segundos. O ciclo segue esta ordem:

Acende o LED vermelho

Acende o LED azul

Acende o LED verde

Repete o ciclo

Enquanto isso, o programa também imprime "Hello, world!" a cada segundo no console.

Compilação e Execução

Para compilar e rodar este código no Raspberry Pi Pico:

Instale o SDK do Raspberry Pi Pico e configure o ambiente.

Compile o programa usando o CMake e o GCC para ARM.

Envie o arquivo binário gerado para o Pico via modo USB de armazenamento.