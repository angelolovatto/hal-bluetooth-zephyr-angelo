# HAL Bluetooth + Zephyr

Individual academic project developed by **Angelo Luigi Bocchi Lovatto**, Computer Engineering student at the **Federal University of Santa Maria (UFSM)**.

The project explores the organization of a small **Hardware Abstraction Layer (HAL)** on top of **Zephyr RTOS**, using the **SAMD21 Xplained Pro** as the main target platform and a BLE abstraction layer designed around Zephyr's Bluetooth APIs.

## What I worked on

- Embedded C application structure with Zephyr RTOS
- GPIO abstraction through a small HAL
- BLE initialization/advertising abstraction using Zephyr APIs
- CMake/west-based Zephyr project organization
- Separation between hardware-facing code and application logic
- Documentation of integration limitations and next steps

## Technologies

`C` · `Zephyr RTOS` · `SAMD21` · `GPIO` · `BLE` · `CMake` · `west` · `Device Tree concepts`

## Project status

The GPIO HAL and application structure were implemented as part of the academic project. The BLE layer is a **software integration skeleton**: complete physical integration with an external BTLC1000 module would still require board-specific Device Tree and driver work.

This distinction is intentional so the repository accurately reflects what was implemented and what remained as future work.

## Source code

The project files are currently stored under:

[`hal-bluetooth-zephyr-angelo/hal-bluetooth-zephyr-angelo/`](hal-bluetooth-zephyr-angelo/hal-bluetooth-zephyr-angelo/)

## Academic context

Developed for coursework in **Embedded Systems Design** at UFSM.

## Author

**Angelo Luigi Bocchi Lovatto**  
Computer Engineering — UFSM
