# Pico Tutorial Projects

This repository contains implementations of Raspberry Pi Pico W tutorial projects using the Pico SDK. These projects
are based on
the [Freenove Ultimate Starter Kit for Raspberry Pi Pico](https://github.com/Freenove/Freenove_Ultimate_Starter_Kit_for_Raspberry_Pi_Pico),
but have been adapted to use the official
[Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk) instead of the Arduino IDE. Each project is contained
in its own directory, with a CMakeLists.txt file for building with the Pico SDK.

> [!NOTE]
> Please note that some projects have been implemented with modifications or additional features and do not exactly
> match the original Freenove examples.

## Setup requirements

- Ensure that you have set the PICO_SDK_PATH environment variable. This variable should point to the location of the
  Pico SDK on your system.

  ```shell
  export PICO_SDK_PATH=/path/to/your/pico-sdk
  ```
- If you are using a Raspberry Pi Pico W (wireless version), you need to specify this when running CMake. Add the
  following option to your CMake command.

  ```shell
  cmake -DPICO_BOARD=pico_w
  ```