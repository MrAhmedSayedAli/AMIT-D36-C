/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#include "hw.h"
#include "eeprom.h"
#include "BitMath.h"


void EEPROM_WriteData(uint16 address, uint8 data) {

    while(EEPROM_CR_REG & (1<<EEWE));

    EEPROM_ARL_REG=address;
    EEPROM_ARH_REG = address>>8;

    EEPROM_DR_REG = data;
    EEPROM_CR_REG |= (1<<EEMWE);
    EEPROM_CR_REG |= (1<<EEWE);
}

uint8 EEPROM_ReadData(uint16 address) {

    while(EEPROM_CR_REG & (1<<EEWE));

    EEPROM_ARL_REG	=address;
    EEPROM_ARH_REG = address>>8;
    EEPROM_CR_REG |= (1<<EERE);

    return EEPROM_DR_REG;
}


void EEPROM_WriteString(uint16 stringAddress, uint8 *stringData){
    do
    {
        EEPROM_WriteData(stringAddress,*stringData);
        stringData++;
        stringAddress++;
    }while(*(stringData-1) !=0);
}

void EEPROM_ReadString(uint16 stringAddress, int8 *stringData){

    int8 eeprom_data;
    do{
        eeprom_data = EEPROM_ReadData(stringAddress);
        *stringData = eeprom_data;
        stringData++;
        stringAddress++;
    }while(eeprom_data!=0);


}
