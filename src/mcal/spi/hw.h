/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef AMIT_COURSE_HW_H
#define AMIT_COURSE_HW_H
#include "STD_Types.h"

#define SPI_SPCR_Reg (*(volatile uint8 *)0x2D)
#define SPI_SPSR_Reg (*(volatile uint8 *)0x2E)
#define SPI_SPDR_Reg (*(volatile uint8 *)0x2F)

#define SPI ((volatile SPI_Registers *)0x2D)
#endif //AMIT_COURSE_HW_H
