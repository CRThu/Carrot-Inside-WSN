#ifndef __CLK_CONFIG_H__
#define __CLK_CONFIG_H__

#include "stm8l15x_clk.h"

#define SYSCLK_DIV CLK_SYSCLKDiv_1
//#define SYSCLK_DIV CLK_SYSCLKDiv_2
//#define SYSCLK_DIV CLK_SYSCLKDiv_4
//#define SYSCLK_DIV CLK_SYSCLKDiv_8
//#define SYSCLK_DIV CLK_SYSCLKDiv_16
//#define SYSCLK_DIV CLK_SYSCLKDiv_32
//#define SYSCLK_DIV CLK_SYSCLKDiv_64
//#define SYSCLK_DIV CLK_SYSCLKDiv_128

void CLK_Config_HSE(void);
void CLK_Config_HSI(void);
void CLK_Config_LSE(void);
void CLK_Config_LSI(void);


#endif