/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef AMIT_COURSE_LM35_H
#define AMIT_COURSE_LM35_H

#include "adc/adc.h"


void LM35_Init();
int16 LM35_Read(ADC_ChannelTypes ChannelId);

#endif //AMIT_COURSE_LM35_H
