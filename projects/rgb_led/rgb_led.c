#include "hardware/pwm.h"
#include "pico/stdlib.h"
#include <stdlib.h>
#include <time.h>

#define DELAY 500
#define WRAP 255

typedef struct Led {
    uint pin;
    uint slice_num;
    uint chan;
} led;

int main() {
    const led leds[] = {
        {13, pwm_gpio_to_slice_num(13), pwm_gpio_to_channel(13)},
        {12, pwm_gpio_to_slice_num(12), pwm_gpio_to_channel(12)},
        {11, pwm_gpio_to_slice_num(11), pwm_gpio_to_channel(11)}};
    constexpr uint led_count = sizeof leds / sizeof leds[0];

    for (int i = 0; i < led_count; i++) {
        gpio_set_function(leds[i].pin, GPIO_FUNC_PWM);

        pwm_set_wrap(leds[i].slice_num, WRAP);
        pwm_set_enabled(leds[i].slice_num, true);
    }

    const led *red = &leds[0];
    const led *green = &leds[1];
    const led *blue = &leds[2];

    srand(time(nullptr));

    while (true) {
        pwm_set_chan_level(red->slice_num, red->chan,
                           WRAP - rand() % WRAP / 10);
        pwm_set_chan_level(green->slice_num, green->chan,
                           WRAP - rand() % WRAP / 10);
        pwm_set_chan_level(blue->slice_num, blue->chan,
                           WRAP - rand() % WRAP / 10);

        sleep_ms(DELAY);
    }
}