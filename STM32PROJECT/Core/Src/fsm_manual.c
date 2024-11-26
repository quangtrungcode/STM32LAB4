/*
 * fsm_manual.c
 *
 *  Created on: Nov 26, 2024
 *      Author: ADMIN
 */

#include "fsm_manual.h"
#include "global.h"

//int check=0;

void fsm_manual_run(){
	switch(status){
	case MAN_RED:
//		HAL_Delay(1000);
//		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		//HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, RESET);
	//	SCH_Dispatch_Tasks();
		if(check==0){
			Turn_On_All_LED_RED();
			Save_led7RED_segment_run13();
			check=1;
		}
//		if(isTimerExpired(1)==1){
//			Save_led7RED_segment_run02();
//			setTimer(1, 1000);
//		}
//		if(isTimerExpired(2)==1){
//			Save_led7RED_segment_run13();
//			setTimer(2, 1000);
//		}
//		if(isTimerExpired(3)==1){
//			HAL_GPIO_TogglePin(GPIOA, LED_RED1_Pin|LED_RED2_Pin);
//			setTimer(3, 500);
//		}
//		if(isTimerExpired(4)==1){
//			status=AUTO_RED1_GREEN2;
//			++countergreen13;
//			//counterred13;
//			counter=0;
//            setTimer(1, 1000);
//            setTimer(2, 1000);
//          //  setTimer(8, 1000);
//			--idx_led13;
//			setTimer(0, countergreen13*1000);
//		}
//		if(isTimerExpired(5)==1){
//			status=AUTO_RED1_YELLOW2;
//			if(counterred13!=a) {
//				++counteryellow13;
//			}
//			else{
//				counterred13=1;
//				counteryellow13=1;
//			}
//			counter=0;
//            setTimer(1, 1000);
//            setTimer(2, 1000);
//			--idx_led13;
//			setTimer(0, counteryellow13*1000);
//		}
//		if(isTimerExpired(6)==1){
//			status=AUTO_GREEN1_RED2;
//			++countergreen13;
//			//++counterred13;
//			--idx_led13;
//			counter=0;
//            setTimer(1, 1000);
//            setTimer(2, 1000);
//			setTimer(0, countergreen13*1000);
//		}
//		if(isTimerExpired(7)==1){
//			status=AUTO_YELLOW1_RED2;
//			if(counterred13!=a) {
//				++counteryellow13;
//			}
//			else{
//				counterred13=1;
//				counteryellow13=1;
//			}
//			--idx_led13;
//			counter=0;
//            setTimer(1, 1000);
//            setTimer(2, 1000);
//			setTimer(0, counteryellow13*1000);
//		}
		if(isButtonPressed(0)==1){
			status= MAN_GREEN;
			check=0;
			counterred=a;
//			clear_timer_flag(1);
//			clear_timer_flag(2);
//			clear_timer_flag(3);
//			setTimer(1, 500);
//			setTimer(2, 1000);
//			setTimer(3, 500);
			SCH_Delete_Task(task_id7);
			SCH_Delete_Task(task_id8);
			SCH_Delete_Task(task_id9);
			task_id10= SCH_Add_Task(Save_led7GREEN_segment_run02,50,100);
			task_id11= SCH_Add_Task(Save_led7GREEN_segment_run13,0,100);
			task_id12= SCH_Add_Task(LED_GREEN_TEST, 50, 50);
			checkcountergreen=0;
		//	checksavered=0;
		//	checksavegreen=0;
		//	setTimer(4, 10000);
		}
		if(isButtonPressed(1)==1){
			status=INCREASE_VALUE_LED_RED;
			//Increase_Save_led7RED_segment_run13();
//			clear_timer_flag(1);
//			clear_timer_flag(2);
//			clear_timer_flag(3);
//			setTimer(1, 500);
//			setTimer(2, 1000);
//			setTimer(3, 500);
		//	setTimer(checkstatus, 10000);
//			SCH_Delete_Task(task_id7);
//			SCH_Delete_Task(task_id8);
//			SCH_Delete_Task(task_id9);
//			task_id10= SCH_Add_Task(Save_led7RED_segment_run02,50,100);
//			task_id11= SCH_Add_Task(Save_led7RED_segment_run13,0,100);
//			task_id12= SCH_Add_Task(LED_RED_TEST, 50, 50);
		    checksavered=0;
		}
		if(isButtonPressed(2)==1){

		}
		break;
//	case INCREASE_VALUE_LED_RED:
//		break;
//	case SET_VALUE_LED_RED:
//		break;
	case MAN_GREEN:
	//	SCH_Dispatch_Tasks();
		if(check==0){
		//	HAL_GPIO_WritePin(GPIOA,LED_RED1_Pin|LED_RED2_Pin, SET);
			Turn_On_All_LED_GREEN();
			Save_led7GREEN_segment_run13();
			check=1;
		}
//		if(isTimerExpired(1)==1){
//			Save_led7GREEN_segment_run02();
//			setTimer(1, 1000);
//		}
//		if(isTimerExpired(2)==1){
//			Save_led7GREEN_segment_run13();
//			setTimer(2, 1000);
//		}
//		if(isTimerExpired(3)==1){
//			HAL_GPIO_TogglePin(GPIOA, LED_GREEN1_Pin|LED_GREEN2_Pin);
//			setTimer(3, 500);
//		}
		if(isButtonPressed(0)==1){
			status= MAN_YELLOW;
			check=0;
			checkcounteryellow=0;
			countergreen=b;
//			clear_timer_flag(1);
//			clear_timer_flag(2);
//			clear_timer_flag(3);
//			setTimer(1, 500);
//			setTimer(2, 1000);
//			setTimer(3, 500);
			SCH_Delete_Task(task_id10);
			SCH_Delete_Task(task_id11);
			SCH_Delete_Task(task_id12);
			task_id13= SCH_Add_Task(Save_led7YELLOW_segment_run02,50,100);
			task_id14= SCH_Add_Task(Save_led7YELLOW_segment_run13,0,100);
			task_id15= SCH_Add_Task(LED_YELLOW_TEST, 50, 50);
		//	checksaveyellow=0;
		//	setTimer(4, 10000);
		}
		if(isButtonPressed(1)==1){
			status=INCREASE_VALUE_LED_GREEN;
//			clear_timer_flag(1);
//			clear_timer_flag(2);
//			clear_timer_flag(3);
//			setTimer(1, 500);
//			setTimer(2, 1000);
//			setTimer(3, 500);
			checksavegreen=0;
		}
		break;
	case MAN_YELLOW:
	//	SCH_Dispatch_Tasks();
		if(check==0){
		//	HAL_GPIO_WritePin(GPIOA,LED_GREEN1_Pin|LED_GREEN2_Pin, SET);
			Turn_On_All_LED_YELLOW();
			Save_led7YELLOW_segment_run13();
			check=1;
		}
//		if(isTimerExpired(1)==1){
//			Save_led7YELLOW_segment_run02();
//			setTimer(1, 1000);
//		}
//		if(isTimerExpired(2)==1){
//			Save_led7YELLOW_segment_run13();
//			setTimer(2, 1000);
//		}
//		if(isTimerExpired(3)==1){
//			HAL_GPIO_TogglePin(GPIOA, LED_YELLOW1_Pin|LED_YELLOW2_Pin);
//			setTimer(3, 500);
//		}
		if(isButtonPressed(0)==1){
//			status= AUTO_RED1_GREEN2;
//            set_led();
//            set_led7_segement();
//            setTimer(0, 3000);
//            setTimer(1, 1000);
//            setTimer(2, 1000);
//            counter=0;
			counteryellow=c;
			status=INIT;
			SCH_Delete_Task(task_id13);
			SCH_Delete_Task(task_id14);
			SCH_Delete_Task(task_id15);
//			clear_timer_flag(1);
//			clear_timer_flag(2);
			//before=0;
		}
		if(isButtonPressed(1)==1){
			status=INCREASE_VALUE_LED_YELLOW;
			//Increase_Save_led7RED_segment_run13();
//			clear_timer_flag(1);
//			clear_timer_flag(2);
//			clear_timer_flag(3);
//			setTimer(1, 500);
//			setTimer(2, 1000);
//			setTimer(3, 500);
		//	setTimer(checkstatus, 10000);
		    checksaveyellow=0;
		}
		break;
//	case CHECK_TIME:
//		HAL_GPIO_WritePin(GPIOA,LED_YELLOW1_Pin|LED_YELLOW2_Pin, SET);
//		if(counterred13==(countergreen13+counteryellow13)){
//			a=counterred13;
//			b=countergreen13;
//			c=counteryellow13;
//			status=AUTO_RED1_GREEN2;
//			counter=0;
//			setTimer(0, b*1000);
//			setTimer(1, 1000);
//			setTimer(2, 1000);
//		}
//		else{
//			counterred13=a;
//			countergreen13=b;
//			counteryellow13=c;
//			status=AUTO_RED1_GREEN2;
//			counter=0;
//            setTimer(0, b*1000);
//            setTimer(1, 1000);
//            setTimer(2, 1000);
//		}
//		break;
	default:
		break;
	}
}
