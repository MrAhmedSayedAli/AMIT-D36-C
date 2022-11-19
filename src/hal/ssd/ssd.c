/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#include "ssd.h"

#include "util/delay.h"

void SSD_WriteNum(uint8 FirstDigit,uint8 SecondDigit){
    uint8 PortValue = 0;
    for (uint8 w=0;w<200;w++)
    {
        PortValue = DIO_ReadPort(SSD_DataPort);
        PortValue = (PortValue & 0x0F) | (FirstDigit<<4);
        DIO_WritePort(SSD_DataPort,PortValue);
        DIO_WriteChannel(SSD_FristDigit_En,STD_HIGH);
        _delay_us(100);
        DIO_WriteChannel(SSD_FristDigit_En,STD_LOW);

        PortValue = DIO_ReadPort(SSD_DataPort);
        PortValue = (PortValue & 0x0F) | (SecondDigit<<4);
        DIO_WritePort(SSD_DataPort,PortValue);
        DIO_WriteChannel(SSD_SecondDigit_En,STD_HIGH);
        _delay_us(100);
        DIO_WriteChannel(SSD_SecondDigit_En,STD_LOW);
    }
}
