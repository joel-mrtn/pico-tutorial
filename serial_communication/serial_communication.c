#include "pico/stdlib.h"
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 128

void flush_input_buffer(void);

int main(void) {
    stdio_init_all();

    sleep_ms(2000);
    flush_input_buffer();

    printf("Type something and press enter:\n");

    while (true) {
        char input[BUFFER_SIZE] = {0};

        fgets(input, BUFFER_SIZE, stdin);
        printf("You entered: %s\n", input);
    }
}

void flush_input_buffer(void) {
    // Read and discard all characters until the buffer is empty
    while (stdio_getchar_timeout_us(0) != PICO_ERROR_TIMEOUT) {
        // Do nothing, just discard the character
    }
}