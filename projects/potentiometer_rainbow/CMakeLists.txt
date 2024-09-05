add_executable(potentiometer_rainbow potentiometer_rainbow.c)

# generate the header file into the source tree as it is included in the RP2040 datasheet
file(MAKE_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/generated)
pico_generate_pio_header(potentiometer_rainbow ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

target_link_libraries(potentiometer_rainbow pico_stdlib hardware_pio hardware_adc)

pico_add_extra_outputs(potentiometer_rainbow)