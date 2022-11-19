/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#include "hw.h"
#include "BitMath.h"
#include "i2c.h"


void I2C_Master_Init(void) {

    TWI_TWBR_REG = 12;    //I2C Speed = 40000khz

    clearBit(TWI_TWSR_REG, 0);
    clearBit(TWI_TWSR_REG, 1);

    setBit(TWI_TWCR_REG, 6);//Enable ACK
    setBit(TWI_TWCR_REG, 2);//Enable I2c

}

void I2C_Slave_Init(uint8 address) {
    /*	set slave address	*/
    TWI_TWAR_REG = address << 1;

    setBit(TWI_TWCR_REG, 6);//Enable ACK
    setBit(TWI_TWCR_REG, 2);//Enable I2C
}

boolean I2C_StartCondition(void) {


    setBit(TWI_TWCR_REG, 5);
    setBit(TWI_TWCR_REG, 7);

    while (getBit(TWI_TWCR_REG, 7) == 0); //TODO::BREAK
    return (I2C_GetStatus() == 0x08) ? TRUE : FALSE;

}

boolean I2C_RepeatedStartCondition(void) {

    setBit(TWI_TWCR_REG, 5);//Set Start
    setBit(TWI_TWCR_REG, 7);//Clear Flag

    while (getBit(TWI_TWCR_REG, 7) == 0); //TODO::BREAK
    return (I2C_GetStatus() == 0x10) ? TRUE : FALSE;
}

void I2C_StopCondition(void) {

    setBit(TWI_TWCR_REG, 4);//Stop bit
    setBit(TWI_TWCR_REG, 7);//ClearFlag

    while (getBit(TWI_TWCR_REG, 7) == 0); //TODO::BREAK
}

boolean I2C_SlaveAddressWrite(uint8 address) {

    TWI_TWDR_REG = (address << 1);//Set Slave Address

    clearBit(TWI_TWCR_REG, 5);//Clear Start bit
    setBit(TWI_TWCR_REG, 7);//Clear Flag

    while (getBit(TWI_TWCR_REG, 7) == 0); //TODO::BREAK
    return (I2C_GetStatus() == 0x18) ? TRUE : FALSE;
}

boolean I2C_SlaveAddressRead(uint8 address) {

    TWI_TWDR_REG = (address << 1);//Set Slave Addr

    setBit(TWI_TWDR_REG, 0);//SET R/W Bit To Read From Slave

    clearBit(TWI_TWCR_REG, 5);//Clear Start bit
    setBit(TWI_TWCR_REG, 7);//Clear Flag

    while (getBit(TWI_TWCR_REG, 7) == 0); //TODO::BREAK
    return (I2C_GetStatus() == 0x40) ? TRUE : FALSE;
}

boolean I2C_WriteByte(uint8 byte) {

    TWI_TWDR_REG = byte;
    clearBit(TWI_TWCR_REG, 5);
    setBit(TWI_TWCR_REG, 7);   /* to clear the flag */

    while (getBit(TWI_TWCR_REG, 7) == 0); //TODO::BREAK
    return (I2C_GetStatus() == 0x28) ? TRUE : FALSE;
}

boolean I2C_ReadByte(uint8 *byte) {

    clearBit(TWI_TWCR_REG, 5);
    setBit(TWI_TWCR_REG, 7);   /* to clear the flag */

    *byte = TWI_TWDR_REG;

    while (getBit(TWI_TWCR_REG, 7) == 0); //TODO::BREAK
    return (I2C_GetStatus() == 0x50) ? TRUE : FALSE;
}

uint8 I2C_GetStatus(void) {
    return (TWI_TWSR_REG & 0xF8);
}