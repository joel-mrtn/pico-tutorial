add_executable(rgb_gradient_led rgb_gradient_led.c)

target_link_libraries(rgb_gradient_led pico_stdlib hardware_pwm)

pico_add_extra_outputs(rgb_gradient_led)