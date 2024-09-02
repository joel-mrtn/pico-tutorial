add_executable(blink_pin blink_pin.c)

pico_enable_stdio_usb(blink_pin 1)
pico_enable_stdio_uart(blink_pin 1)

pico_add_extra_outputs(blink_pin)

target_link_libraries(blink_pin pico_stdlib)
