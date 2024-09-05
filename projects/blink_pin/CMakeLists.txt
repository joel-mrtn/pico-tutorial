add_executable(blink_pin blink_pin.c)

target_link_libraries(blink_pin pico_stdlib)

pico_add_extra_outputs(blink_pin)