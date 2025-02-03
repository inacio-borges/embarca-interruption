#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/adc.h"
#include "pico/bootrom.h"

// arquivo .pio
#include "main.pio.h"

// numeros na matriz de led
double numero_5[25] = {1.0, 1.0, 1.0, 1.0, 1.0,
                       0.0, 0.0, 0.0, 0.0, 1.0,
                       1.0, 1.0, 1.0, 1.0, 1.0,
                       1.0, 0.0, 0.0, 0.0, 0.0,
                       1.0, 1.0, 1.0, 1.0, 1.0};

double numero_4[25] = {1.0, 0.0, 0.0, 1.0, 0.0,
                       0.0, 1.0, 0.0, 0.0, 1.0,
                       1.0, 1.0, 1.0, 1.0, 0.0,
                       0.0, 1.0, 0.0, 0.0, 0.0,
                       0.0, 0.0, 0.0, 1.0, 0.0};

double numero_3[25] = {0.0, 1.0, 1.0, 1.0, 1.0,
                       1.0, 0.0, 0.0, 0.0, 0.0,
                       0.0, 0.0, 1.0, 1.0, 1.0,
                       1.0, 0.0, 0.0, 0.0, 0.0,
                       0.0, 1.0, 1.0, 1.0, 1.0};

double numero_2[25] = {1.0, 1.0, 1.0, 1.0, 1.0,
                       1.0, 0.0, 0.0, 0.0, 0.0,
                       1.0, 1.0, 1.0, 1.0, 1.0,
                       0.0, 0.0, 0.0, 0.0, 1.0,
                       1.0, 1.0, 1.0, 1.0, 1.0};

double numero_1[25] = {0.0, 1.0, 1.0, 0.0, 0.0,
                       0.0, 0.0, 1.0, 0.0, 0.0,
                       0.0, 0.0, 1.0, 0.0, 0.0,
                       0.0, 0.0, 1.0, 0.0, 0.0,
                       1.0, 1.0, 1.0, 1.0, 1.0};

double numero_0[25] = {1.0, 1.0, 1.0, 1.0, 1.0,
                       1.0, 0.0, 0.0, 0.0, 1.0,
                       1.0, 0.0, 0.0, 0.0, 1.0,
                       1.0, 0.0, 0.0, 0.0, 1.0,
                       1.0, 1.0, 1.0, 1.0, 1.0};


#define button_A 5
#define button_B 6

// número de LEDs
#define NUM_PIXELS 25

// pino de saída
#define OUT_PIN 7

// botão de interupção

// rotina da interrupção
static void gpio_irq_handler(uint gpio, uint32_t events)
{
    printf("Interrupção ocorreu no pino %d, no evento %d\n", gpio, events);
    printf("HABILITANDO O MODO GRAVAÇÃO");
    reset_usb_boot(0, 0); // habilita o modo de gravação do microcontrolador
}

// rotina para definição da intensidade de cores do led
uint32_t matrix_rgb(double r, double g, double b)
{
    unsigned char R, G, B;
    R = r * 255;
    G = g * 255;
    B = b * 255;
    return (G << 24) | (R << 16) | (B << 8);
}

// função principal
int main()
{
    printf("Iniciando o programa\n");
    PIO pio = pio0;
    bool ok;
    uint16_t i;
    uint32_t valor_led;
    double r = 0.0, b = 0.0, g = 0.0;
    //
    stdio_init_all(); // Inicializa a comunicação com o terminal
    keypad_init();    // Inicializa o teclado matricial

    // coloca a frequência de clock para 128 MHz, facilitando a divisão pelo clock
    ok = set_sys_clock_khz(128000, false);

    // Inicializa todos os códigos stdio padrão que estão ligados ao binário.
    stdio_init_all();

    printf("iniciando a transmissão PIO");
    if (ok)
        printf("clock set to %ld\n", clock_get_hz(clk_sys));

    // configurações da PIO
    uint offset = pio_add_program(pio, &main_program);
    uint sm = pio_claim_unused_sm(pio, true);
    main_program_init(pio, sm, offset, OUT_PIN);

    gpio_init(button_A);
    gpio_set_dir(button_A, GPIO_IN);
    gpio_pull_up(button_A);

    gpio_init(button_B);
    gpio_set_dir(button_B, GPIO_IN);
    gpio_pull_up(button_B);

    int key = -1;
    while (true)
    {
        if (!gpio_get(button_B))
        {
            key++;
        }
        if (!gpio_get(button_A))
        {
            key--;
        }
    }
    return 0;
}