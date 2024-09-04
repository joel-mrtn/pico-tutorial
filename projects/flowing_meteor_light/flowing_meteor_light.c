#include "pico/stdlib.h"
#include <hardware/pwm.h>
#include <sys/types.h>

#define DELAY 100

typedef struct Led {
    uint pin;
    uint slice_num;
    uint chan;
} led;

int main(void) {
    const led leds[] = {
        {16, pwm_gpio_to_slice_num(16), pwm_gpio_to_channel(16)},
        {17, pwm_gpio_to_slice_num(17), pwm_gpio_to_channel(17)},
        {18, pwm_gpio_to_slice_num(18), pwm_gpio_to_channel(18)},
        {19, pwm_gpio_to_slice_num(19), pwm_gpio_to_channel(19)},
        {20, pwm_gpio_to_slice_num(20), pwm_gpio_to_channel(20)},
        {21, pwm_gpio_to_slice_num(21), pwm_gpio_to_channel(21)},
        {22, pwm_gpio_to_slice_num(22), pwm_gpio_to_channel(22)},
        {26, pwm_gpio_to_slice_num(26), pwm_gpio_to_channel(26)},
        {27, pwm_gpio_to_slice_num(27), pwm_gpio_to_channel(27)},
        {28, pwm_gpio_to_slice_num(28), pwm_gpio_to_channel(28)}};
    constexpr uint led_count = sizeof leds / sizeof leds[0];

    const uint duties[] = {0,    0,    0,    0,   0,   0,   0,  0,  0,  0,
                           4095, 2047, 1023, 512, 256, 128, 64, 32, 16, 8,
                           0,    0,    0,    0,   0,   0,   0,  0,  0,  0};
    constexpr uint duties_count = sizeof duties / sizeof duties[0];

    for (int i = 0; i < led_count; i++) {
        gpio_set_function(leds[i].pin, GPIO_FUNC_PWM);

        pwm_set_wrap(leds[i].slice_num, 4095);
        pwm_set_enabled(leds[i].slice_num, true);
    }

    while (true) {
        for (int i = 0; i < duties_count - led_count; i++) {
            for (int j = 0; j < led_count; j++) {
                pwm_set_chan_level(leds[j].slice_num, leds[j].chan,
                                   duties[i + j]);
            }
            sleep_ms(DELAY);
        }

        for (int i = 0; i < duties_count - led_count; i++) {
            for (int j = 0; j < led_count; j++) {
                pwm_set_chan_level(leds[j].slice_num, leds[j].chan,
                                   duties[i + j]);
            }
            sleep_ms(DELAY);
        }
    }
}