/*
 * ATimer.c
 *
 *  Created on: Dec 13, 2023
 *      Author: cody.chiang
 */

#include "ATimer.h"

uint32_t simpleMs_TimerStart()
{
    return platform_current_time()/kMSTimeFactor;
}

uint32_t simpleMs_TimerElapsed(uint32_t startTime_ms)
{
    return simpleUs_TimerElapsed(startTime_ms * kMSTimeFactor) / kMSTimeFactor;
}

uint32_t simpleUs_TimerStart()
{
    return platform_current_time();
}

uint32_t simpleUs_TimerElapsed(uint32_t startTime_us)
{
    uint32_t current_us = (uint32_t)platform_current_time();
    return (current_us - startTime_us);
}



