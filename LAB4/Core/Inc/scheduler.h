/*
 * scheduler.h
 *
 *  Created on: Nov 29, 2023
 *      Author: Administrator
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_
#include "stdint.h"
#include "main.h"


typedef struct {
// Pointer to the task (must be a ’ void ( void ) ’ function )
void ( * pTask) ( void ) ;
// Delay ( ti ck s ) until the function w ill ( next ) be run
uint32_t Delay ;
// Interval ( ti ck s ) between subsequent runs .
uint32_t Period ;
// Incremented ( by scheduler ) when task i s due to execute
uint8_t RunMe;
// This i s a hint to solve the question below .
uint32_t TaskID ;
} sTask;
// MUST BE ADJUSTED FOR EACH NEW PROJECT
#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0
#define TICKS				10
sTask SCH_tasks_G[SCH_MAX_TASKS];

void SCH_Init(void);
void SCH_Update(void);
unsigned char SCH_Add_Task(void (* pFunction)(), unsigned int DELAY, unsigned int PERIOD);
void SCH_Dispatch_Tasks(void);
#endif /* INC_SCHEDULER_H_ */
