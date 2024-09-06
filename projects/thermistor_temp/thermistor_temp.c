#include "hardware/adc.h"
#include "pico/stdlib.h"

#include <math.h>
#include <stdio.h>

#define PIN_ANALOG_IN 26

#define THERMISTOR_NOMINAL 10000.0 // Resistance at 25 degrees C
#define TEMPERATURE_NOMINAL 25.0   // Temperature for nominal resistance
#define B_COEFFICIENT 3950.0       // The beta coefficient of the thermistor
#define SERIES_RESISTOR 10000.0    // The value of the circuit resistor

int main(void) {
    stdio_init_all();

    adc_init();
    adc_gpio_init(PIN_ANALOG_IN);
    adc_select_input(0);

    while (true) {
        const uint16_t adcValue = adc_read();

        // Voltage (Pico's ADC is 12-bit, so max value is 4095)
        const double voltage = (double)adcValue / 4095.0 * 3.3;
        // Resistance value of thermistor
        const double resistance_t = SERIES_RESISTOR * voltage / (3.3 - voltage);

        // Calculate temperature
        const double temp_c =
            1.0 / (1.0 / TEMPERATURE_NOMINAL +
                   log(resistance_t / THERMISTOR_NOMINAL) / B_COEFFICIENT);
        const double temp_k = temp_c + 273.15;

        printf("Voltage: %.2fV,\t\tKelvins: %.2fK,\tTemperature: %.2fC\n",
               voltage, temp_k, temp_c);

        sleep_ms(1000);
    }
}