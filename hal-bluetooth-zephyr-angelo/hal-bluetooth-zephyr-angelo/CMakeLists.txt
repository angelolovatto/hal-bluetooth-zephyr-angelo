# CMakeLists.txt - Aplicação Zephyr HAL + Bluetooth

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(hal_bluetooth_zephyr)

target_include_directories(app PRIVATE include)

target_sources(app PRIVATE
    src/main.c
    src/hal_gpio.c
    src/hal_bt.c
)
