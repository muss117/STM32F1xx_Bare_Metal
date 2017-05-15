#include "stm32f10x.h"
#include "custom.h"

void SystemInit(void)
{

	/* Enable HSI-RC Bit0->1 */
	RCC->CR |= BIT0;

	/* Set PLL Source As HSI/2 Bit 16->0 */
	RCC->CFGR &= ~BIT16;

	// Set PLLMUL to 6-> Bit 20 ->1 */
	RCC->CFGR |= BIT20;

	//Set SYSCLK Source As PLL bit 1 ->1
	RCC->CFGR |= BIT1;

	// Set AHB Prescalar to 8 bit[7:4]: 1010
	//RCC->CFGR |= (BIT5 || BIT7);

	/* Select HSI as System Clock */
	//RCC->CFGR &= ~BIT0 & ~BIT1; // OR Nothing (Reset State)

	/* Set AHPR prescalar as Bit7 ->0 */
	//RCC->CFGR &= ~BIT7; //Or reset state

	/* Set APB2 prescalar to 1 BIT13->0 */
	//RCC->CFGR &= ~BIT13;

}
