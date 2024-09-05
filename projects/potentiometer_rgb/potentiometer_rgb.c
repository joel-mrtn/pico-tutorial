#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"

#define ADC_THRESHOLD 4000
#define LED_COUNT 3

typedef struct {
    uint pin;
    uint slice_num;
    uint chan;
} led;

int main() {
    constexpr char adc_chnannels[LED_COUNT] = {26, 27, 28};
    const led leds[LED_COUNT] = {
        {15, pwm_gpio_to_slice_num(15), pwm_gpio_to_channel(15)},
        {14, pwm_gpio_to_slice_num(14), pwm_gpio_to_channel(14)},
        {13, pwm_gpio_to_slice_num(13), pwm_gpio_to_channel(13)}};

    adc_init();

    for (int i = 0; i < LED_COUNT; i++) {
        gpio_set_function(leds[i].pin, GPIO_FUNC_PWM);

        pwm_set_wrap(leds[i].slice_num, 4095);
        pwm_set_enabled(leds[i].slice_num, true);

        adc_gpio_init(adc_chnannels[i]);
    }

    while (true) {
        for (int i = 0; i < LED_COUNT; i++) {
            // ADC inputs are contiguous
            adc_select_input(adc_chnannels[i] - adc_chnannels[0]);
            const uint16_t adc_value = adc_read();

            pwm_set_chan_level(leds[i].slice_num, leds[i].chan,
                               adc_value > ADC_THRESHOLD ? 4100 : adc_value);
        }
        sleep_ms(10);
    }
}