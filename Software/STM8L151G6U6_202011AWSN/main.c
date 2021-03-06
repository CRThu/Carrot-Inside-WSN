/**
******************************************************************************
* @file    Project/STM8L15x_StdPeriph_Template/main.c
* @author  MCD Application Team
* @version V1.6.1
* @date    30-September-2014
* @brief   Main program body
******************************************************************************
* @attention
*
* <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
*
* Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
* You may not use this file except in compliance with the License.
* You may obtain a copy of the License at:
*
*        http://www.st.com/software_license_agreement_liberty_v2
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "stm8l15x.h"
#include "app_func.h"


/** @addtogroup STM8L15x_StdPeriph_Template
* @{
*/

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/**
* @brief  Main program.
* @param  None
* @retval None
*/
void main(void)
{
    App_Sys_Init();
    App_OLED_Init();

    OLED_ShowString(0,0,"PUMP ON ",8);
    App_Pump_Control(1);
    delay_ms(250);
    App_Pump_Control(0);
    OLED_ShowString(0,0,"PUMP OFF",8);

    App_Bat_Control(1);

    /* Infinite loop */
    while (1)
    {
        OLED_ShowNum(0,1,ADC_Config_Read_Vref(),5,8);
        OLED_ShowNum(0,2,ADC_Config_Read_CH17(3327),5,8);
        OLED_ShowNum(0,3,App_Bat_Volt(),5,8);


        if(!GPIO_KEY1())
        {
            GPIO_LED1(1);
            GPIO_LED2(1);
        }
        else if(!GPIO_KEY2())
        {
            GPIO_LED1(0);
            GPIO_LED2(0);
        }
        else
        {
            GPIO_LED2(1);
            GPIO_LED1(0);
            delay_ms(200);
            GPIO_LED1(1);
            GPIO_LED2(0);
            delay_ms(200);
        }
    }
}

#ifdef  USE_FULL_ASSERT

/**
* @brief  Reports the name of the source file and the source line number
*   where the assert_param error has occurred.
* @param  file: pointer to the source file name
* @param  line: assert_param error line source number
* @retval None
*/
void assert_failed(uint8_t* file, uint32_t line)
{
    /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

    /* Infinite loop */
    while (1)
    {
    }
}
#endif

/**
* @}
*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
