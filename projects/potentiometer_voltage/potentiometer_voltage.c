#include "hardware/adc.h"
#include "pico/stdlib.h"
#include <stdio.h>

#define PIN_ANALOG_IN 26

int main(void) {
    stdio_init_all();

    adc_init();
    adc_gpio_init(PIN_ANALOG_IN);
    adc_select_input(0);

    constexpr float conversion_factor = 3.3f / (1 << 12);

    while (true) {
        const uint16_t result = adc_read();

        printf("Raw value: 0x%03x, voltage: %f V\n", result,
               (float)result * conversion_factor);

        sleep_ms(500);
    }
}