/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/


#include "dio/dio.h"
#include "led/led.h"

#include "FREERTOS/FreeRTOS.h"
#include "FREERTOS//task.h"

void LED_0();
void LED_1();

_Noreturn void LED_2();

int main(){

    DIO_WriteDirection(DIO_ChannelC2,OUTPUT);
    DIO_WriteDirection(DIO_ChannelC7,OUTPUT);
    DIO_WriteDirection(DIO_ChannelD3,OUTPUT);

    LED_ON(DIO_ChannelC2);
    LED_ON(DIO_ChannelC7);
    LED_ON(DIO_ChannelD3);

    xTaskCreate(&LED_0,NULL,100,NULL,1,NULL);
    xTaskCreate(&LED_1,NULL,100,NULL,2,NULL);
    xTaskCreate(&LED_2,NULL,100,NULL,3,NULL);



    vTaskStartScheduler();

    while(1){

    }
}


void LED_0(void){
    while(1) {
        LED_TOGGLE(DIO_ChannelC2);
        vTaskDelay(1000);
    }
}


void LED_1(void){
    while(1) {
        LED_TOGGLE(DIO_ChannelC7);
        vTaskDelay(1000);
    }
}

void LED_2(void){
    while(1) {
        LED_TOGGLE(DIO_ChannelD3);
        vTaskDelay(1000);
    }
}


