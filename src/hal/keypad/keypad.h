/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef AMIT_COURSE_KEYPAD_H
#define AMIT_COURSE_KEYPAD_H

#include "dio/dio.h"

#define r0 DIO_ChannelC3
#define r1 DIO_ChannelC4
#define r2 DIO_ChannelC5
#define r3 DIO_ChannelC6

#define c0 DIO_ChannelB4
#define c1 DIO_ChannelB5
#define c2 DIO_ChannelB6
#define c3 DIO_ChannelB7


uint8 getKey(void);

#endif //AMIT_COURSE_KEYPAD_H
