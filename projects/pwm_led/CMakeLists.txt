add_executable(pwm_led pwm_led.c)

target_link_libraries(pwm_led pico_stdlib hardware_pwm)

pico_add_extra_outputs(pwm_led)