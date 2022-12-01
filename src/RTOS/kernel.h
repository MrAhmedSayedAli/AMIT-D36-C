/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef AMIT_COURSE_KERNEL_H
#define AMIT_COURSE_KERNEL_H

#include "STD_Types.h"

#define RTOS_TASK_NUM          3
#define RTOS_TASK_SUSPENDED           1
#define RTOS_TASK_RESUMED             2

typedef struct
{
    uint16 taskPeriodicity;
    void (*pTaskCode)(void);
    uint16 taskState;
}Task_t;


void RTOS_start      (void);
void RTOS_createTask (uint8 priority, uint16 periodicity, void(*pTaskFunc)(void));
void RTOS_suspendTask(uint8 priority);
void RTOS_resumeTask (uint8 priority);
void RTOS_deleteTask (uint8 priority);
void RTOS_scheduler  (void);


#endif //AMIT_COURSE_KERNEL_H
