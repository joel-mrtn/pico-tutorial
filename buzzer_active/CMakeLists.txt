add_executable(buzzer_active buzzer_active.c)

pico_add_extra_outputs(buzzer_active)

target_link_libraries(buzzer_active pico_stdlib)
