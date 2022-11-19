/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef AMIT_COURSE_DHT22_H
#define AMIT_COURSE_DHT22_H

#include "STD_Types.h"
#include "dio/dio.h"

#define DHT_ReadInterval			1500
#define __DHT_Delay_Setup			2000

enum DHT_Status_t
{
    DHT_Ok,
    DHT_Error_Humidity,
    DHT_Error_Temperature,
    DHT_Error_Checksum,
    DHT_Error_Timeout
};


void DHT_Setup();
enum DHT_Status_t DHT_GetStatus();

enum DHT_Status_t DHT_Read(DIO_ChannelTypes ChannelId,double *Temperature, double *Humidity);
enum DHT_Status_t DHT_ReadRaw(DIO_ChannelTypes ChannelId,uint8 Data[4]);

enum DHT_Status_t DHT_GetTemperature(double *Temperature);
enum DHT_Status_t DHT_GetHumidity(double *Humidity);
double DHT_CelsiusToFahrenheit(double Temperature);
double DHT_CelsiusToKelvin(double Temperature);


#endif //AMIT_COURSE_DHT22_H
