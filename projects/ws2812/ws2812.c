#include "hardware/pio.h"
#include "pico/stdlib.h"
#include "ws2812.pio.h"

#define PIN 16
#define NUM_PIXELS 8
#define BRIGHTNESS 20 // (0-255)

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} rgb_color;

void set_pixels(PIO pio, uint sm, rgb_color color_buf[], uint num_pixels,
                uint brightness);
rgb_color gradient_wheel(int pos);

int main(void) {
    auto pio = pio0;
    uint offset = pio_add_program(pio, &ws2812_program);
    uint sm = pio_claim_unused_sm(pio, true);
    ws2812_program_init(pio, sm, offset, PIN, 800000, false);

    const rgb_color circle_colors[] = {
        {0, 255, 0},     // Green
        {0, 0, 255},     // Blue
        {255, 255, 255}, // White
        {0, 0, 0},       // Off
        {255, 0, 0},     // Red
    };
    constexpr uint num_circle_colors =
        sizeof circle_colors / sizeof circle_colors[0];

    rgb_color strip_buf[NUM_PIXELS] = {0};

    while (1) {
        // Circle
        for (int j = 0; j < num_circle_colors; j++) {
            for (int i = 0; i < NUM_PIXELS; i++) {
                strip_buf[i] = circle_colors[j];
                set_pixels(pio, sm, strip_buf, NUM_PIXELS, BRIGHTNESS);
                sleep_ms(100);
            }
            sleep_ms(500);
        }

        // Rainbow
        for (int j = 0; j < 255; j++) {
            for (int i = 0; i < NUM_PIXELS; i++) {
                strip_buf[i] = gradient_wheel(j);
                set_pixels(pio, sm, strip_buf, NUM_PIXELS, BRIGHTNESS);
            }
            sleep_ms(10);
        }
    }
}

void set_pixels(PIO pio, uint sm, rgb_color color_buf[], uint num_pixels,
                uint brightness) {
    for (int i = 0; i < num_pixels; i++) {
        const uint pixel = color_buf[i].g * brightness / 255 << 16 |
                           color_buf[i].r * brightness / 255 << 8 |
                           color_buf[i].b * brightness / 255;
        pio_sm_put_blocking(pio, sm, pixel << 8u);
    }
}

rgb_color gradient_wheel(int pos) {
    rgb_color color;
    long wheel_pos = pos % 255;

    if (wheel_pos < 85) {
        // Decrease red, increase green
        color.r = 255 - wheel_pos * 3;
        color.g = wheel_pos * 3;
        color.b = 0;
    } else if (wheel_pos < 170) {
        // Decrease green, increase blue
        wheel_pos -= 85;
        color.r = 0;
        color.g = 255 - wheel_pos * 3;
        color.b = wheel_pos * 3;
    } else {
        // Decrease blue, increase red
        wheel_pos -= 170;
        color.r = wheel_pos * 3;
        color.g = 0;
        color.b = 255 - wheel_pos * 3;
    }

    return color;
}