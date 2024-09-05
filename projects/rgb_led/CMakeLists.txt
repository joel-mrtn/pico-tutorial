add_executable(rgb_led rgb_led.c)

target_link_libraries(rgb_led pico_stdlib hardware_pwm)

pico_add_extra_outputs(rgb_led)