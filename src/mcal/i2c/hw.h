/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef AMIT_COURSE_HW_H
#define AMIT_COURSE_HW_H

#include "STD_Types.h"

#define TWI_TWBR_REG (*(volatile uint8 *)0x20)
#define TWI_TWCR_REG (*(volatile uint8 *)0x56)
#define TWI_TWSR_REG (*(volatile uint8 *)0x21)
#define TWI_TWDR_REG (*(volatile uint8 *)0x23)
#define TWI_TWAR_REG (*(volatile uint8 *)0x22)

#endif //AMIT_COURSE_HW_H
