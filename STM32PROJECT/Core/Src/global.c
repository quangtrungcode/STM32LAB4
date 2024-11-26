/*
 * global.c
 *
 *  Created on: Nov 26, 2024
 *      Author: ADMIN
 */

#include"global.h"

int status=0;
int before=0;
int after=0;

void status_transition_AUTO_GREEN1_RED2(){
	//HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	status=AUTO_YELLOW1_RED2;
	SCH_Delete_Task(task_id1);
	SCH_Delete_Task(task_id2);
	task_id1 =  SCH_Add_Task(led7_segment_run02, 50, 100);
	task_id2 =  SCH_Add_Task(led7_segment_run13, 0, 100);
	//status=5;
//	SCH_Add_Task(status_transition_AUTO_YELLOW1_RED2, (c+1)*100,0);
}
void status_transition_AUTO_RED1_YELLOW2(){
	status=AUTO_GREEN1_RED2;
	SCH_Delete_Task(task_id1);
	SCH_Delete_Task(task_id2);
	task_id1 =  SCH_Add_Task(led7_segment_run02, 50, 100);
	task_id2 =  SCH_Add_Task(led7_segment_run13, 0, 100);
	//status=4;
	//HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
//	SCH_Add_Task(status_transition_AUTO_GREEN1_RED2,(b+1)*100,0);
}
void status_transition_AUTO_RED1_GREEN2(){
	status=AUTO_RED1_YELLOW2;
	SCH_Delete_Task(task_id1);
	SCH_Delete_Task(task_id2);
	task_id1 =  SCH_Add_Task(led7_segment_run02, 50, 100);
	task_id2 =  SCH_Add_Task(led7_segment_run13, 0, 100);
	//status=3;
//	SCH_Add_Task(status_transition_AUTO_RED1_YELLOW2, (c+1)*100,0);
}

void status_transition_AUTO_YELLOW1_RED2(){
	status=AUTO_RED1_GREEN2;
	SCH_Delete_Task(task_id1);
	SCH_Delete_Task(task_id2);
	task_id1 =  SCH_Add_Task(led7_segment_run02, 50, 100);
	task_id2 =  SCH_Add_Task(led7_segment_run13, 0, 100);
//	status=INIT;
	//status=2;
//	SCH_Add_Task(status_transition_AUTO_RED1_GREEN2, (b+1)*100,0);
}
