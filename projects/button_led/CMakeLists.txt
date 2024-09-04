add_executable(button_led button_led.c)

pico_add_extra_outputs(button_led)

target_link_libraries(button_led pico_stdlib)
