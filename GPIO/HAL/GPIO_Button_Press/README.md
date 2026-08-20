# HAL-GPIO-Button_Press
This project made use of the STM32 HAL library in order to setup a GPIO interrupt triggered by a button press, instead of polling the pin state

# Hardware
- Board : NUCLEO-F446RE
- Pin : PC13 connected to user button, PA5 connected to onboard green LED

# What it does 
First, PC13 is configured as an external interrupt input with a falling edge detection. Afterwards when the button is pressed, the EXTI interrupt fires which in turn calls HAL_GPIO_EXTI_Callback, which in turn toggles PA5 which is connected to the green LED. This in turn will turn the LED on or off. 

# Key Concepts
- GPIO interrupt configuration via CubeMX
- NVIC interrupt enabled for the EXTI line
- HAL_GPIO_EXTI_Callback being used as the interrupt service routine entry point
- External pull-up resistor on board is used for a reliable falling-edge detection
- Toggling the GPIO output of PA5 via HAL_GPIO_TogglePin in response to an interrupt event

# Comparison to Bare-Metal
Unlike the bare-metal implementation, HAL takes away the use of direct register configuration. Instead when using CubeMX it generates the pin/interrupt setup. Meanwhile the callback function handles the interrupt logic without manually touching EXTI_IMR, EXTI_FTSR, or NVIC registers directly.
