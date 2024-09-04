#include "hardware/pwm.h"
#include "pico/stdlib.h"

#include <time.h>

#define DELAY 100
#define DIMMING 5

typedef struct {
    uint pin;
    uint slice_num;
    uint chan;
} led;

long gradient_wheel(const int pos) {
    long wheel_pos = pos % 0xff;
    long rgb;

    if (wheel_pos < 85) {
        // Decrease red, increase green
        rgb = (255 - wheel_pos * 3) << 16 | wheel_pos * 3 << 8;
    } else if (wheel_pos < 170) {
        // Decrease green, increase blue
        wheel_pos -= 85;
        rgb = (255 - wheel_pos * 3) << 8 | wheel_pos * 3;
    } else {
        // Decrease blue, increase red
        wheel_pos -= 170;
        rgb = (wheel_pos * 3) << 16 | (255 - wheel_pos * 3);
    }

    return rgb;
}

int main() {
    const led leds[] = {
        {13, pwm_gpio_to_slice_num(13), pwm_gpio_to_channel(13)},
        {12, pwm_gpio_to_slice_num(12), pwm_gpio_to_channel(12)},
        {11, pwm_gpio_to_slice_num(11), pwm_gpio_to_channel(11)}};
    constexpr uint led_count = sizeof leds / sizeof leds[0];

    for (int i = 0; i < led_count; i++) {
        gpio_set_function(leds[i].pin, GPIO_FUNC_PWM);

        pwm_set_wrap(leds[i].slice_num, 255);
        pwm_set_enabled(leds[i].slice_num, true);
    }

    const led *red = &leds[0];
    const led *green = &leds[1];
    const led *blue = &leds[2];

    while (true) {
        for (int i = 0; i <= 255; i++) {
            const long rgb = gradient_wheel(i);

            const uint red_value = 255 - (rgb >> 16 & 0xFF) / DIMMING;
            const uint green_value = 255 - (rgb >> 8 & 0xFF) / DIMMING;
            const uint blue_value = 255 - (rgb & 0xFF) / DIMMING;

            pwm_set_chan_level(red->slice_num, red->chan, red_value);
            pwm_set_chan_level(green->slice_num, green->chan, green_value);
            pwm_set_chan_level(blue->slice_num, blue->chan, blue_value);

            sleep_ms(DELAY);
        }
    }
}