/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef AMIT_COURSE_SPI_H
#define AMIT_COURSE_SPI_H

#include "hw.h"
#include "types.h"
#include "dio/dio.h"

#define SPI_SS DIO_ChannelB4
#define SPI_MOSI DIO_ChannelB5
#define SPI_MISO DIO_ChannelB6
#define SPI_SCK DIO_ChannelB7

#define SPI_SPE_Bit 6
#define SPI_MSTR_Bit 4
#define SPI_SPIF_Bit 7

void SPI_Init(SPI_OperationTypes state);
int8 SPI_TxRx(int8 data);
void SPI_Slave_Enable(void);
void SPI_Slave_Disable(void);
#endif //AMIT_COURSE_SPI_H
