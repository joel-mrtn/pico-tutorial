cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(pico_tutorial C CXX ASM)
set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 23)
pico_sdk_init()

add_compile_options(-Wall)

add_subdirectory(blink_builtin)
add_subdirectory(blink_pin)
add_subdirectory(button_led)
add_subdirectory(buzzer_active)
add_subdirectory(buzzer_passive)
add_subdirectory(flowing_light)
add_subdirectory(flowing_meteor_light)
add_subdirectory(pwm_led)
add_subdirectory(rgb_gradient_led)
add_subdirectory(rgb_led)
add_subdirectory(serial_communication)
add_subdirectory(ws2812)