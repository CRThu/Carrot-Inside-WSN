#ifndef __IIC_CONFIG_H__
#define __IIC_CONFIG_H__

#include "stm8l15x.h"

void IIC_Config_Init();
void IIC_Config_WriteByte(uint8_t iic_address, uint8_t memory_address, uint8_t data);
uint8_t IIC_Config_ReadByte(uint8_t iic_address, uint8_t addr);

void IIC_Config_WriteWord(uint8_t iic_address, uint8_t memory_address, uint16_t data);
uint16_t IIC_Config_ReadWord(uint8_t iic_address, uint8_t addr);

#endif
