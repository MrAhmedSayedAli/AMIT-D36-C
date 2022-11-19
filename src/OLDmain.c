
#include <stdio.h>
//#include <stdlib.h>
//#include "string.h"

#include "util/delay.h"
//#include "avr/interrupt.h"

#include "dio/dio.h"


#include "lcd/lcd.h"
#include "keypad/keypad.h"

/*
#include "spi/spi.h"
#include "interrupt/external/eint.h"
#include "adc/adc.h"


#include "dht22/dht22.h"
#include "lm35/lm35.h"
#include "led/led.h"
#include "ssd/ssd.h"
#include "bluetooth/bluetooth.h"
*/
#include "io.h"
//#include "STD_Types.h"


//uint8 customChar[] = {
//        0x00, 0x00, 0x0C, 0x12, 0x01, 0x3E, 0x00, 0x1C
//};

//uint8 counter = 0;



int main(void) {

//    PinMode(C2,OUTPUT);
//    PinMode(C7,OUTPUT);
//    PinMode(D3,OUTPUT);
//
//    PinMode(A0,OUTPUT);
//    PinMode(A1,OUTPUT);
//    PinMode(A2,OUTPUT);
//    PinMode(A3,OUTPUT);
//    PinMode(A4,OUTPUT);
//    PinMode(A5,OUTPUT);
//    PinMode(A6,OUTPUT);
//    PinMode(A7,OUTPUT);
//
//    PinMode(B1,OUTPUT);
//    PinMode(B2,OUTPUT);
//
//
//    DigitalWrite(C2,HIGH);
//    DigitalWrite(C7,LOW);
//    DigitalWrite(D3,HIGH);

//    double temperature[1];
//    double humidity[1];
//
//    DHT_Setup();
//
//    sei();
    dioInit();
//    SPI_Init(Slave);
//
//
//
//    DIO_ChannelTypes Led1 = DIO_ChannelC2;
//    DIO_ChannelTypes Led2 = DIO_ChannelC7;
//    DIO_ChannelTypes Led3 = DIO_ChannelD3;
//    DIO_ChannelTypes Buzzer = DIO_ChannelA3;
//
//    ADC_Init();
//    LCD_INIT();
//    Bluetooth_Init();
//
//    Ext_INT_Enable(Ext_INT0);
//    Ext_INT_Sncontrol(Ext_INT0,Rising_Edge);

//    LCD_CUSTOM_CHAR(0,customChar);
//    LCD_SET_POS(1,0);

//    LCD_SET_POS(1,1);
//    LCD_STRING("AHMED  ELSAYED");

    //LCD_SET_POS(2,4);
    //LCD_STRING("AMIT");

//    int8 temp = 0;
//    int16 spiTmp = 0;

//    SSD_WriteNum(5,5);

//    uint8 counter = 0;

    uint8 keypadVr = 0;

    while (1) {

        keypadVr = getKey();
        if (keypadVr != 0) {
            LCD_CHAR(keypadVr);
            keypadVr = 0;
        }


//        if(counter == 99) counter = 0;
//        SSD_WriteNum(((counter/10)%10),(counter % 10));
//        SSD_WriteNum(5,7);

//        counter++;
//        DigitalLevelToggle(C2);
//        DigitalLevelToggle(C7);
//        DigitalLevelToggle(D3);
//        _delay_ms(100);

        //LCD_CMD(0x01);
//        int8 spiData = SPI_TxRx(0xFF);
//
//        int8 tMString[20] = "Temperature : ";
//        int8 spiString[20];
//        sprintf(spiString, "%d   ", spiData);
//
//        strcat(tMString, spiString);
//        LCD_SET_POS(1,0);
//        LCD_STRING(tMString);

/*
            DHT_Read(DIO_ChannelA0,temperature, humidity);

            int8 tMString[20] = "Temperature: ";
            int8 tString[20];

            int8 hMString[20] = "Humidity: ";
            int8 hString[20];

            switch (DHT_GetStatus()){

                case DHT_Ok:

                    itoa(temperature[0],tString,10);
                    strcat(tMString, tString);
                    LCD_SET_POS(1,0);
                    LCD_STRING(tMString);

                    itoa(humidity[0],hString,10);
                    strcat(hMString, hString);
                    LCD_SET_POS(2,0);
                    LCD_STRING(hMString);

                    break;
                case DHT_Error_Humidity:
                    //LCD_STRING("DHT_Error_Humidity");
                    break;
                case DHT_Error_Temperature:
                    //LCD_STRING("DHT_Error_Temperature");
                    break;
                case DHT_Error_Checksum:
                   //LCD_STRING("DHT_Error_Checksum");
                    break;
                case DHT_Error_Timeout:
                    //LCD_STRING("DHT_Error_Timeout");
                    break;
            }
*/

//        {
//            int8 Main_String[20] = "TEMP : ";
//            int8 temp_String[20];
//            temp = LM35_Read(ADC_Channel1);
//            itoa(temp,temp_String,10);
//
//            strcat(Main_String, temp_String);
//
//            LCD_SET_POS(2,0);
//            LCD_STRING(Main_String);
//            //LCD_CMD(0x01);
//            Bluetooth_TransmitString(Main_String);
//        }

//        {
//            if(Bluetooth_Receive() == '1'){
//                LED_TOGGLE(DIO_ChannelC7);
//                Bluetooth_TransmitString("Done Toggle");
//            }
//        }

//        LED_TOGGLE(Led1);
        //LED_OFF(Led2);
//        LED_OFF(Led3);

//        _delay_ms(100);


        //LED_OFF(Led1);
        //LED_ON(Led2);
        //LED_OFF(Led3);
        //_delay_ms(20);


//        LED_OFF(Led1);
        //LED_OFF(Led2);
//        LED_ON(Led3);
//        _delay_ms(100);

        //LCD_CMD(0x01);
    }

}


//ISR(INT0_vect){
//    counter++;
//    LED_TOGGLE(DIO_ChannelC7);
//}
