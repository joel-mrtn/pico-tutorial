add_executable(button_led button_led.c)

target_link_libraries(button_led pico_stdlib)

pico_add_extra_outputs(button_led)