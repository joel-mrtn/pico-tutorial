add_executable(flowing_light flowing_light.c)

pico_add_extra_outputs(flowing_light)

target_link_libraries(flowing_light pico_stdlib)
