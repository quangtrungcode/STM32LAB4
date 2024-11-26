/*
 * fsm_setting.c
 *
 *  Created on: Nov 26, 2024
 *      Author: ADMIN
 */

#include "fsm_setting.h"

//int checksavered=0;
void fsm_setting_run(){
      switch(status){
		  case INCREASE_VALUE_LED_RED:
//			  	Increase_Save_led7RED_segment_run13();
			//  SCH_Dispatch_Tasks();
				if(checksavered==0){
				//	Save_led7RED_segment_run13();
					Turn_On_All_LED_RED();
					Increase_Save_led7RED_segment_run13();
					++checksavered;
				}
//				if(isTimerExpired(1)==1){
//					Save_led7RED_segment_run02();
//					setTimer(1, 1000);
//				}
//				if(isTimerExpired(2)==1){
////					if(checksavered==0){
////						Increase_Save_led7RED_segment_run13();
////						checksavered=1;
////					}
//					Save_led7RED_segment_run13();
//					setTimer(2, 1000);
//		//			setTimer(4, 10000);
//				}
//				if(isTimerExpired(3)==1){
//					HAL_GPIO_TogglePin(GPIOA, LED_RED1_Pin|LED_RED2_Pin);
//					setTimer(3, 500);
//				}
//				if(isTimerExpired(4)==1){
//					status=AUTO_RED1_GREEN2;
//					counter=0;
//					++countergreen13;
//					counterred13=savecounterred13-checksavered;
//					checksavered=0;
//					--idx_led13;
//					setTimer(0, countergreen13*1000);
//		               setTimer(1, 443);
//		               setTimer(2, 1000);
//				}
//				if(isTimerExpired(5)==1){
//					status=AUTO_RED1_YELLOW2;
//					counter=0;
//					if(counterred13!=a) {
//						++counteryellow13;
//						counterred13=savecounterred13-checksavered;
//					}
//					else{
//						counterred13=1;
//						counteryellow13=1;
//					}
//					checksavered=0;
//					--idx_led13;
//					setTimer(0, counteryellow13*1000);
//		               setTimer(1, 443);
//		               setTimer(2, 1000);
//				}
//				if(isTimerExpired(6)==1){
//					status=AUTO_GREEN1_RED2;
//					counter=0;
//					++countergreen13;
//					counterred13=savecounterred13-checksavered;
//					checksavered=0;
//					--idx_led13;
//					setTimer(0, countergreen13*1000);
//		               setTimer(1, 443);
//		               setTimer(2, 1000);
//				}
//				if(isTimerExpired(7)==1){
//					status=AUTO_YELLOW1_RED2;
//					counter=0;
//					if(counterred13!=a) {
//						++counteryellow13;
//						counterred13=savecounterred13-checksavered;
//					}
//					else{
//						counterred13=1;
//						counteryellow13=1;
//					}
//					checksavered=0;
//					--idx_led13;
//					setTimer(0, counteryellow13*1000);
//		               setTimer(1, 443);
//		               setTimer(2, 1000);
//				}

				if(isButtonPressed(0)==1){
					status= MAN_GREEN;
					check=0;
					checkcountergreen=0;
				//	checksavegreen=0;
					counterred=a;
//					clear_timer_flag(1);
//					clear_timer_flag(2);
//					clear_timer_flag(3);
//					setTimer(1, 500);
//					setTimer(2, 1000);
//					setTimer(3, 500);
//					setTimer(4, 10000);
					SCH_Delete_Task(task_id7);
					SCH_Delete_Task(task_id8);
					SCH_Delete_Task(task_id9);
					task_id10= SCH_Add_Task(Save_led7GREEN_segment_run02,50,100);
					task_id11= SCH_Add_Task(Save_led7GREEN_segment_run13,0,100);
					task_id12= SCH_Add_Task(LED_GREEN_TEST, 50, 50);
				}
				if(isButtonPressed(1)==1){
					++checksavered;
				    Increase_Save_led7RED_segment_run13();
//					clear_timer_flag(1);
//					clear_timer_flag(2);
//					clear_timer_flag(3);
//					setTimer(1, 500);
//					setTimer(2, 1000);
//					setTimer(3, 500);
				 //   setTimer(checkstatus, 10000);
				}
				if(isButtonPressed(2)==1){
					status=SET_VALUE_LED_RED;
					checksavered=0;
					SCH_Delete_Task(task_id9);
//					SCH_Delete_Task(task_id11);
//					SCH_Delete_Task(task_id12);
//					task_id13= SCH_Add_Task(Save_led7RED_segment_run02,50,100);
//					task_id14= SCH_Add_Task(Save_led7RED_segment_run13,0,100);
				//	task_id15= SCH_Add_Task(LED_GREEN_TEST, 50, 50);
//					clear_timer_flag(1);
//					clear_timer_flag(2);
//					setTimer(1, 500);
//					setTimer(2, 1000);
				//	  setTimer(checkstatus, 10000);
//					  counterred13 = savecounterred13;
//					  countergreen13=counterred13-counteryellow13;
//					  counteryellow13=counterred13-countergreen13;
//					  a=counterred13;
//					  b=countergreen13;
//					  c=counteryellow13;
				}

			  break;
		  case SET_VALUE_LED_RED:
			//  SCH_Dispatch_Tasks();
			  Turn_On_All_LED_RED();
			  counterred = savecounterred13;
			//  countergreen13=counterred13-counteryellow13;
			// counteryellow13=counterred13-countergreen13;
			//  savecountergreen13=countergreen13;
			//  a=counterred13;
			//  b=countergreen13;
			//  c=counteryellow13;
				if(checksavered==0){
					Save_led7RED_segment_run13();
					//Increase_Save_led7RED_segment_run13();
					checksavered=1;
				}
//				if(isTimerExpired(1)==1){
//					Save_led7RED_segment_run02();
//					setTimer(1, 1000);
//				}
//				if(isTimerExpired(2)==1){
////					if(checksavered==0){
////						Increase_Save_led7RED_segment_run13();
////						checksavered=1;
////					}
//					Save_led7RED_segment_run13();
//					setTimer(2, 1000);
//		//			setTimer(4, 10000);
//				}
//				if(isTimerExpired(3)==1){
//					HAL_GPIO_TogglePin(GPIOA, LED_RED1_Pin|LED_RED2_Pin);
//					setTimer(3, 500);
//				}
//				if(isTimerExpired(checkstatus)==1){
//					status=AUTO_RED1_GREEN2;
//					counter=0;
//					//++countergreen13;
//					//counterred13;
//					idx_led13=0;
//					setTimer(0, b*1000);
//		            setTimer(1, 443);
//		            setTimer(2, 1000);
//				}
//				if(isTimerExpired(5)==1){
//					status=AUTO_RED1_YELLOW2;
//					if(counterred13!=a) {
//						++counteryellow13;
//					}
//					else{
//						counterred13=1;
//						counteryellow13=1;
//					}
//					--idx_led13;
//					setTimer(0, counteryellow13*1000);
//				}
//				if(isTimerExpired(6)==1){
//					status=AUTO_GREEN1_RED2;
//					++countergreen13;
//					//++counterred13;
//					--idx_led13;
//					setTimer(0, countergreen13*1000);
//				}
//				if(isTimerExpired(7)==1){
//					status=AUTO_YELLOW1_RED2;
//					if(counterred13!=a) {
//						++counteryellow13;
//					}
//					else{
//						counterred13=1;
//						counteryellow13=1;
//					}
//					--idx_led13;
//					setTimer(0, counteryellow13*1000);
//				}
//				if(isButtonPressed(0)==1){
//					status= MAN_GREEN;
//					check=0;
//					setTimer(1, 1000);
//					setTimer(2, 1000);
//					setTimer(3, 500);
//					setTimer(checkstatus, 10000);
//					checkcountergreen=1;
//				}
				if(isButtonPressed(0)==1){
					status= MAN_GREEN;
					check=0;
					checkcountergreen=0;
//					clear_timer_flag(1);
//					clear_timer_flag(2);
//					clear_timer_flag(3);
//					setTimer(1, 500);
//					setTimer(2, 1000);
//					setTimer(3, 500);
				//	setTimer(4, 10000);
					SCH_Delete_Task(task_id7);
					SCH_Delete_Task(task_id8);
					task_id10= SCH_Add_Task(Save_led7GREEN_segment_run02,50,100);
					task_id11= SCH_Add_Task(Save_led7GREEN_segment_run13,0,100);
					task_id12= SCH_Add_Task(LED_GREEN_TEST, 50, 50);
				}
				if(isButtonPressed(1)==1){
					status=INCREASE_VALUE_LED_RED;
					//Increase_Save_led7RED_segment_run13();
					checksavered=0;
					task_id9= SCH_Add_Task(LED_RED_TEST, 50, 50);
//					clear_timer_flag(1);
//					clear_timer_flag(2);
//					clear_timer_flag(3);
//					setTimer(1, 500);
//					setTimer(2, 1000);
//					setTimer(3, 500);
				//	setTimer(checkstatus, 10000);
//					SCH_Delete_Task(task_id13);
//					SCH_Delete_Task(task_id14);
//					task_id13= SCH_Add_Task(Save_led7RED_segment_run02,50,100);
//					task_id14= SCH_Add_Task(Save_led7RED_segment_run13,0,100);
//					task_id15= SCH_Add_Task(LED_RED_TEST, 50, 50);

				}
//				if(isButtonPressed(2)==1){
//					status=SAVE_VALUE_LED_RED;
////					status=AUTO_RED1_GREEN2;
////					counter=0;
////					//++countergreen13;
////					//counterred13;
////					idx_led13=0;
////					setTimer(0, b*1000);
////		            setTimer(1, 443);
////		            setTimer(2, 1000);
//				}

			  break;
		  case INCREASE_VALUE_LED_GREEN:
			//  SCH_Dispatch_Tasks();
				if(checksavegreen==0){
					Turn_On_All_LED_GREEN();
					Increase_Save_led7GREEN_segment_run13();
					++checksavegreen;
				}
//				if(isTimerExpired(1)==1){
//					Save_led7GREEN_segment_run02();
//					setTimer(1, 1000);
//				}
//				if(isTimerExpired(2)==1){
//					Save_led7GREEN_segment_run13();
//					setTimer(2, 1000);
//				}
//				if(isTimerExpired(3)==1){
//					HAL_GPIO_TogglePin(GPIOA, LED_GREEN1_Pin|LED_GREEN2_Pin);
//					setTimer(3, 500);
//				}
				if(isButtonPressed(0)==1){
					status= MAN_YELLOW;
					check=0;
					checkcounteryellow=0;
				//	checksaveyellow=0;
					countergreen=b;
//					clear_timer_flag(1);
//					clear_timer_flag(2);
//					clear_timer_flag(3);
//					setTimer(1, 500);
//					setTimer(2, 1000);
//					setTimer(3, 500);
//					setTimer(4, 10000);
					SCH_Delete_Task(task_id10);
					SCH_Delete_Task(task_id11);
					SCH_Delete_Task(task_id12);
					task_id13= SCH_Add_Task(Save_led7YELLOW_segment_run02,50,100);
					task_id14= SCH_Add_Task(Save_led7YELLOW_segment_run13,0,100);
					task_id15= SCH_Add_Task(LED_YELLOW_TEST, 50, 50);

				}
				if(isButtonPressed(1)==1){
					++checksavegreen;
				    Increase_Save_led7GREEN_segment_run13();
//					clear_timer_flag(1);
//					clear_timer_flag(2);
//					clear_timer_flag(3);
//					setTimer(1, 500);
//					setTimer(2, 1000);
//					setTimer(3, 500);
				}
				if(isButtonPressed(2)==1){
					status=SET_VALUE_LED_GREEN;
					checksavegreen=0;
					SCH_Delete_Task(task_id12);
//					clear_timer_flag(1);
//					clear_timer_flag(2);
//					setTimer(1, 500);
//					setTimer(2, 1000);
				}
			  break;
		  case SET_VALUE_LED_GREEN:
			//  SCH_Dispatch_Tasks();
                      Turn_On_All_LED_GREEN();
		  			  countergreen = savecountergreen13;
		  			 // b=countergreen13;
		  				if(checksavegreen==0){
		  					Save_led7GREEN_segment_run13();
		  					checksavegreen=1;
		  				}
//		  				if(isTimerExpired(1)==1){
//		  					Save_led7GREEN_segment_run02();
//		  					setTimer(1, 1000);
//		  				}
//		  				if(isTimerExpired(2)==1){
//		  					Save_led7GREEN_segment_run13();
//		  					setTimer(2, 1000);
//		  				}
//		  				if(isTimerExpired(3)==1){
//		  					HAL_GPIO_TogglePin(GPIOA, LED_GREEN1_Pin|LED_GREEN2_Pin);
//		  					setTimer(3, 500);
//		  				}
		  				if(isButtonPressed(0)==1){
		  					status= MAN_YELLOW;
		  					check=0;
		  					checkcounteryellow=0;
							SCH_Delete_Task(task_id10);
							SCH_Delete_Task(task_id11);
							task_id13= SCH_Add_Task(Save_led7YELLOW_segment_run02,50,100);
							task_id14= SCH_Add_Task(Save_led7YELLOW_segment_run13,0,100);
							task_id15= SCH_Add_Task(LED_YELLOW_TEST, 50, 50);
		  				//	checksaveyellow=0;
//							clear_timer_flag(1);
//							clear_timer_flag(2);
//							clear_timer_flag(3);
//		  					setTimer(1, 500);
//		  					setTimer(2, 1000);
//		  					setTimer(3, 500);
		  				}
		  				if(isButtonPressed(1)==1){
		  					status=INCREASE_VALUE_LED_GREEN;
		  					checksavegreen=0;
		  					task_id12= SCH_Add_Task(Save_led7GREEN_segment_run02,50,50);
//							clear_timer_flag(1);
//							clear_timer_flag(2);
//							clear_timer_flag(3);
//		  					setTimer(1, 500);
//		  					setTimer(2, 1000);
//		  					setTimer(3, 500);
		  				}
		  			  break;
		  case INCREASE_VALUE_LED_YELLOW:
			//  SCH_Dispatch_Tasks();
				if(checksaveyellow==0){
					Turn_On_All_LED_YELLOW();
					Increase_Save_led7YELLOW_segment_run13();
					++checksaveyellow;
				}
//				if(isTimerExpired(1)==1){
//					Save_led7YELLOW_segment_run02();
//					setTimer(1, 1000);
//				}
//				if(isTimerExpired(2)==1){
//					Save_led7YELLOW_segment_run13();
//					setTimer(2, 1000);
//				}
//				if(isTimerExpired(3)==1){
//					HAL_GPIO_TogglePin(GPIOA, LED_YELLOW1_Pin|LED_YELLOW2_Pin);
//					setTimer(3, 500);
//				}
				if(isButtonPressed(0)==1){
					status= INIT;
					counteryellow=c;
					SCH_Delete_Task(task_id13);
					SCH_Delete_Task(task_id14);
					SCH_Delete_Task(task_id15);
//					clear_timer_flag(1);
//					clear_timer_flag(2);
				}
				if(isButtonPressed(1)==1){
					++checksaveyellow;
				    Increase_Save_led7YELLOW_segment_run13();
//					clear_timer_flag(1);
//					clear_timer_flag(2);
//					clear_timer_flag(3);
//					setTimer(1, 500);
//					setTimer(2, 1000);
//					setTimer(3, 500);
				}
				if(isButtonPressed(2)==1){
					status=SET_VALUE_LED_YELLOW;
					checksaveyellow=0;
					SCH_Delete_Task(task_id15);
//					clear_timer_flag(1);
//					clear_timer_flag(2);
//					setTimer(1, 500);
//					setTimer(2, 1000);
				}
			  break;
		  case SET_VALUE_LED_YELLOW:
			//  SCH_Dispatch_Tasks();
			          Turn_On_All_LED_YELLOW();
		  			  counteryellow = savecounteryellow13;
		  			//  c=counteryellow13;
		  				if(checksaveyellow==0){
		  					Save_led7YELLOW_segment_run13();
		  					checksaveyellow=1;
		  				}
//		  				if(isTimerExpired(1)==1){
//		  					Save_led7YELLOW_segment_run02();
//		  					setTimer(1, 1000);
//		  				}
//		  				if(isTimerExpired(2)==1){
//		  					Save_led7YELLOW_segment_run13();
//		  					setTimer(2, 1000);
//		  				}
//		  				if(isTimerExpired(3)==1){
//		  					HAL_GPIO_TogglePin(GPIOA, LED_YELLOW1_Pin|LED_YELLOW2_Pin);
//		  					setTimer(3, 500);
//		  				}
		  				if(isButtonPressed(0)==1){
		  					status= INIT;
							SCH_Delete_Task(task_id13);
							SCH_Delete_Task(task_id14);
//		  					clear_timer_flag(1);
//		  					clear_timer_flag(2);
		  				}
		  				if(isButtonPressed(1)==1){
		  					status=INCREASE_VALUE_LED_YELLOW;
		  					checksaveyellow=0;
		  					task_id15= SCH_Add_Task(Save_led7YELLOW_segment_run02,50,50);
//							clear_timer_flag(1);
//							clear_timer_flag(2);
//							clear_timer_flag(3);
//		  					setTimer(1, 500);
//		  					setTimer(2, 1000);
//		  					setTimer(3, 500);
		  				}
		  			  break;
		  default:
			  break;
      }
}
