#include "pico/stdlib.h"
#include <stdio.h>

#define PIN_LED 15
#define LED_DELAY_MS 500

int main(void) {
    gpio_init(PIN_LED);
    gpio_set_dir(PIN_LED, GPIO_OUT);

    while (true) {
        gpio_put(PIN_LED, true);
        sleep_ms(LED_DELAY_MS);

        gpio_put(PIN_LED, false);
        sleep_ms(LED_DELAY_MS);
    }
}