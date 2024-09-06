# Pico Tutorial Projects

This repository contains implementations of Raspberry Pi Pico W tutorial projects using the Pico SDK. These projects
are based on
the [Freenove Ultimate Starter Kit for Raspberry Pi Pico](https://github.com/Freenove/Freenove_Ultimate_Starter_Kit_for_Raspberry_Pi_Pico),
but have been adapted to use the official
[Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk) instead of the Arduino IDE. Each project is contained
in its own directory, with a `CMakeLists.txt` file for building with the Pico SDK.

> [!NOTE]
> Please note that some projects have been implemented with modifications or additional features and do not exactly
> match the original Freenove examples.

## Setup requirements

- Ensure that you have set the `PICO_SDK_PATH` environment variable. This variable should point to the location of the
  Pico SDK on your system.

  ```shell
  export PICO_SDK_PATH=/path/to/your/pico-sdk
  ```
- If you are using a Raspberry Pi Pico W (wireless version), you need to specify this when running CMake. Add the
  following option to your CMake command.

  ```shell
  cmake -DPICO_BOARD=pico_w
  ```

## Project list

1. [Blink (builtin)](https://github.com/joel-mrtn/pico-tutorial/tree/main/projects/blink_builtin)
2. [Blink (pin)](https://github.com/joel-mrtn/pico-tutorial/tree/main/projects/blink_pin)
3. [Button LED](https://github.com/joel-mrtn/pico-tutorial/tree/main/projects/button_led)
4. [Flowing light](https://github.com/joel-mrtn/pico-tutorial/tree/main/projects/flowing_light)
5. [PWM LED](https://github.com/joel-mrtn/pico-tutorial/tree/main/projects/pwm_led)
6. [Flowing meteor light](https://github.com/joel-mrtn/pico-tutorial/tree/main/projects/flowing_meteor_light)
7. [RGB LED](https://github.com/joel-mrtn/pico-tutorial/tree/main/projects/rgb_led)
8. [RGB gradient LED](https://github.com/joel-mrtn/pico-tutorial/tree/main/projects/rgb_gradient_led)
9. [WS2812 (NeoPixel)](https://github.com/joel-mrtn/pico-tutorial/tree/main/projects/ws2812)
10. [Doorbell (active buzzer)](https://github.com/joel-mrtn/pico-tutorial/tree/main/projects/buzzer_active)
11. [Alarm (passive buzzer)](https://github.com/joel-mrtn/pico-tutorial/tree/main/projects/buzzer_passive)
12. [Serial communication](https://github.com/joel-mrtn/pico-tutorial/tree/main/projects/serial_communication)
13. [Potentiometer voltage](https://github.com/joel-mrtn/pico-tutorial/tree/main/projects/potentiometer_voltage)
14. [Potentiometer LED](https://github.com/joel-mrtn/pico-tutorial/tree/main/projects/potentiometer_led)
15. [Potentiometer RGB](https://github.com/joel-mrtn/pico-tutorial/tree/main/projects/potentiometer_rgb)
16. [Potentiometer rainbow](https://github.com/joel-mrtn/pico-tutorial/tree/main/projects/potentiometer_rainbow)
17. [Photoresistor LED](https://github.com/joel-mrtn/pico-tutorial/tree/main/projects/photoresistor_led)
18. [Thermistor temperature](https://github.com/joel-mrtn/pico-tutorial/tree/main/projects/thermistor_temp)
19. [Joystick output](https://github.com/joel-mrtn/pico-tutorial/tree/main/projects/joystick_out)