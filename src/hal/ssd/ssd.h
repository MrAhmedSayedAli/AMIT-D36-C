/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef AMIT_COURSE_SSD_H
#define AMIT_COURSE_SSD_H

#include "dio/dio.h"

#define SSD_DataPort DIO_PortA

#define SSD_FristDigit_En DIO_ChannelB2
#define SSD_SecondDigit_En DIO_ChannelB1

void SSD_WriteNum(uint8 FirstDigit,uint8 SecondDigit);


#endif //AMIT_COURSE_SSD_H
