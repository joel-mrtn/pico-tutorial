#include "hardware/adc.h"
#include "pico/stdlib.h"
#include <stdio.h>

#define INPUT_X 28 // ADC2
#define INPUT_Y 27 // ADC1
#define INPUT_Z 26

int main(void) {
    stdio_init_all();

    adc_init();
    adc_gpio_init(INPUT_X);
    adc_gpio_init(INPUT_Y);

    gpio_init(INPUT_Z);
    gpio_set_dir(INPUT_Z, GPIO_IN);
    gpio_pull_up(INPUT_Z);

    while (true) {
        adc_select_input(2);
        const int x_val = adc_read();

        adc_select_input(1);
        const int y_val = adc_read();

        const int z_val = gpio_get(INPUT_Z);

        printf("X: %d, Y: %d, Z: %d\n", x_val, y_val, z_val);
        sleep_ms(500);
    }
}