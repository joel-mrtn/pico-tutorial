#include "pico/cyw43_arch.h"
#include "pico/stdlib.h"

#define LED_DELAY_MS 1000

int main() {
    const int rc = cyw43_arch_init();
    hard_assert(rc == PICO_OK);

    while (true) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, true);
        sleep_ms(LED_DELAY_MS);

        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, false);
        sleep_ms(LED_DELAY_MS);
    }
}