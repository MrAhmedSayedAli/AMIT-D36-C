/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/
#include "keypad.h"

uint8 KeyPadRow[4] = {r0,r1,r2,r3};
uint8 KeyPadCol[4] = {c0,c1,c2,c3};
uint8 KeyPad[4][4] = {{'1','2','3','A'},
                      {'4','5','6','B'},
                      {'7','8','9','C'},
                      {'*','0','#','D'}};

uint8 getKey(void){
    for (uint8 w=0;w<4;w++){
        DIO_WriteChannel(KeyPadRow[w],STD_HIGH);//output 5v
        DIO_WriteChannel(KeyPadCol[w],STD_HIGH);//Pull up Res.
    }
    for (uint8 i=0;i<4;i++)
    {
        DIO_WriteChannel(KeyPadRow[i],STD_LOW);
        for (uint8 j=0;j<4;j++)
        {
            if (DIO_ReadChannel(KeyPadCol[j]) == STD_LOW)
            {
                while(DIO_ReadChannel(KeyPadCol[j]) == STD_LOW);
                return KeyPad[i][j];
            }
        }
        DIO_WriteChannel(KeyPadRow[i],STD_HIGH);
    }
    return STD_LOW;
}