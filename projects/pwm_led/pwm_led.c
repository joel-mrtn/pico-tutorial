#include "hardware/pwm.h"
#include "pico/stdlib.h"

#define PIN_LED 15
#define DELAY 5

int main() {
    gpio_set_function(PIN_LED, GPIO_FUNC_PWM);

    const uint slice_num = pwm_gpio_to_slice_num(PIN_LED);
    const uint chan = pwm_gpio_to_channel(PIN_LED);

    pwm_set_wrap(slice_num, 255);
    pwm_set_enabled(slice_num, true);

    while (true) {
        for (int i = 0; i < 255; i++) {
            pwm_set_chan_level(slice_num, chan, i);
            sleep_ms(DELAY);
        }

        for (int i = 255; i > -1; i--) {
            pwm_set_chan_level(slice_num, chan, i);
            sleep_ms(DELAY);
        }
    }
}