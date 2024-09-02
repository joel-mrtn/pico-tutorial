#include "pico/stdlib.h"
#include <stdio.h>

#define DELAY 100

int main(void) {
    const uint led_pins[] = {16, 17, 18, 19, 20, 21, 22, 26, 27, 28};
    constexpr uint led_count = sizeof led_pins / sizeof led_pins[0];

    for (int i = 0; i < led_count; i++) {
        gpio_init(led_pins[i]);
        gpio_set_dir(led_pins[i], GPIO_OUT);
    }

    int current_led = 0;
    int direction = 1;

    while (true) {
        gpio_put(led_pins[current_led], true);
        sleep_ms(DELAY);
        gpio_put(led_pins[current_led], false);

        current_led += direction;

        if (current_led == led_count || current_led == -1) {
            direction ^= -2; // Toggle between 1 and -1
            current_led += 2 * direction;
        }
    }
}