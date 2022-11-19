/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef AMIT_COURSE_EEPROM24C16_H
#define AMIT_COURSE_EEPROM24C16_H

#include "STD_Types.h"

void EEPROM24C16_Init(void);
void EEPROM24C16_Write(uint16 address,uint8 Data);
uint8 EEPROM24C16_Read(uint16 address);


#endif //AMIT_COURSE_EEPROM24C16_H
