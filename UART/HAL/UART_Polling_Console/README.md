# UART_Polling_Console

This project made use of the STM32 HAL library to build a single-key command console over UART. It uses polling: the CPU waits for each individual key input instead of using interrupts.

## Hardware

- Board : NUCLEO-F446RE
- Pin : PA2 (USART2_TX) and PA3 (USART2_RX) go to the PC through the ST-LINK virtual COM port, PC13 is connected to the user button, PA5 is connected to the onboard green LED
- Serial settings : 115200 baud, 8 data bits, no parity, 1 stop bit

## What it does

First, the menu is printed once at startup. Afterwards, the main loop prints a prompt and waits for one single key input with HAL_UART_Receive. The input is echoed back and a switch statement runs the matching command:

| Key | Action |
|-----|--------|
| 1 | Toggle the green LED |
| 2 | Print the user button state (Pressed or Released) |
| 3 | Print uptime in milliseconds |
| 4 | Print how many keys have been pressed |
| h | Print the menu |

Any other key prints an unknown command message.

## Example session (PuTTY)

```
>1
LED toggled
>2
Button : Released
>3
Uptime: 16903 ms
>4
Commands run : 4
>5
Unknown command, press h
```

## Key Concepts

- Blocking transmit and receive with HAL_UART_Transmit and HAL_UART_Receive using HAL_MAX_DELAY
- Receiving a single byte into a uint8_t and comparing it against character literals in a switch
- Converting numbers to text with snprintf before sending, since UART only carries bytes
- A static variable keeps the key counter between function calls

## Comparison to Interrupt mode

By using HAL_MAX_DELAY blocks the CPU until an input is received, so nothing else can run while the console waits. 
By doing an interrupt-driven version it would receive the keys from the background with HAL_UART_Receive_IT and 
leave the main loop free for other tasks. Possible other tasks could be blinking an LED or sending a message. 

