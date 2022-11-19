/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef AMIT_COURSE_TYPES_H
#define AMIT_COURSE_TYPES_H

#include "STD_Types.h"

typedef struct{
    uint8 SPR_Bit:2;
    uint8 CPHA_Bit:1;
    uint8 CPOL_Bit:1;
    uint8 MSTR_Bit:1;
    uint8 DORD_Bit:1;
    uint8 SPE_Bit:1;
    uint8 SPIE_Bit:1;
}SPI_SPCRBits;

typedef union{
    uint8 AllRegister;
    SPI_SPCRBits Bits;
}SPI_SPCRCFG;

typedef struct{
    SPI_SPCRCFG MySPCR;
    uint8 MySPSR;
    uint8 MySPDR;
}SPI_Registers;

typedef enum{
    Slave=0,
    Master
}SPI_OperationTypes;
#endif //AMIT_COURSE_TYPES_H
