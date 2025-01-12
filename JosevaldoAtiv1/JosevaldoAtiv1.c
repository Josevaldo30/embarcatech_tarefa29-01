#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define RED 13
#define BLUE 12
#define GREEN 11

static volatile int controle= 0;

bool callback( struct repeating_timer *time){

    if (controle==0)
    {
        gpio_put(RED,1);
        gpio_put(BLUE,0);
        gpio_put(GREEN,0);
        controle=1;
        return true;
    }
    if (controle==1)
    {
        gpio_put(RED,0);
        gpio_put(BLUE,1);
        gpio_put(GREEN,0);
        controle=2;
        return true;
    }
    if (controle==2)
    {
        gpio_put(RED,0);
        gpio_put(BLUE,0);
        gpio_put(GREEN,1);
        controle=0;
        return true;
    }
    
}

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
    stdio_init_all();
    inicia();

    struct repeating_timer time;

    add_repeating_timer_ms(3000, callback, NULL, &time);

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
