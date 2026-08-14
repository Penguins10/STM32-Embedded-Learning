/**
 ******************************************************************************
 * @file           : main.c
 * @Jerry Cruz
 * @brief
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2026 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

// 1: THE BASE ADDRESS WHERE ALL PERIPHERALS BEGIN AT FOR THIS BOARD
#define PERIPH_BASE		   (0X40000000UL)


// 2: THE OFFSET ADDRESS FOR AHB1 PERIPHERALS BUS WHICH IS WHERE GPIOA IS LOCATED
#define AHB1PERIPH_OFFSET  (0X00020000UL)

// 3: THE BASE ADDRESS FOR AHB1 PERIPHERALS
#define AHB1PERIPH_BASE    (PERIPH_BASE + AHB1PERIPH_OFFSET)


// 4: THE OFFSET FOR GPIOA
#define GPIOA_OFFSET       (0X00000000UL)


// 5: THE BASE ADDRESS FOR GPIOA
#define GPIOA_BASE         (AHB1PERIPH_BASE + 0X00000000UL)


// 6: OFFSET FOR RCC
#define RCC_OFFSET		   (0X00003800UL)


// 7: THE BASE ADDRESS FOR RCC
#define RCC_BASE		   (AHB1PERIPH_BASE + RCC_OFFSET)


// 8: THE OFFSET FOR AHB1EN REGISTER
#define AHB1EN_R_OFFSET      (0X30UL)


// 9: THE ADDRESS OF AHB1EN REGISTER
#define RCC_AHB1EN_R        (*(volatile unsigned int*)(RCC_BASE + AHB1EN_R_OFFSET))

//MODER IS NEEDED TO SETUP PINS AS EITHER INPUT, OUTPUT, ANALOG, ETC..
// 10: THE OFFSET FOR MODE REGISTER
#define MODE_R_OFFSET      (0X00UL)


// 11: THE ADDRESS OF GPIOA MODE REGISTER
#define GPIOA_MODE_R       (*(volatile unsigned int*)(GPIOA_BASE +  MODE_R_OFFSET))


// 12: THE OFFSET FOR OUTPUT DATA REGISTER
#define OD_R_OFFSET        (0X14UL)


// 13: THE ADDRESS OF GPIOA OUTPUT DATA REGISTER
#define GPIOA_D_R           (*(volatile unsigned int*)(GPIOA_BASE + OD_R_OFFSET))

// 14: THE BIT MASK FOR ENABLING GPIOA BIT 0
#define GPIOAEN             (1U<<0)


// 15: THE BIT MASK FOR GPIOA PIN 5
#define PIN5                (1U<<5)


// 16: THE NAME ALIAS FOR PIN WHICH IS CONNECTED/REPRESENTING LED PIN
#define LED_PIN             PIN5



int main(void)
{
// ENABLING CLOCK ACCESS TO GPIOA
	RCC_AHB1EN_R |= GPIOAEN;

//SETTING BIT 10 TO 1 ( ITS JUST TO TURN IT ON)
	GPIOA_MODE_R |= (1U << 10);

// SETTING BIT 11 TO 0 (CLEARING BIT 11)
	GPIOA_MODE_R &= ~(1U << 11);

// THE START OF THE INFINTE LOOP
	while (1)
	{
		// SETTING PA5 WHICH IS OUR LED PIN TO HIGH
		GPIOA_D_R |= LED_PIN ;
	}
    /* Loop forever */

}
