#include "app_func.h"

void App_Sys_Init()
{
    CLK_Config_HSE();
    GPIO_Config_Init();
    ADC_Config();
}

void App_OLED_Init()
{
    IIC_Config_Init();
    GPIO_OLED_CTL(1);
    OLED_Init();
    OLED_Clear();
}

// mV Power D3V3
uint16_t App_ADC_Read_D3V3()
{
    return ADC_Config_Read_Vref();
}

// mV P11 4051::Y3 CHA=H CHB=H
uint16_t App_ADC_Read_Soil_CH0()
{
    GPIO_4051_CHA(1);
    GPIO_4051_CHB(1);

    uint16_t Vref = ADC_Config_Read_Vref();
    return ADC_Config_Read_CH1(Vref);
}

// mV P8 4051::Y0 CHA=L CHB=L
uint16_t App_ADC_Read_Soil_CH1()
{
    GPIO_4051_CHA(0);
    GPIO_4051_CHB(0);

    uint16_t Vref = ADC_Config_Read_Vref();
    return ADC_Config_Read_CH1(Vref);
}

// mV P9 4051::Y1 CHA=H CHB=L
uint16_t App_ADC_Read_Soil_CH2()
{
    GPIO_4051_CHA(1);
    GPIO_4051_CHB(0);

    uint16_t Vref = ADC_Config_Read_Vref();
    return ADC_Config_Read_CH1(Vref);
}

// mV P10 4051::Y2 CHA=H CHB=L
uint16_t App_ADC_Read_Soil_CH3()
{
    GPIO_4051_CHA(0);
    GPIO_4051_CHB(1);

    uint16_t Vref = ADC_Config_Read_Vref();
    return ADC_Config_Read_CH1(Vref);
}

int8_t App_Soil_Humi(uint16_t adc)
{
    if(adc > SOIL_CHX_3K3_CHX_mV)
        return -1;  // Short
    else if(adc < SOIL_CHX_30K_CHX_mV)
        return -2;  // Open
    else
        return ((float)adc - (float)SOIL_CHX_30K_CHX_mV)/((float)SOIL_CHX_3K3_CHX_mV - (float)SOIL_CHX_30K_CHX_mV) * (float)100;
}

// BAT_ADC
uint16_t App_Bat_Volt()
{
    uint16_t Vref = ADC_Config_Read_Vref();
    return (float)ADC_Config_Read_CH17(Vref)/(float)BAT_ADC_R27*(float)(BAT_ADC_R26 + BAT_ADC_R27);
}



/**
* @brief  Inserts a delay time.
* @param  nCount: specifies the delay time length.
* @retval None
*/
void delay_ms(__IO uint16_t msCount)
{
    /* Decrement msCount value */
	__IO uint16_t nopCount;
	while(msCount)
	{
		nopCount = 1600;
        while (nopCount)
            nopCount--;
        msCount--;
	}
}