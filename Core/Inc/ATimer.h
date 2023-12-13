/*
 * ATimer.h
 *
 *  Created on: Dec 13, 2023
 *      Author: cody.chiang
 */

#ifndef _ATIMER_H_
#define _ATIMER_H_

#include "ATypes.h"

#define kMSTimeFactor   1000  /* ARM platform timer set for 1us */

uint32_t simpleMs_TimerStart();
uint32_t simpleMs_TimerElapsed(uint32_t startTime_ms);
uint32_t simpleUs_TimerStart();
uint32_t simpleUs_TimerElapsed(uint32_t startTime_us);

#endif /* _ATIMER_H_ */
