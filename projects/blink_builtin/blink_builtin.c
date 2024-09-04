#include "pico/cyw43_arch.h"
#include "pico/stdlib.h"

#define LED_DELAY_MS 1000

int main() {
    stdio_init_all();

    const int rc = cyw43_arch_init();
    hard_assert(rc == PICO_OK);

    while (true) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        puts("LED ON");
        sleep_ms(LED_DELAY_MS);

        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        puts("LED OFF");
        sleep_ms(LED_DELAY_MS);
    }
}