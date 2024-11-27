/*
 * scheduler.h
 *
 *  Created on: Nov 26, 2024
 *      Author: ADMIN
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_
#include <stdint.h>
typedef struct {
 // Pointer to the task (must be a ’ void ( void ) ’ function )
 void ( * pTask ) ( void ) ;
 // Delay ( ti c k s ) un til the function will ( next ) be run
 uint32_t Delay ;
 // In t e r v al ( ti c k s ) between subsequent runs .
 uint32_t Period ;
 // Incremented (by scheduler) when task i s due to execute
 uint8_t RunMe;
 //This i s a hin t to solve the question below .
 uint32_t TaskID ;
 } sTask ;

 // MUST BE ADJUSTED FOR EACH NEW PROJECT
#define SCH_MAX_TASKS 40
 void SCH_Init ( void );
// unsigned char SCH_Add_Task ( void ( * pFunction ) ( ) , unsigned int DELAY, unsigned int PERIOD);
// void SCH_Update ( void );
// void SCH_Dispatch_Tasks ( void );
// void SCH_Delete_Task(uint32_t TASK_INDEX);

 uint8_t SCH_Add_Task(void (*pFunction)(void), uint32_t DELAY, uint32_t PERIOD);
 void SCH_Delete_Task(uint8_t TASK_INDEX);
 void SCH_Update(void);
 void SCH_Dispatch_Tasks(void);
#endif /* INC_SCHEDULER_H_ */
