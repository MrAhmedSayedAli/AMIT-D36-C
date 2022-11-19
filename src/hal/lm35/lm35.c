/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#include "lm35.h"

void LM35_Init(void){
    ADC_Init();
}
int16 LM35_Read(ADC_ChannelTypes ChannelId){
    int16 temp = 0;
    temp = (ADC_Read(ChannelId))/4;
    return temp;
}