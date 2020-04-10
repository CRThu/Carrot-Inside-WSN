#ifndef __APP_FUNC_H__
#define __APP_FUNC_H__

#include "stm8l15x.h"

#include "clk_config.h"
#include "gpio_config.h"
#include "iic_config.h"
#include "adc_config.h"
#include "oled.h"


// DEFINE PARA
// USE 3K3 AND 30K FOR SHORT AND OPEN
#define SOIL_CHX_D3V3_mV      3500
#define SOIL_CHX_0R_CHX_mV    1120
#define SOIL_CHX_3K3_CHX_mV   1000
#define SOIL_CHX_5K_CHX_mV    960
#define SOIL_CHX_8K3_CHX_mV   880
#define SOIL_CHX_10K_CHX_mV   850
#define SOIL_CHX_13K3_CHX_mV  780
#define SOIL_CHX_15K_CHX_mV   760
#define SOIL_CHX_20K_CHX_mV   700
#define SOIL_CHX_30K_CHX_mV   580
#define SOIL_CHX_40K_CHX_mV   500
#define SOIL_CHX_50K_CHX_mV   450
// FIT
#define Soil_R(x) (0.0001*(float)x*(float)x - 0.2243*(float)x + 128.83)*1000.0

// App Init
void App_Sys_Init();
void App_OLED_Init();
// Power
uint16_t App_ADC_Read_D3V3();
// Soil
#define APP_Soil_4051_Control(x)    GPIO_ADC_CTL(x)
uint16_t App_ADC_Read_Soil_CH0();
uint16_t App_ADC_Read_Soil_CH1();
uint16_t App_ADC_Read_Soil_CH2();
uint16_t App_ADC_Read_Soil_CH3();
int8_t App_Soil_Humi(uint16_t adc);
// Pump
#define APP_Pump_Control(x)         GPIO_PUMP_CTL(x)
// Delay
void delay_ms(__IO uint16_t msCount);

#endif