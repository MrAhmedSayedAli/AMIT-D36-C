/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef AMIT_COURSE_I2C_H
#define AMIT_COURSE_I2C_H

#include "STD_Types.h"

void I2C_Master_Init(void);
void I2C_Slave_Init(uint8 address);

boolean I2C_StartCondition(void);
boolean I2C_RepeatedStartCondition(void);
void I2C_StopCondition(void);

boolean I2C_SlaveAddressWrite(uint8 address);
boolean I2C_SlaveAddressRead(uint8 address);

boolean I2C_WriteByte(uint8 byte);
boolean I2C_ReadByte(uint8 *byte);

uint8 I2C_GetStatus(void);


#endif //AMIT_COURSE_I2C_H
