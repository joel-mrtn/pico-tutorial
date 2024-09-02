#include "pico/stdlib.h"
#include <stdio.h>

#define PIN_LED 15
#define LED_DELAY_MS 500

void log_gpio(const uint gpio, const bool value) {
    printf("GPIO %d: %s\n", gpio, value ? "ON" : "OFF");
}

int main(void) {
    stdio_init_all();

    gpio_init(PIN_LED);
    gpio_set_dir(PIN_LED, GPIO_OUT);

    while (true) {
        gpio_put(PIN_LED, true);
        log_gpio(PIN_LED, true);
        sleep_ms(LED_DELAY_MS);

        gpio_put(PIN_LED, false);
        log_gpio(PIN_LED, false);
        sleep_ms(LED_DELAY_MS);
    }
}
