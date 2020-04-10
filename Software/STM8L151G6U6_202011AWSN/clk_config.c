#include "clk_config.h"

/**
* @brief  Configure System Clock
* @param  None
* @retval None
*/
void CLK_Config_HSE(void)
{
    /* Select HSE as system clock source */
    CLK_SYSCLKSourceSwitchCmd(ENABLE);
    CLK_SYSCLKSourceConfig(CLK_SYSCLKSource_HSE);
    /* system clock prescaler: SYSCLK_DIV */
    CLK_SYSCLKDivConfig(SYSCLK_DIV);
    while (CLK_GetSYSCLKSource() != CLK_SYSCLKSource_HSE)
    {}
}

void CLK_Config_HSI(void)
{
    /* Select HSI as system clock source */
    CLK_SYSCLKSourceSwitchCmd(ENABLE);
    CLK_SYSCLKSourceConfig(CLK_SYSCLKSource_HSI);
    /* system clock prescaler: SYSCLK_DIV */
    CLK_SYSCLKDivConfig(SYSCLK_DIV);
    while (CLK_GetSYSCLKSource() != CLK_SYSCLKSource_HSI)
    {}
}

void CLK_Config_LSE(void)
{
    /* Select LSE as system clock source */
    CLK_SYSCLKSourceSwitchCmd(ENABLE);
    CLK_SYSCLKSourceConfig(CLK_SYSCLKSource_LSE);
    /* system clock prescaler: SYSCLK_DIV */
    CLK_SYSCLKDivConfig(SYSCLK_DIV);
    while (CLK_GetSYSCLKSource() != CLK_SYSCLKSource_LSE)
    {}
}

void CLK_Config_LSI(void)
{
    /* Select LSI as system clock source */
    CLK_SYSCLKSourceSwitchCmd(ENABLE);
    CLK_SYSCLKSourceConfig(CLK_SYSCLKSource_LSI);
    /* system clock prescaler: SYSCLK_DIV */
    CLK_SYSCLKDivConfig(SYSCLK_DIV);
    while (CLK_GetSYSCLKSource() != CLK_SYSCLKSource_LSI)
    {}
}
