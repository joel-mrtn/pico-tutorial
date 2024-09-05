#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"

#define PIN_ANALOG_IN 26
#define PIN_LED 15
#define THRESHOLD 200

int main(void) {
    adc_init();
    adc_gpio_init(PIN_ANALOG_IN);
    adc_select_input(0);

    const uint slice_num = pwm_gpio_to_slice_num(PIN_LED);
    const uint chan = pwm_gpio_to_channel(PIN_LED);

    gpio_set_function(PIN_LED, GPIO_FUNC_PWM);
    pwm_set_wrap(slice_num, 4095);
    pwm_set_enabled(slice_num, true);

    while (true) {
        const uint16_t adc_value = adc_read();
        const uint16_t pwm_value =
            adc_value < THRESHOLD
                ? 0
                : (adc_value - THRESHOLD) * 4095 / (4095 - THRESHOLD);

        pwm_set_chan_level(slice_num, chan, pwm_value);
        sleep_ms(100);
    }
}