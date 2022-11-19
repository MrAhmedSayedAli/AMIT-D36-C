/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#include "util/delay.h"
#include "i2c/i2c.h"
#include "eeprom24C16.h"



void EEPROM24C16_Init(void){
    I2C_Master_Init();
}

void EEPROM24C16_Write(uint16 address,uint8 Data){
    uint8 Loc_PageNO = address / 256;
    uint8 Loc_ByteNO = address % 256;

    I2C_StartCondition();
    I2C_SlaveAddressWrite(0x50 | Loc_PageNO);
    I2C_WriteByte(Loc_ByteNO);
    I2C_WriteByte(Data);
    I2C_StopCondition();

    _delay_ms(10);
}

uint8 EEPROM24C16_Read(uint16 address){

    uint8 Loc_Data = 0;
    uint8 Loc_PageNO = address / 256;
    uint8 Loc_ByteNO = address % 256;

    I2C_StartCondition();
    I2C_SlaveAddressWrite(0x50 | Loc_PageNO);
    I2C_WriteByte(Loc_ByteNO);
    I2C_RepeatedStartCondition();
    I2C_SlaveAddressRead(0x50 | Loc_PageNO);
    I2C_ReadByte(&Loc_Data);
    I2C_StopCondition();
    return Loc_Data;

}
