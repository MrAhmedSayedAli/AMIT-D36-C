/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#include "timer.h"
#include "hw.h"
#include "BitMath.h"

void TIMER0_INIT(void) {
#if (TIMER_OPERATION_MODE == TIMER0_MODE_INTERVAL)
    TIMER0_TCCR0_REG|= TIMER0_INTERVAL_MODE;
#elif (TIMER_OPERATION_MODE == TIMER0_MODE_CTC)
    //TIMER0_TCCR0_REG |= TIMER0_CTC_MODE;
    // Select Mode = CTC Mode
    clearBit(TIMER0_TCCR0_REG,6);
    setBit(TIMER0_TCCR0_REG,3);

    // Enable CTC Interrupt
    setBit(TIMER0_TIMSK_REG,1);

    // Select Prescaler Value = 64
    setBit(TIMER0_TCCR0_REG,0);
    setBit(TIMER0_TCCR0_REG,1);
    clearBit(TIMER0_TCCR0_REG,2);

#elif (TIMER_OPERATION_MODE == TIMER0_MODE_FAST_PWM)
    TIMER0_TCCR0_REG|= TIMER0_PWM_FAST;
#elif (TIMER_OPERATION_MODE == TIMER0_MODE_PWM_PHASE_CORRECT)
    TIMER0_TCCR0_REG|= TIMER0_PWM_PHASE_CORRECT;
#else
#error "You Shall Define Timer Operation Mode In Timer0_Cfg.h"
#endif
}

//=====================================>
void TIMER0_SetCompareMatchValue(uint8 compareMatchValue){
    TIMER0_OCR0_REG = compareMatchValue;
}
//=====================================>
void TIMER0_StartTimer(uint8 prescaler) {
    TIMER0_TCCR0_REG |= prescaler;
}

//------------------------------------->
void TIMER0_StopTimer(void) {
    TIMER0_TCCR0_REG &= 0xF8; // 1111 1000
}

//=====================================>
void TIMER0_SetPreLoad(uint8 value) {
    TIMER0_TCNT0_REG = value;
}

//------------------------------------->
uint8 TIMER0_GetPreload(void) {
    return TIMER0_TCNT0_REG;
}

//=====================================>
void TIMER0_EnableInterrupt(void) {
#if (TIMER_OPERATION_MODE == TIMER0_MODE_INTERVAL)
    setBit(TIMER0_TIMSK_REG,TIMER0_INTERVAL_INT_ENABLE_BIT_NO);
#elif (TIMER_OPERATION_MODE == TIMER0_MODE_CTC)
    setBit(TIMER0_TIMSK_REG, TIMER0_CTC_INT_ENABLE_BIT_NO);
#endif
}

//------------------------------------->
void TIMER0_DisableInterrupt(void) {
#if (TIMER_OPERATION_MODE == TIMER0_MODE_INTERVAL)
    clearBit(TIMER0_TIMSK_REG,TIMER0_INTERVAL_INT_ENABLE_BIT_NO);
#elif (TIMER_OPERATION_MODE == TIMER0_MODE_CTC)
    clearBit(TIMER0_TIMSK_REG, TIMER0_CTC_INT_ENABLE_BIT_NO);
#endif
}

//------------------------------------->
void TIMER0_PWM(uint8 freq, uint8 dutyCycle) {
    uint16 result = 0;
    result = (dutyCycle * TIMER0_TOP) / 100;
    TIMER0_OCR0_REG = result;
}