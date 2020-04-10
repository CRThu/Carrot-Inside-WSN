#ifndef __ADC_CONFIG_H__
#define __ADC_CONFIG_H__

#include "stm8l15x_adc.h"

void ADC_Config();
uint16_t ADC_Config_Read_Vref();
uint16_t ADC_Config_Read_CH1(uint16_t Vref);

#endif