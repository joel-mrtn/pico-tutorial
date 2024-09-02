#include "pico/stdlib.h"
#include <math.h>

#define PIN_BUZZER 15
#define PIN_BUTTON 16
#define VOLUME 0.05

void set_freq(uint pin, int freq, int times, float volume);

int main(void) {
    gpio_init(PIN_BUZZER);
    gpio_set_dir(PIN_BUZZER, GPIO_OUT);
    gpio_put(PIN_BUZZER, false);

    gpio_init(PIN_BUTTON);
    gpio_set_dir(PIN_BUTTON, GPIO_IN);
    gpio_pull_up(PIN_BUTTON);

    while (true) {
        if (gpio_get(PIN_BUTTON) == false) {
            for (int x = 0; x < 360; x += 10) {
                // Oscillate between 1500 Hz and 2500 Hz
                const double sin_val = sin(x * (M_PI / 180.0));
                const int tone_val = (int)(2000 + sin_val * 500);

                set_freq(PIN_BUZZER, tone_val, 10, VOLUME);
            }
        } else {
            set_freq(PIN_BUZZER, 0, 10, VOLUME);
        }
        sleep_ms(10);
    }
}

void set_freq(uint pin, int freq, int times, float volume) {
    if (freq == 0) {
        gpio_put(pin, false);
    } else {
        const int on_time = (int)(1000000.0 / freq / 2 * volume);
        const int off_time = (int)(1000000.0 / freq / 2 * (1.0f - volume));

        for (int i = 0; i < times * freq / 1000; i++) {
            gpio_put(pin, true);
            sleep_us(on_time); // Delay for half period
            gpio_put(pin, false);
            sleep_us(off_time); // Delay for half period
        }
    }
}