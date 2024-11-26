/*
 * fsm_automatic.c
 *
 *  Created on: Nov 26, 2024
 *      Author: ADMIN
 */

#include "fsm_automatic.h"
#include "global.h"

int k1=0;
int k2=0;
int counter=0;
int checkstatus=0;
int check=0;
int checksavered=0;
int checksavegreen=0;
int checksaveyellow=0;
int task_id1, task_id2,task_id3,task_id4,task_id5,task_id6,task_id7,task_id8,task_id9,task_id10,task_id11,task_id12,
task_id13,task_id14,task_id15;
//void fsm_automatic_run(){
//	switch(status){
//		case INIT:
//			 //  counter=0;
//               set_led();
//               set_led7_segement();
//               status=AUTO_RED1_GREEN2;
//               setTimer(0, b*1000);
//               setTimer(1, 500);
//               setTimer(2, 1000);
//               setTimer(8,1000);
//   			//led7_segment_run13();
//   			//LED_RED1_GREEN2();
//			break;
//		case AUTO_RED1_GREEN2:
//			if(isTimerExpired(8)==1){
//				LED_RED1_GREEN2();
//				//	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
//				setTimer(8,1000);
//			}
//			if(counter==0){
//			led7_segment_run13();
//			LED_RED1_GREEN2();
//			//setTimer(2, 1000);
//			//setTimer(8,1000);
//			counter=1;
//			}
//			if(isTimerExpired(1)==1){
//				led7_segment_run02();
//				setTimer(1, 500);
//			}
//			if(isTimerExpired(2)==1){
//					led7_segment_run13();
//					setTimer(2, 1000);
//			}
//			if(isTimerExpired(0)==1){
//				status=AUTO_RED1_YELLOW2;
//				setTimer(0, c*1000);
//				//counter=0;
//	             setTimer(1, 500);
//	             setTimer(2, 1000);
//	             setTimer(8,1000);
//	             //  setTimer(2, 1000);
//			}
//			if(isButtonPressed(0)==1){
//		//		 HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
//				status=MAN_RED;
//			//	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
//				setTimer(1, 500);
//				setTimer(2, 1000);
//				setTimer(3, 500);
//				setTimer(4, 10000);
//			//	setTimer(8, 1000);
//				checkstatus=4;
//			}
//			break;
//		case AUTO_RED1_YELLOW2:
//			if(isTimerExpired(8)==1){
//			//	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
//			//	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
//				LED_RED1_YELLOW2();
//				setTimer(8,1000);
//			}
//			if(counter==0){
//			led7_segment_run13();
//			counter=1;
//			}
//			if(isTimerExpired(1)==1){
//				led7_segment_run02();
//				setTimer(1, 500);
//			}
//			if(isTimerExpired(2)==1){
//							led7_segment_run13();
//							setTimer(2, 1000);
//			}
//			if(isTimerExpired(0)==1){
//				status=AUTO_GREEN1_RED2;
//				setTimer(0, b*1000);
//				setTimer(8,1000);
//
//	           //    counter=0;
//			//	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
//	              setTimer(1, 500);
//	               setTimer(2, 1000);
//			}
//			if(isButtonPressed(0)==1){
//				status=MAN_RED;
//				setTimer(1, 500);
//				setTimer(2, 1000);
//				setTimer(3, 500);
//				setTimer(5, 10000);
//				checkstatus=5;
//			}
//			break;
//		case AUTO_GREEN1_RED2:
//			if(isTimerExpired(8)==1){
//				LED_GREEN1_RED2();
//				//	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
//				setTimer(8,1000);
//			}
//			if(counter==0){
//			led7_segment_run13();
//			counter=1;
//			}
//			if(isTimerExpired(1)==1){
//				led7_segment_run02();
//				setTimer(1, 500);
//			}
//			if(isTimerExpired(2)==1){
//							led7_segment_run13();
//							setTimer(2, 1000);
//			}
//			if(isTimerExpired(0)==1){
//				status=AUTO_YELLOW1_RED2;
//				setTimer(0, c*1000);
//	             //  counter=0;
//	              setTimer(1, 500);
//	              setTimer(8,1000);
//	               setTimer(2, 1000);
//			}
//			if(isButtonPressed(0)==1){
//				status=MAN_RED;
//				setTimer(1, 500);
//				setTimer(2, 1000);
//				setTimer(3, 500);
//				setTimer(6, 10000);
//				checkstatus=6;
//			}
//			break;
//		case AUTO_YELLOW1_RED2:
//			if(isTimerExpired(8)==1){
//				LED_YELLOW1_RED2();
//				setTimer(8,1000);
//			}
//			if(counter==0){
//			led7_segment_run13();
//			counter=1;
//			}
//			if(isTimerExpired(1)==1){
//				led7_segment_run02();
//				setTimer(1, 500);
//			}
//			if(isTimerExpired(2)==1){
//							led7_segment_run13();
//							setTimer(2, 1000);
//			}
//			if(isTimerExpired(0)==1){
//				status=AUTO_RED1_GREEN2;
//				setTimer(0, b*1000);
//				setTimer(8,1000);
////	              setTimer(1, 500);
////	               setTimer(2, 1000);
//			//	counter=0;
//	               setTimer(1, 500);
//	               setTimer(2, 1000);
//			}
//			if(isButtonPressed(0)==1){
//				status=MAN_RED;
//				setTimer(1, 500);
//				setTimer(2, 1000);
//				setTimer(3, 500);
//				setTimer(7, 10000);
//				checkstatus=7;
//			}
//			break;
//		default:
//			break;
//	}
//}

