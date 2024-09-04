#include "pico/stdlib.h"
#include <stdio.h>

#define PIN_BUTTON 13
#define PIN_LED 15

int main(void) {
    gpio_init(PIN_LED);
    gpio_init(PIN_BUTTON);
    gpio_set_dir(PIN_LED, GPIO_OUT);
    gpio_set_dir(PIN_BUTTON, GPIO_IN);

    bool led_state = false;

    while (true) {
        if (gpio_get(PIN_BUTTON) == false)
            continue;

        sleep_ms(20);

        if (gpio_get(PIN_BUTTON) == false) {
            led_state ^= 1;
            gpio_put(PIN_LED, led_state);
        }

        while (gpio_get(PIN_BUTTON) == false)
            ;
    }
}
