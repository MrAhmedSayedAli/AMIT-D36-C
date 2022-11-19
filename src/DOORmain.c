/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/
#include "stdio.h"
#include <stdlib.h>
#include <string.h>

#include "util/delay.h"

#include "dio/dio.h"


#include "lcd/lcd.h"
#include "keypad/keypad.h"

#include "eeprom/eeprom.h"


typedef enum {
    DOOR_LOGIN = 0,
    DOOR_CHANGE,
    DOOR_CHANGE_NEW,
    DOOR_NO_STATE
} DOOR_ACTION;


uint8 tempInput[10];
uint8 tempInputCount = 0;


void LCD_RESET_TITLE(int8 *string) {
    LCD_SET_POS(0, 0);
    LCD_INT8_STRING(string);
    LCD_SET_POS(2, 0);
}

void LCD_RESET_INPUT() {
    LCD_SET_POS(2, 0);
    LCD_STRING("                ");
    LCD_SET_POS(2, 0);
}

void LCD_RESET_ALL(int8 *string) {
    LCD_CMD(0x01);
    LCD_INT8_STRING(string);
    LCD_SET_POS(2, 0);
}

void LCD_FLASH_MESSAEG(uint8 *string) {
    LCD_RESET_ALL(string);
    _delay_ms(40);
    LCD_RESET_ALL("                ");
    LCD_RESET_ALL(string);
    _delay_ms(40);
    LCD_RESET_ALL("                ");
    LCD_RESET_ALL(string);
    _delay_ms(40);
    LCD_RESET_ALL("                ");
}

boolean CHECK_PASSWORD(int8 *input) {
    int8 passwordString[10];
    EEPROM_ReadString(0, passwordString);
    return strcmp(passwordString, input) == 0 ? TRUE : FALSE;
}


void FORCE_RESET() {
    LCD_RESET_ALL("ENTER PASSWORD : ");
    DIO_WriteChannel(DIO_ChannelA2, STD_LOW);
}


void inputPush(uint8 tChar) {
    tempInput[tempInputCount] = tChar;
    tempInputCount++;
}

void inputReset() {
    memset(tempInput, 0, 10);
    tempInputCount = 0;
}

int main() {

    DOOR_ACTION doorAction;
    doorAction = DOOR_LOGIN;
    dioInit();
    LCD_INIT();


    if(EEPROM_ReadData(0) == 255){
        EEPROM_WriteString(0,"1234");
    }

    uint8 keypadVr = 0;


    LCD_RESET_ALL("ENTER PASSWORD : ");

    while (1) {

        keypadVr = getKey();
        if (keypadVr != 0) {


            if (keypadVr >= '0' && keypadVr <= '9') {
                if (tempInputCount == 6) continue;
                inputPush(keypadVr);
                LCD_CHAR(keypadVr);

            } else {

                if (keypadVr == 'A') {

                    LCD_RESET_ALL("CHANGE (oldPass)");
                    doorAction = DOOR_CHANGE;

                } else if (keypadVr == 'B') {

                } else if (keypadVr == 'C') {

                    inputReset();
                    DIO_WriteChannel(DIO_ChannelA2, STD_LOW);
                    FORCE_RESET();


                } else if (keypadVr == 'D') {

                    switch (doorAction) {
                        case DOOR_LOGIN: {
                            if (CHECK_PASSWORD(tempInput) == TRUE) {
                                LCD_RESET_ALL("   DOOR  OPEN   ");
                                inputReset();
                                DIO_WriteChannel(DIO_ChannelA2, STD_HIGH);
                            } else {
                                LCD_FLASH_MESSAEG("WRONG PASSWORD :/ ");
                                _delay_ms(100);
                                LCD_RESET_ALL("ENTER PASSWORD : ");
                                inputReset();
                            }
                        }
                            break;
                        case DOOR_CHANGE: {

                            if (CHECK_PASSWORD(tempInput) == FALSE) {
                                LCD_FLASH_MESSAEG("WRONG PASSWORD :/ ");
                                inputReset();
                                FORCE_RESET();

                            }else {
                                LCD_RESET_ALL("CHANGE (newPass)");
                                LCD_RESET_INPUT();
                                inputReset();
                                doorAction = DOOR_CHANGE_NEW;
                            }
                        }
                            break;
                        case DOOR_CHANGE_NEW: {
                            EEPROM_WriteString(0, tempInput);
                            inputReset();
                            FORCE_RESET();
                            doorAction = DOOR_LOGIN;
                        }
                            break;
                    }


                } else if (keypadVr == '#') {
//FOR TEST ONLY
//                    LCD_RESET_INPUT();
//                    DIO_WriteChannel(DIO_ChannelA2, STD_LOW);
//
//
//                    if (CHECK_PASSWORD(tempInput) == TRUE) {
//                        DIO_WriteChannel(DIO_ChannelA2, STD_HIGH);
//                    } else {
//                        LCD_FLASH_MESSAEG("WRONG PASSWORD :/ ");
//                        _delay_ms(100);
//                        LCD_RESET_TITLE("ENTER PASSWORD : ");
//                    }


                } else {
                    LCD_CHAR(keypadVr);
                }

            }
            keypadVr = 0;
        }

        //DO_ACTION




    }
}