/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef AMIT_COURSE_EEPROM_H
#define AMIT_COURSE_EEPROM_H
#include "STD_Types.h"


void EEPROM_WriteData(uint16 address, uint8 data);
uint8 EEPROM_ReadData(uint16 address);

void EEPROM_WriteString(uint16 stringAddress, uint8 *stringData);
void EEPROM_ReadString(uint16 stringAddress, int8 *stringData);


#endif //AMIT_COURSE_EEPROM_H
