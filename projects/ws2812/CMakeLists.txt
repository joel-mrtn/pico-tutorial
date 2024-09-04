add_executable(ws2812 ws2812.c)

# generate the header file into the source tree as it is included in the RP2040 datasheet
file(MAKE_DIRECTORY generated)
pico_generate_pio_header(ws2812 ws2812.pio OUTPUT_DIR generated)

pico_add_extra_outputs(ws2812)

target_link_libraries(ws2812 pico_stdlib hardware_pio)