//*****************************************************************************
//
//! \file main.c
//! \brief main application
//! \version 1.0.0.0
//! \date $Creat_time$
//! \author $Creat_author$
//! \copy
//!
//! Copyright (c) 2014 CooCox.  All rights reserved.
//
//! \addtogroup project
//! @{
//! \addtogroup main
//! @{
//*****************************************************************************
#include "stm32f10x.h"
#include "core_cm3.h"
#include "custom.h"
int i;
int main(void)
{
	/* Enable GPIOC's Clock from APB2, Bit4->1  */
	RCC->APB2ENR |= BIT4;


	/* Set PC8 Mode to Output mode speed 50Mhz  Bit[1:0]=11*/
	GPIOC->CRH |= BIT0 || BIT1;

	/* Set PC8 Config to Output push-pull */
	GPIOC->CRH &= ~BIT0 && ~BIT1;

	//GPIOC->ODR |= (uint32_t) 0x300;

	/* Set Pin8 On portC to 1 */
	GPIOC->BSRR |= BIT8;



	/* Setting Systick Configuration */

	//Set SYstick Clock to AHB/8
	//SysTick->CTRL &= (uint32_t)0xfffffffffb;

	//Set SYstick Clock to AHB
	SysTick->CTRL |= BIT2;

	//Enable Interuption Assertion
	SysTick->CTRL |= (uint32_t)0x2;
	//int Calibration_value = (uint32_t)(SysTick->CALIB & 0xffffff);

	//set Load value to 9000 by  aim 1ms
	//SysTick->LOAD = (uint32_t)9000;
	SysTick->LOAD = 8000 - 1;

	//Eanable Systick Counter
	SysTick->CTRL |= (uint32_t)0x1;


	while (1)
	{
	}
}

void SysTick_Handler(void)
{
	i++;
	if (i > 60000) GPIOC->BRR = BIT8;

}
