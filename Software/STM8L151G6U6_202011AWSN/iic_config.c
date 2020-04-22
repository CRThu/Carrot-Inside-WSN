#include "iic_config.h"

void IIC_Config_Init()
{
    GPIO_Init(GPIOC, GPIO_Pin_0, GPIO_Mode_Out_OD_HiZ_Slow);    // SDA
    GPIO_Init(GPIOC, GPIO_Pin_1, GPIO_Mode_Out_OD_HiZ_Slow);    // SCL

    // prevent IIC SDA Locked (testing)
//    GPIO_WriteBit(GPIOC, GPIO_Pin_0, SET);      // SDA
//    GPIO_WriteBit(GPIOC, GPIO_Pin_1, SET);      // SCL
//    if(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_0) == RESET)  // SDA LOCKED
//    {
//        GPIO_WriteBit(GPIOC, GPIO_Pin_1, SET);    // SCL
//        for(int i=0;i<17;i++)
//        {
//            GPIO_WriteBit(GPIOC, GPIO_Pin_1, RESET);    // SCL
//            GPIO_WriteBit(GPIOC, GPIO_Pin_1, SET);      // SCL
//
//            if(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_0) != RESET)
//                break;
//        }
//    }

    CLK_PeripheralClockConfig(CLK_Peripheral_I2C1, ENABLE);     // CLOCK
    I2C_Init(I2C1, 100000, 0x00,                                // (0x00 unused)
           I2C_Mode_I2C, I2C_DutyCycle_2,
           I2C_Ack_Enable, I2C_AcknowledgedAddress_7bit);

    while(I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));
}

void IIC_Config_WriteByte(uint8_t iic_address, uint8_t memory_address, uint8_t data)
{
    while(I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));

    // START EV5(Sent)
    I2C_GenerateSTART(I2C1, ENABLE);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));

    // Send Address EV6(Sent, ACK)
    I2C_Send7bitAddress(I2C1, iic_address, I2C_Direction_Transmitter);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));

    // Send Data EV8(Sent)
    I2C_SendData(I2C1, memory_address);
    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));

    // Send Data EV8(Sent)
    I2C_SendData(I2C1, data);
    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
    I2C_AcknowledgeConfig(I2C1,ENABLE);

    // Stop
    I2C_GenerateSTOP(I2C1, ENABLE);
}

uint8_t IIC_Config_ReadByte(uint8_t iic_address, uint8_t addr)
{
    uint8_t i;

    while(I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));

    // START EV5(Sent)
    I2C_GenerateSTART(I2C1, ENABLE);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));

    // Send Address EV6(Sent, ACK)
    I2C_Send7bitAddress(I2C1, iic_address, I2C_Direction_Transmitter);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));

    // Send Data EV8(Sent)
    I2C_SendData(I2C1, addr);
    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));

    // START EV5(Sent)
    I2C_GenerateSTART(I2C1, ENABLE);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));

    // Send Address EV6(Sent, ACK)
    I2C_Send7bitAddress(I2C1, iic_address, I2C_Direction_Receiver);
    while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));

    // Recv Data
    while (!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_BYTE_RECEIVED));
    i=I2C_ReceiveData(I2C1);
    I2C_AcknowledgeConfig(I2C1,DISABLE);

    // Stop
    I2C_GenerateSTOP(I2C1, ENABLE);

    return i;
}


void IIC_Config_WriteWord(uint8_t iic_address, uint8_t memory_address, uint16_t data)
{

}

uint16_t IIC_Config_ReadWord(uint8_t iic_address, uint8_t addr)
{

}