void fsm_automatic_run(){
	switch(status){
		case INIT:
			 //  counter=0;

               set_led();
               set_led7_segement();

       		if(counterred==(countergreen+counteryellow+1)){
       			a=counterred;
       			b=countergreen;
       			c=counteryellow;
       			idx_led13=0;
       			idx_led02=0;
       			status=AUTO_RED1_GREEN2;
    task_id1 =  SCH_Add_Task(led7_segment_run02, 50, 100);
    task_id2 =  SCH_Add_Task(led7_segment_run13, 0, 100);
    task_id3 =  SCH_Add_Task(status_transition_AUTO_RED1_GREEN2, b*100, (a+b+c+3)*100);
    task_id4 =		SCH_Add_Task(status_transition_AUTO_RED1_YELLOW2, (b+c+1)*100, (a+b+c+3)*100);
    task_id5	=    SCH_Add_Task(status_transition_AUTO_GREEN1_RED2, (b+c+1+b+1)*100, (a+b+c+3)*100);
    task_id6	=    SCH_Add_Task(status_transition_AUTO_YELLOW1_RED2,(b+c+1+b+1+c+1)*100,(a+b+c+3)*100);
       		// SCH_Dispatch_Tasks();
//       			counter=0;
//       			setTimer(0, b*1000);
//       			setTimer(1, 500);
//       			setTimer(2, 1000);
       		}
       		else{
       			counterred=a;
       			countergreen=b;
       			counteryellow=c;
       			idx_led13=0;
       			idx_led02=0;
       			status=AUTO_RED1_GREEN2;
       		    task_id1 =  SCH_Add_Task(led7_segment_run02, 50, 100);
       		    task_id2 =  SCH_Add_Task(led7_segment_run13, 0, 100);
       		    task_id3 =  SCH_Add_Task(status_transition_AUTO_RED1_GREEN2, b*100, (b+c+b+1+c+b)*100);
       		    task_id4 =		SCH_Add_Task(status_transition_AUTO_RED1_YELLOW2, (b+c+1)*100, (b+c+b+1+c+b)*100);
       		    task_id5	=    SCH_Add_Task(status_transition_AUTO_GREEN1_RED2, (b+c+1+b+1)*100, (b+c+b+1+c+b)*100);
       		    task_id6	=    SCH_Add_Task(status_transition_AUTO_YELLOW1_RED2,(b+c+1+b+1+c+1)*100,(b+c+1+b+1+c+1+b-2)*100);
//       			counter=0;
//                   setTimer(0, b*1000);
//                   setTimer(1, 500);
//                   setTimer(2, 1000);
       		}
//               status=AUTO_RED1_GREEN2;
//               setTimer(0, b*1000);
//               setTimer(1, 1000);
//               setTimer(2, 1000);
			break;
		case AUTO_RED1_GREEN2:
			LED_RED1_GREEN2();
		//	SCH_Dispatch_Tasks();
//			if(counter==0){
//			led7_segment_run13();
//			counter=1;
//			}
//			if(isTimerExpired(1)==1){
//				led7_segment_run02();
//				setTimer(1, 1000);
//			}
//			if(isTimerExpired(2)==1){
//					led7_segment_run13();
//					setTimer(2, 1000);
//			}
//			if(isTimerExpired(0)==1){
//				status=AUTO_RED1_YELLOW2;
//				//if(k1==0) {
//			//	 clear_timer_flag(1);
//			//	 clear_timer_flag(2);
//				 setTimer(1, 500);
//				 setTimer(2, 1000);
//					setTimer(0, (c+1)*1000);
//				//	k1=1;
//				//}
//			//	else setTimer(0, (c+1)*1000);
//	              // setTimer(1, 500);
//	             //  setTimer(2, 1000);
//				//counter=0;
//			}
			if(isButtonPressed(0)==1){
		//		 HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
				status=MAN_RED;
			//	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
//				clear_timer_flag(1);
//				clear_timer_flag(2);
//				setTimer(1, 500);
//				setTimer(2, 1000);
//				setTimer(3, 500);
			//	setTimer(4, 10000);
			//	checkstatus=4;
       		//    SCH_Add_Task(led7_segment_run02, 0, 0);
       		//    SCH_Add_Task(led7_segment_run13, 0, 0);
				SCH_Delete_Task(task_id1);
				SCH_Delete_Task(task_id2);
				SCH_Delete_Task(task_id3);
				SCH_Delete_Task(task_id4);
				SCH_Delete_Task(task_id5);
				SCH_Delete_Task(task_id6);
				task_id7=			SCH_Add_Task(Save_led7RED_segment_run02,50,100);
				task_id8= SCH_Add_Task(Save_led7RED_segment_run13,0,100);
				task_id9= SCH_Add_Task(LED_RED_TEST, 50, 50);
				check=0;
				checkcounterred=0;
			//	checksavered=0;
			}
			break;
		case AUTO_RED1_YELLOW2:
			LED_RED1_YELLOW2();
		//	SCH_Dispatch_Tasks();
//			if(counter==0){
//			led7_segment_run13();
//			counter=1;
//			}
//			if(isTimerExpired(1)==1){
//				led7_segment_run02();
//				setTimer(1, 1000);
//			}
//			if(isTimerExpired(2)==1){
//				led7_segment_run13();
//				setTimer(2, 1000);
//			}
//			if(isTimerExpired(0)==1){
//				status=AUTO_GREEN1_RED2;
//				 clear_timer_flag(1);
//				 clear_timer_flag(2);
//				 setTimer(1, 500);
//				 setTimer(2, 1000);
//				setTimer(0, (b+1)*1000);
//			//	setTimer(0, (b)*1000);
//	              // counter=0;
//	              // setTimer(1, 500);
//	             //  setTimer(2, 1000);
//			}
			if(isButtonPressed(0)==1){
				status=MAN_RED;
				SCH_Delete_Task(task_id1);
				SCH_Delete_Task(task_id2);
				SCH_Delete_Task(task_id3);
				SCH_Delete_Task(task_id4);
				SCH_Delete_Task(task_id5);
				SCH_Delete_Task(task_id6);
				task_id7=			SCH_Add_Task(Save_led7RED_segment_run02,50,100);
				task_id8= SCH_Add_Task(Save_led7RED_segment_run13,0,100);
				task_id9= SCH_Add_Task(LED_RED_TEST, 50, 50);
//				clear_timer_flag(1);
//				clear_timer_flag(2);
//				setTimer(1, 500);
//				setTimer(2, 1000);
//				setTimer(3, 500);
//				setTimer(5, 10000);
				//checkstatus=5;
				check=0;
				checkcounterred=0;
			}
			break;
		case AUTO_GREEN1_RED2:
			LED_GREEN1_RED2();
		//	SCH_Dispatch_Tasks();

//			if(counter==0){
//			led7_segment_run13();
//			counter=1;
//			}
//			if(isTimerExpired(1)==1){
//				led7_segment_run02();
//				setTimer(1, 1000);
//			}
//			if(isTimerExpired(2)==1){
//							led7_segment_run13();
//							setTimer(2, 1000);
//			}
//			if(isTimerExpired(0)==1){
//				status=AUTO_YELLOW1_RED2;
////				if(k2==0) {
////					setTimer(0, c*1000);
////					k2=1;
////				}
//				 clear_timer_flag(1);
//				 clear_timer_flag(2);
//				 setTimer(1, 500);
//				 setTimer(2, 1000);
//				 setTimer(0, (c+1)*1000);
//	              // setTimer(1, 500);
//	             // setTimer(2, 1000);
//	             //  counter=0;
//			}
			if(isButtonPressed(0)==1){
				status=MAN_RED;
				SCH_Delete_Task(task_id1);
				SCH_Delete_Task(task_id2);
				SCH_Delete_Task(task_id3);
				SCH_Delete_Task(task_id4);
				SCH_Delete_Task(task_id5);
				SCH_Delete_Task(task_id6);
				task_id7=			SCH_Add_Task(Save_led7RED_segment_run02,50,100);
				task_id8= SCH_Add_Task(Save_led7RED_segment_run13,0,100);
				task_id9= SCH_Add_Task(LED_RED_TEST, 50, 50);
//				clear_timer_flag(1);
//				clear_timer_flag(2);
//				setTimer(1, 500);
//				setTimer(2, 1000);
//				setTimer(3, 500);
//				setTimer(6, 10000);
				//checkstatus=6;
				check=0;
				checkcounterred=0;
			}
			break;
//		case KEEP_AUTO_GREEN1_RED2:
//			LED_GREEN1_RED2();
//			if(isTimerExpired(0)==1){
//				setTimer(0, c*1000);
//			}
//			break;
		case AUTO_YELLOW1_RED2:
			LED_YELLOW1_RED2();
		//	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		//	SCH_Dispatch_Tasks();
//			if(counter==0){
//			led7_segment_run13();
//			counter=1;
//			}
//			if(isTimerExpired(1)==1){
//				led7_segment_run02();
//				setTimer(1, 1000);
//			}
//			if(isTimerExpired(2)==1){
//							led7_segment_run13();
//							setTimer(2, 1000);
//			}
//			if(isTimerExpired(0)==1){
//				status=AUTO_RED1_GREEN2;
//				 clear_timer_flag(1);
//				 clear_timer_flag(2);
//				 setTimer(1, 500);
//				 setTimer(2, 1000);
//				setTimer(0, (b+1)*1000);
//			//	setTimer(0, (b)*1000);
//	             //  setTimer(1, 500);
//	             //  setTimer(2, 1000);
//	            //   setTimer(1, 500);
//	            //   setTimer(2, 1000);
//			}
			if(isButtonPressed(0)==1){
				status=MAN_RED;
				SCH_Delete_Task(task_id1);
				SCH_Delete_Task(task_id2);
				SCH_Delete_Task(task_id3);
				SCH_Delete_Task(task_id4);
				SCH_Delete_Task(task_id5);
				SCH_Delete_Task(task_id6);
				task_id7=			SCH_Add_Task(Save_led7RED_segment_run02,50,100);
				task_id8= SCH_Add_Task(Save_led7RED_segment_run13,0,100);
				task_id9= SCH_Add_Task(LED_RED_TEST, 50, 50);
//				clear_timer_flag(1);
//				clear_timer_flag(2);
//				setTimer(1, 500);
//				setTimer(2, 1000);
//				setTimer(3, 500);
//				setTimer(7, 10000);
				//checkstatus=7;
				check=0;
				checkcounterred=0;
			}
			break;
		default:
			break;
	}
}
