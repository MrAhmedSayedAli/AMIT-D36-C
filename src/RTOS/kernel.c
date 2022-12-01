/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/


/* UTILES_LIB */
#include "BitMath.h"


/* MCAL */
#include "interrupt/general/gint.h"
#include "timer/timer.h"

/* RTOS STACK */
#include "kernel.h"

//=====================================================================>
Task_t TaskArr[RTOS_TASK_NUM];

//=====================================================================>
void RTOS_start(void) {
    Enable_GINT_AllInterrupts();
    TIMER0_SetCompareMatchValue(249);
    TIMER0_INIT();
}

//=====================================================================>
void RTOS_createTask(uint8 priority, uint16 periodicity, void(*pTaskFunc)(void)) {
    if ((priority < RTOS_TASK_NUM) && (pTaskFunc != NULL) && (TaskArr[priority].pTaskCode == NULL)) {
        TaskArr[priority].taskPeriodicity = periodicity;
        TaskArr[priority].pTaskCode = pTaskFunc;
        TaskArr[priority].taskState = RTOS_TASK_RESUMED;
    } else {
        //Do Nothing
    }
}

//=====================================================================>
void RTOS_suspendTask(uint8 priority) {
    if (priority < RTOS_TASK_NUM)
        TaskArr[priority].taskState = RTOS_TASK_SUSPENDED;
}

//=====================================================================>
void RTOS_resumeTask(uint8 priority) {
    if (priority < RTOS_TASK_NUM)
        TaskArr[priority].taskState = RTOS_TASK_RESUMED;
}

//=====================================================================>
void RTOS_deleteTask(uint8 priority) {
    if (priority < RTOS_TASK_NUM)
        TaskArr[priority].pTaskCode = 0;
}

//=====================================================================>
void RTOS_scheduler(void) {
    static uint16 tickCounter = 0;
    tickCounter++;

    uint8 taskCounter;
    for (taskCounter = 0; taskCounter < RTOS_TASK_NUM; taskCounter++) {
        if (TaskArr[taskCounter].taskState == RTOS_TASK_RESUMED) {
            if (tickCounter % (TaskArr[taskCounter].taskPeriodicity) == 0) {
                if (TaskArr[taskCounter].pTaskCode != NULL) {
                    TaskArr[taskCounter].pTaskCode();
                }
            }
        }
    }
}
//=====================================================================>
//=====================================================================>
//=====================================================================>