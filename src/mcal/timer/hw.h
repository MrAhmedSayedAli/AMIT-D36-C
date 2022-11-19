/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef AMIT_COURSE_HW_H
#define AMIT_COURSE_HW_H

#include "STD_Types.h"

//TIMER ZERO
#define TIMER0_TCCR0_REG   (* (volatile uint8 *) (0x53))
#define TIMER0_TCNT0_REG   (* (volatile uint8 *) (0x52))
#define TIMER0_OCR0_REG    (* (volatile uint8 *) (0x5C))
#define TIMER0_TIMSK_REG   (* (volatile uint8 *) (0x59))
#define TIMER0_TIFR_REG    (* (volatile uint8 *) (0x58))




#endif //AMIT_COURSE_HW_H
