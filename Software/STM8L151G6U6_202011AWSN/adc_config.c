#include "adc_config.h"

void ADC_Config()
{
    GPIO_Init(GPIOA, GPIO_Pin_5, GPIO_Mode_In_FL_No_IT);
    GPIO_Init(GPIOB, GPIO_Pin_1, GPIO_Mode_In_FL_No_IT);

    /* Enable ADC1 clock */
    CLK_PeripheralClockConfig(CLK_Peripheral_ADC1, ENABLE);

    /* Initialize and configure ADC1 */
    ADC_Init(ADC1, ADC_ConversionMode_Continuous, ADC_Resolution_12Bit, ADC_Prescaler_2);

    /* Enable ADC1 */
    ADC_Cmd(ADC1, ENABLE);
}
// Power Voltage
uint16_t ADC_Config_Read_Vref()
{
    ADC_VrefintCmd(ENABLE);
    ADC_ChannelCmd(ADC1,ADC_Channel_Vrefint,ENABLE);

    /* Start ADC1 Conversion using Software trigger*/
    ADC_SoftwareStartConv(ADC1);

    /* Wait until End-Of-Convertion */
    while (!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));

    /* Get conversion value */
    uint16_t ADCData = ADC_GetConversionValue(ADC1);

    ADC_VrefintCmd(DISABLE);
    ADC_ChannelCmd(ADC1,ADC_Channel_Vrefint,DISABLE);

    return (uint16_t)(VREFINT*4096.0/(float)ADCData);
}

uint16_t ADC_Config_Read_CH1(uint16_t Vref)
{
    ADC_ChannelCmd(ADC1, ADC_Channel_1 , ENABLE);

    /* Start ADC1 Conversion using Software trigger*/
    ADC_SoftwareStartConv(ADC1);

    /* Wait until End-Of-Convertion */
    while (!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));

    /* Get conversion value */
    uint16_t ADCData = ADC_GetConversionValue(ADC1);

    ADC_ChannelCmd(ADC1,ADC_Channel_1,DISABLE);

    return (uint16_t)((float)ADCData/4096.0*(float)Vref);
}

uint16_t ADC_Config_Read_CH17(uint16_t Vref)
{
    ADC_ChannelCmd(ADC1, ADC_Channel_17, ENABLE);

    /* Start ADC1 Conversion using Software trigger*/
    ADC_SoftwareStartConv(ADC1);

    /* Wait until End-Of-Convertion */
    while (!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));

    /* Get conversion value */
    uint16_t ADCData = ADC_GetConversionValue(ADC1);

    ADC_ChannelCmd(ADC1,ADC_Channel_17, DISABLE);

    return (uint16_t)((float)ADCData/4096.0*(float)Vref);
}

