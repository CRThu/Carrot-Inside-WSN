#ifndef __GPIO_CONFIG_H__
#define __GPIO_CONFIG_H__

#include "stm8l15x_gpio.h"

#define GPIO_KEY1()         ((GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_2) == RESET) ? 0 : 1)
#define GPIO_KEY2()         ((GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_6) == RESET) ? 0 : 1)

#define GPIO_LED1(x)        GPIO_WriteBit(GPIOD, GPIO_Pin_4, (x == 1) ? SET : RESET)
#define GPIO_LED2(x)        GPIO_WriteBit(GPIOC, GPIO_Pin_5, (x == 1) ? SET : RESET)

#define GPIO_ADC_CTL(x)     GPIO_WriteBit(GPIOD, GPIO_Pin_2, (x == 1) ? SET : RESET)
#define GPIO_4051_CHA(x)    GPIO_WriteBit(GPIOD, GPIO_Pin_1, (x == 1) ? SET : RESET)
#define GPIO_4051_CHB(x)    GPIO_WriteBit(GPIOD, GPIO_Pin_0, (x == 1) ? SET : RESET)

#define GPIO_PUMP_CTL(x)    GPIO_WriteBit(GPIOA, GPIO_Pin_4, (x == 1) ? SET : RESET)

#define GPIO_OLED_CTL(x)    GPIO_WriteBit(GPIOC, GPIO_Pin_4, (x == 1) ? SET : RESET)


void GPIO_Config_Init(void);

#endif