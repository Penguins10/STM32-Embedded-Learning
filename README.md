# STM32-Embedded-Learning
A hands-on learning repository for embedded systems development using STM32 microcontrollers. Projects are implemented in both HAL and bare-metal approaches. Primary hardware is the STM32F446RE (Cortex-M4) Nucleo board, with the STM32H753ZI (Cortex-M7) used for advanced topics.

**Hardware:** NUCLEO-F446RE (STM32F446, Cortex-M4) · NUCLEO-H753ZI (Cortex-M7) for advanced topics
**Tools:** STM32CubeIDE, CubeMX
**References:** RM0390 reference manual, UM1724 board manual, Mastering STM32, Stm32f446re Schematic, stm32f446mc Datasheet

## Projects

| Peripheral | Project | HAL | Bare-Metal | Description |
|---|---|:-:|:-:|---|
| GPIO | LED Blink / Register Manipulation | ✅ | ✅ | Toggle LD2 (PA5) via RCC/MODER/ODR registers |
| GPIO | Button Interrupt | ✅ | — | PC13 falling-edge EXTI toggles LD2 |
| UART | Polling & Interrupt-Driven Serial | 🚧 | 🚧 | In progress |
| DMA |                                   |  |  |  |
| Timers/PWM |                            |  |  |  |
| ADC |                                   |  |  |  |
| I2C |                                   |  |  |  |
| SPI |                                   |  |  |  |

## Roadmap
GPIO → Interrupts/NVIC → UART → DMA → Timers/PWM → ADC → I2C → SPI 
→ **Capstone:** BME280 environmental data logger (I2C sensor, timer-driven sampling, UART streaming)

## Repo Structure
Each peripheral has its own folder with `HAL/` and `Bare_Metal/` subfolders,
one project per folder, each with its own README.
