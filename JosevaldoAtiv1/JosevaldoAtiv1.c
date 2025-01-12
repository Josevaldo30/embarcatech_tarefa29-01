#include <stdio.h>// Biblioteca padrão de entrada e saída para operações como printf().  
#include "pico/stdlib.h"// Biblioteca da Raspberry Pi Pico contendo funções essenciais para manipulação de GPIO, temporizadores e comunicação. 
#include "hardware/timer.h"// Biblioteca específica para controle de temporizadores (timers) no Raspberry Pi Pico.

// Definição dos pinos do LED RGB
#define RED 13
#define BLUE 12
#define GREEN 11

// Variável de controle para alternância das cores
static volatile int controle= 0;

// Função de callback chamada pelo temporizador a cada 3 segundos
bool callback( struct repeating_timer *time){

    // Alterna entre as cores do LED RGB
    if (controle==0)
    {
        gpio_put(RED,1);// Acende o LED vermelho
        gpio_put(BLUE,0);
        gpio_put(GREEN,0);
        controle=1;
        return true;
    }
    if (controle==1)
    {
        gpio_put(RED,0);
        gpio_put(BLUE,1);// Acende o LED azul
        gpio_put(GREEN,0);
        controle=2;
        return true;
    }
    if (controle==2)
    {
        gpio_put(RED,0);
        gpio_put(BLUE,0);
        gpio_put(GREEN,1);// Acende o LED verde
        controle=0;
        return true;
    }
    
}

// Função para inicializar os pinos do LED como saída
void inicia(){
    gpio_init(RED);
    gpio_init(GREEN);
    gpio_init(BLUE);

    gpio_set_dir(RED,GPIO_OUT);
    gpio_set_dir(GREEN,GPIO_OUT);
    gpio_set_dir(BLUE,GPIO_OUT);


}

int main()
{
    stdio_init_all();// Inicializa a saída padrão (para debug via USB)
    inicia(); // Configura os pinos do LED
    

    struct repeating_timer time;
    
    // Configura o temporizador para chamar a função de callback a cada 3000 ms (3 segundos)
    add_repeating_timer_ms(3000, callback, NULL, &time);

    // Loop infinito para manter o programa em execução
    while (true) {
        printf("Hello, world!\n");// Imprime uma mensagem a cada 1 segundo
        sleep_ms(1000);
    }
}
