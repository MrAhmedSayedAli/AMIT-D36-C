/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef AMIT_COURSE_HW_H
#define AMIT_COURSE_HW_H




#define EEPROM_ARH_REG				(*(volatile uint8*)0x3F)
#define EEPROM_ARL_REG				(*(volatile uint8*)0x3E)
#define EEPROM_DR_REG				(*(volatile uint8*)0x3D)
#define EEPROM_CR_REG				(*(volatile uint8*)0x3C)

#define EERE				(0u)
#define EEWE             	(1u)
#define EEMWE				(2u)


#endif //AMIT_COURSE_HW_H
