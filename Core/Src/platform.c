/*
 * platform.c
 *
 *  Created on: Dec 13, 2023
 *      Author: cody.chiang
 */

#include "platform.h"
#include "stm32f091xc.h"
#include "stm32f0xx_hal.h"

void InitializeTickTimer();
void EnableTickTimer(__BOOL enable);

void PlatformInitialize()
{
	InitializeTickTimer();
}

void InitializeTickTimer()
{
  /* Disable */
  TIM2->CR1 = 0x00000000;

  /* SystemCoreClock is 180MHz. */
  /* Prescaler - 180 gives 1us resolution */
  uint32_t pclk1Freq = HAL_RCC_GetPCLK1Freq();
  TIM2->PSC = (pclk1Freq*2/1000000)-1;

  /* Start the count at the end.  Certain registers (PSC,ARR,...) are */
  /* "shadowed" and only get updated on a rollover or other event. */
  TIM2->CNT = 0xFFFFFFFF;

  /* Period/Reload - a long period give a free-running time-stamp-mode timer */
  TIM2->ARR = 0xFFFFFFFF;

  /* Enable! */
  EnableTickTimer(TRUE);

  /* Enable and set TIM2 Interrupt */
//  TIM2->SR = 0;
//  HAL_NVIC_SetPriority(TIM2_IRQn, 1, 0);
//  HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

void EnableTickTimer(__BOOL enable)
{
  if (enable) {
    TIM2->CR1 |= TIM_CR1_CEN;
  }
  else {
    TIM2->CR1 &= ~TIM_CR1_CEN;
  }
}

//usecond
uint32_t platform_current_time(void)
{
    return TIM2->CNT;
}
