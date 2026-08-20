# Bare-Metal Register Manipulation
This project made use of direct register-level GPIO configuration, by use of memory-mapped register access instead of using HAL

# Hardware
- Board : NUCLEO-F446RE
- Pin : PA5 connected to onboard green LED

# What it does 
First, PA5 is configured as an output. Afterwards inside of a loop, XOR is used in order to change the current state of the pin after every run. Which
in turn results in the LED turning on or off depending if it is high and swapped to low.

# Key Concepts
- Peripheral address calculation : base address + bus offset
- Enabling Peripheral clock via RCC_AHB1ENR
- Configuring Pin mode as output via GPIOx_MODER which consists of 2 bits for every pin
- Driving the pin output via GPIOx_ODR
- Bitwise mask used for clearing, setting, and toggling operations for register manipulation
- Delay used in order to visibly see the LED change

# Comparison to HAL
Unlike HAL version every peripheral and register address had to be manually found via offset + base address in order to directly manipulate the bits connected to that pin.
