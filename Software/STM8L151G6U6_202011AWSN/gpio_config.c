#include "gpio_config.h"

/**
* @brief  Configure GPIO
* @param  None
* @retval None
*/

void GPIO_Config_Init(void)
{
    CLK_LSEConfig(CLK_LSE_OFF);   // USE C5 & C6

    // LED
    GPIO_Init(GPIOD, GPIO_Pin_4, GPIO_Mode_Out_PP_Low_Slow);    // LED1
    GPIO_Init(GPIOC, GPIO_Pin_5, GPIO_Mode_Out_PP_Low_Slow);    // LED2

    // KEY
    GPIO_Init(GPIOB, GPIO_Pin_2, GPIO_Mode_In_PU_No_IT);        // KEY1
    GPIO_Init(GPIOC, GPIO_Pin_6, GPIO_Mode_In_PU_No_IT);        // KEY2

    // ADC_CTL
    GPIO_Init(GPIOD, GPIO_Pin_2, GPIO_Mode_Out_PP_Low_Slow);    // ADC_CTL

    // 4051
    GPIO_Init(GPIOD, GPIO_Pin_1, GPIO_Mode_Out_PP_Low_Slow);    // 4051_CHA
    GPIO_Init(GPIOD, GPIO_Pin_0, GPIO_Mode_Out_PP_Low_Slow);    // 4051_CHB

    // PUMP_CTL
    GPIO_Init(GPIOA, GPIO_Pin_4, GPIO_Mode_Out_PP_Low_Slow);    // PUMP_CTL
}