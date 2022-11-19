/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#include "spi.h"

void SPI_Init(SPI_OperationTypes state){
    switch(state){
        case Master:
            DIO_WriteDirection(SPI_SS,OUTPUT);//SS,MOSI,SCK -> OUTPUT & MISO -> INPUT
            DIO_WriteDirection(SPI_MOSI,OUTPUT);
            DIO_WriteDirection(SPI_SCK,OUTPUT);
            DIO_WriteDirection(SPI_MISO,OUTPUT);
            //SetBit(SPI_SPCR_Reg,SPI_MSTR_Bit);
            //SPI->MySPCR.MSTR_Bit = 1;
            //SPI->MySPCR.Bits.MSTR_Bit=1;


            //SetBit(SPI_SPCR_Reg,SPI_SPE_Bit);
            //SPI->MySPCR.SPE_Bit = 1;
            //SPI->MySPCR.Bits.SPE_Bit=1;
            SPI->MySPCR.AllRegister = 0b01010000;
            break;
        case Slave:
            DIO_WriteDirection(SPI_SS,INPUT);//SS,MOSI,SCK -> INPUT & MISO -> OUTPUT
            DIO_WriteDirection(SPI_MOSI,INPUT);
            DIO_WriteDirection(SPI_SCK,INPUT);
            DIO_WriteDirection(SPI_MISO,INPUT);
            setBit(SPI_SPCR_Reg,SPI_SPE_Bit);
            break;
    }
}
int8 SPI_TxRx(int8 data){
    //SPI_SPDR_Reg = data;
    SPI->MySPDR = data;
    while(getBit(SPI_SPSR_Reg,SPI_SPIF_Bit) == STD_LOW);
    return SPI_SPDR_Reg;
}
void SPI_Slave_Enable(void){
    DIO_WriteChannel(SPI_SS,STD_LOW);
}
void SPI_Slave_Disable(void){
    DIO_WriteChannel(SPI_SS,STD_HIGH);
}

//char SPI_Read()				/* SPI read data function */
//{
//    SPDR = 0xFF;
//    while(!(SPSR & (1<<SPIF)));	/* Wait till reception complete */
//    return(SPDR);			/* Return received data */
//}