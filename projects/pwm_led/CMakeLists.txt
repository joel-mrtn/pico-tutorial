add_executable(pwm_led pwm_led.c)

pico_add_extra_outputs(pwm_led)

target_link_libraries(pwm_led pico_stdlib hardware_pwm)