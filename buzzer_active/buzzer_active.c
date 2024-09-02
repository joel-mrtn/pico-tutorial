#include "pico/stdlib.h"

#define PIN_BUZZER 15
#define PIN_BUTTON 16

int main(void) {
    gpio_init(PIN_BUZZER);
    gpio_init(PIN_BUTTON);

    gpio_set_dir(PIN_BUZZER, GPIO_OUT);
    gpio_set_dir(PIN_BUTTON, GPIO_IN);

    gpio_put(PIN_BUZZER, false);

    while (true) {
        if (gpio_get(PIN_BUTTON) == false) {
            gpio_put(PIN_BUZZER, true);
        } else {
            gpio_put(PIN_BUZZER, false);
        }
    }
}
