/*
 * scheduler.c
 *
 *  Created on: Nov 26, 2024
 *      Author: ADMIN
 */

#include "scheduler.h"
sTask SCH_tasks_G [SCH_MAX_TASKS ] ;
uint8_t SCH_task_head = 0;
uint8_t SCH_task_tail = 0;
//void SCH_Init ( void ) {
//// unsigned char i ;
//// for ( i = 0; i < SCH_MAX_TASKS; i ++) {
////   SCH_Delete_Task (i) ;
//// }
//// Error_code_G = 0;
//// Timer_init ( ) ;
//// Watchdog_init ( ) ;
//}

//unsigned char SCH_Add_Task ( void (*pFunction) () , unsigned int DELAY,unsigned int PERIOD){
//	unsigned char Index = 0;
// // Fi r s t find a gap in the array ( i f there i s one)
// while ( ( SCH_tasks_G [ Index ] . pTask != 0 ) && ( Index < SCH_MAX_TASKS) )
// {
// Index ++;
// }
//  if ( Index == SCH_MAX_TASKS)
// {
// // Task l i s t i s f u l l
// // Set the global e r ro r v a ri abl e
// //Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
// // Also return an e r ro r code
// return SCH_MAX_TASKS;
// }
// // I f we ’re here , there i s a space in the task array
// SCH_tasks_G [ Index ] . pTask = pFunction ;
// SCH_tasks_G [ Index ] . Delay = DELAY;
// SCH_tasks_G [ Index ] . Period = PERIOD;
// SCH_tasks_G [ Index ] .RunMe = 0;
// // return posi tion o f task ( to allow l a t e r dele tion )
// return Index ;
// }
//
//void SCH_Update ( void ) {
// unsigned char Index ;
// // NOTE: c alcul a tions are in *TICKS*
// for ( Index = 0; Index < SCH_MAX_TASKS; Index++) {
// // Check i f there i s a task a t t hi s loca tion
// if ( SCH_tasks_G [ Index ] . pTask ) {
//	 if ( SCH_tasks_G [ Index ] . Delay == 0 ) {
// // The task i s due to run
// // Inc . the ’RunMe’ fl a g
// SCH_tasks_G [ Index ] .RunMe += 1;
// 	 if ( SCH_tasks_G [ Index ] . Period ) {
// // Schedule periodic tasks to run again
// SCH_tasks_G [ Index ] . Delay = SCH_tasks_G [ Index ] . Period ;
// }
// } else {
// // Not ye t ready to run : j u s t decrement the delay
// SCH_tasks_G [ Index ] . Delay -= 1;
// }
// }
// }
// }
//
//void SCH_Dispatch_Tasks ( void ){
// unsigned char Index ;
// // Dispatches (runs ) the next task ( i f one i s ready )
// for ( Index = 0; Index < SCH_MAX_TASKS; Index++) {
// if ( SCH_tasks_G [ Index ] .RunMe > 0 ) {
// ( * SCH_tasks_G [ Index ] . pTask ) ( ) ; // Run the task
// SCH_tasks_G [ Index ] .RunMe -= 1; // Reset / reduce RunMe fl a g
// // Periodic tasks will au toma tically run again
// // − i f t hi s i s a ’one shot ’ task , remove i t from the array
// if ( SCH_tasks_G [ Index ] . Period == 0 )
// {
// SCH_Delete_Task ( Index ) ;
// }
// }
// }
// // Report system s t a tus
// //SCH_Report_Status ( ) ;
// // The scheduler en ters i dl e mode a t t hi s point
//// SCH_Go_To_Sleep ( ) ;
// }
//
//void SCH_Delete_Task(uint32_t TASK_INDEX) {
//    // Đặt tất cả các trường của task tại TASK_INDEX về 0
//    SCH_tasks_G[TASK_INDEX].pTask = 0x0000;
//    SCH_tasks_G[TASK_INDEX].Delay = 0;
//    SCH_tasks_G[TASK_INDEX].Period = 0;
//    SCH_tasks_G[TASK_INDEX].RunMe = 0;
//}

void SCH_Init(void) {
    SCH_task_head = 0;
    SCH_task_tail = 0;

    // Xóa tất cả các task
    for (uint8_t i = 0; i < SCH_MAX_TASKS; i++) {
        SCH_tasks_G[i].pTask = 0x0000;
        SCH_tasks_G[i].Delay = 0;
        SCH_tasks_G[i].Period = 0;
        SCH_tasks_G[i].RunMe = 0;
    }
}

// Thêm task
uint8_t SCH_Add_Task(void (*pFunction)(void), uint32_t DELAY, uint32_t PERIOD) {
    if ((SCH_task_tail + 1) % SCH_MAX_TASKS == SCH_task_head) {
        // Hàng đợi đầy
        return SCH_MAX_TASKS;
    }

    SCH_tasks_G[SCH_task_tail].pTask = pFunction;
    SCH_tasks_G[SCH_task_tail].Delay = DELAY;
    SCH_tasks_G[SCH_task_tail].Period = PERIOD;
    SCH_tasks_G[SCH_task_tail].RunMe = 0;

    uint8_t task_id = SCH_task_tail;
    SCH_task_tail = (SCH_task_tail + 1) % SCH_MAX_TASKS;

    return task_id;
}

// Xóa task
void SCH_Delete_Task(uint8_t TASK_INDEX) {
    SCH_tasks_G[TASK_INDEX].pTask = 0x0000;
    SCH_tasks_G[TASK_INDEX].Delay = 0;
    SCH_tasks_G[TASK_INDEX].Period = 0;
    SCH_tasks_G[TASK_INDEX].RunMe = 0;

    // Nếu xóa task đầu, di chuyển head
    if (TASK_INDEX == SCH_task_head) {
        SCH_task_head = (SCH_task_head + 1) % SCH_MAX_TASKS;
    }
}

// Cập nhật thời gian chờ
void SCH_Update(void) {
    uint8_t Index = SCH_task_head;

    while (Index != SCH_task_tail) {
        if (SCH_tasks_G[Index].pTask) {
            if (SCH_tasks_G[Index].Delay == 0) {
                SCH_tasks_G[Index].RunMe += 1;

                if (SCH_tasks_G[Index].Period) {
                    SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
                }
            } else {
                SCH_tasks_G[Index].Delay -= 1;
            }
        }
        Index = (Index + 1) % SCH_MAX_TASKS;
    }
}

// Thực thi các task
void SCH_Dispatch_Tasks(void) {
    uint8_t Index = SCH_task_head;

    while (Index != SCH_task_tail) {
        if (SCH_tasks_G[Index].RunMe > 0) {
            (*SCH_tasks_G[Index].pTask)();
            SCH_tasks_G[Index].RunMe -= 1;

            if (SCH_tasks_G[Index].Period == 0) {
                SCH_Delete_Task(Index);
            }
        }
        Index = (Index + 1) % SCH_MAX_TASKS;
    }
}
