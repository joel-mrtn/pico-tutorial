add_executable(joystick_out joystick_out.c)

target_link_libraries(joystick_out pico_stdlib hardware_adc)

pico_enable_stdio_usb(joystick_out 1)

pico_add_extra_outputs(joystick_out)