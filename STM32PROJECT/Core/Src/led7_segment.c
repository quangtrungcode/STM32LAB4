/*
 * led7_segment.c
 *
 *  Created on: Nov 26, 2024
 *      Author: ADMIN
 */

#include "led7_segment.h"
#include "scheduler.h"
int idx=0;
int idx_led02=0;
int idx_led13=0;
int counterred02=2;
int counterred13=5;

int countergreen02=1;
int countergreen13=3;

int counteryellow02=1;
int counteryellow13=1;

int savecounterred13,savecountergreen13,savecounteryellow13 =0;
int checkcounterred,checkcountergreen,checkcounteryellow=0;
int checkcounterred02,checkcountergreen02,checkcounteryellow02=0;
int a=5;
int b=3;
int c=1;
//int d=2;
//int e=1;
//int f=1;
int counterred=5;
int countergreen=3;
int counteryellow=1;

int savecounterred02,savecountergreen02,savecounteryellow02=0;
void set_led7_segement(){
	HAL_GPIO_WritePin(GPIOB, SEG0X_Pin|SEG1X_Pin|SEG2X_Pin|EN3_Pin
		                          |SEG3X_Pin|SEG4X_Pin|SEG5X_Pin|SEG6X_Pin
		                          |EN0_Pin|EN1_Pin|EN2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, SEG0Y_Pin|SEG1Y_Pin|SEG2Y_Pin|SEG3Y_Pin|SEG4Y_Pin|SEG5Y_Pin|SEG6Y_Pin, GPIO_PIN_SET);
}
void display7SEGX(int num) {
      const uint8_t segmentMap[10] = {
          0b11111100,
          0b01100000,
          0b11011010,
          0b11110010,
          0b01100110,
          0b10110110,
          0b10111110,
          0b11100000,
          0b11111110,
          0b11110110
      };
      HAL_GPIO_WritePin(SEG0X_GPIO_Port, SEG0X_Pin, (segmentMap[num] & 0b10000000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(SEG1X_GPIO_Port, SEG1X_Pin, (segmentMap[num] & 0b01000000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(SEG2X_GPIO_Port, SEG2X_Pin, (segmentMap[num] & 0b00100000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(SEG3X_GPIO_Port, SEG3X_Pin, (segmentMap[num] & 0b00010000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(SEG4X_GPIO_Port, SEG4X_Pin, (segmentMap[num] & 0b00001000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(SEG5X_GPIO_Port, SEG5X_Pin, (segmentMap[num] & 0b00000100) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(SEG6X_GPIO_Port, SEG6X_Pin, (segmentMap[num] & 0b00000010) ? GPIO_PIN_RESET : GPIO_PIN_SET);
  }
void display7SEGY(int num) {
      const uint8_t segmentMap[10] = {
          0b11111100,
          0b01100000,
          0b11011010,
          0b11110010,
          0b01100110,
          0b10110110,
          0b10111110,
          0b11100000,
          0b11111110,
          0b11110110
      };
      HAL_GPIO_WritePin(SEG0Y_GPIO_Port, SEG0Y_Pin, (segmentMap[num] & 0b10000000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(SEG1Y_GPIO_Port, SEG1Y_Pin, (segmentMap[num] & 0b01000000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(SEG2Y_GPIO_Port, SEG2Y_Pin, (segmentMap[num] & 0b00100000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(SEG3Y_GPIO_Port, SEG3Y_Pin, (segmentMap[num] & 0b00010000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(SEG4Y_GPIO_Port, SEG4Y_Pin, (segmentMap[num] & 0b00001000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(SEG5Y_GPIO_Port, SEG5Y_Pin, (segmentMap[num] & 0b00000100) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(SEG6Y_GPIO_Port, SEG6Y_Pin, (segmentMap[num] & 0b00000010) ? GPIO_PIN_RESET : GPIO_PIN_SET);
  }
void led7_segment_run02(){

	if(idx_led02>=(2*b+2*(c+1)+2)) idx_led02=0;
	idx_led02++;
	if(idx_led02<=b+1){
					HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
					HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
					HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
					HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);

					display7SEGX((counterred+1)/10);
					if(idx_led02>=(b+1)) display7SEGY(0);
					else display7SEGY((countergreen+1)/10);
	}
	if(idx_led02>b+1&&idx_led02<=(b+c+1+1)){
					HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
					HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
					HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
					HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
					if(idx_led02>=(b+c+1+1)){
						display7SEGX(0);
						display7SEGY(0);
					}
					else{
						display7SEGX((counterred+1)/10);
						display7SEGY((counteryellow+1)/10);
					}

	}
	if(idx_led02>(b+c+1+1)&&idx_led02<=(2*b+c+1+2)){
					HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
					HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
					HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
					HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
					display7SEGY((counterred+1)/10);
					if(idx_led02>=(2*b+c+1+2)) display7SEGX(0);
					else display7SEGX((countergreen+1)/10);
	}
	if(idx_led02>(2*b+c+1+2)&&idx_led02<=(2*b+2*(c+1)+2)){
					HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
					HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
					HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
					HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
					if(idx_led02>=(2*b+2*(c+1)+2)){
						display7SEGY(0);
						display7SEGX(0);
					}
					else{
						display7SEGY((counterred+1)/10);
						display7SEGX((counteryellow+1)/10);
					}
	}
//			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
//			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
//			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
//			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
//			display7SEGX(counterred02);
//			display7SEGY(0);
}
void led7_segment_run13(){
	if(idx_led13>=(2*b+2*(c+1)+2)) idx_led13=0;
	idx_led13++;
	if(idx_led13<=b+1){
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		display7SEGX(counterred%10);
		display7SEGY(countergreen%10);
		if(idx_led13>=b+1){
			countergreen=b;
			--counterred;
		}
		else{
			--countergreen;
			--counterred;
		}
	}
	if(idx_led13>b+1&&idx_led13<=(b+c+1+1)){
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		display7SEGX(counterred%10);
		display7SEGY(counteryellow%10);
			if(idx_led13>=(b+c+1+1)){
				counterred=a;
				counteryellow=c;

			//	countergreen13=b;
			}
			else{
				--counterred;
				--counteryellow;
			}
	}
	if(idx_led13>(b+c+1+1)&&idx_led13<=(2*b+c+1+2)){
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		display7SEGY(counterred%10);
		display7SEGX(countergreen%10);
		if(idx_led13>=2*b+c+1+2){
			countergreen=b;
			--counterred;
		}
		else{
			--countergreen;
			--counterred;
		}

	}
	if(idx_led13>(2*b+c+1+2)&&idx_led13<=(2*b+2*(c+1)+2)){
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		display7SEGY(counterred%10);
		display7SEGX(counteryellow%10);
			if(idx_led13>=(2*b+2*(c+1)+2)){
				counterred=a;
				counteryellow=c;
			}
			else{
				--counterred;
				--counteryellow;
			}
	}
}
//void led7_segment_run13(int d){
//	switch(d){
//	case 0:
//		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
//		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
//		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
//		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
//		display7SEGX(counterred13--);
//		display7SEGY(countergreen13--);
//	  break;
//	case 1:
//		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
//		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
//		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
//		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
//		display7SEGX(counterred13--);
//		display7SEGY(counteryellow13--);
//			if(counterred13==0){
//				counterred13=a;
//				counteryellow13=c;
//				countergreen13=b;
//			}
//			break;
//	case 2:
//		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
//		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
//		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
//		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
//		display7SEGX(countergreen13--);
//		display7SEGY(counterred13--);
//	//	display7SEGX(countergreen13--);
//
//	break;
//	case 3:
//		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
//		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
//		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
//		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
//		display7SEGX(counteryellow13--);
//		display7SEGY(counterred13--);
//		//display7SEGX(counteryellow13--);
//			if(counterred13==0){
//				counterred13=a;
//				counteryellow13=c;
//				countergreen13=b;
//
//			}
//			break;
//	default:
//		break;
//	}
//}
void Save_led7RED_segment_run02(){
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
	display7SEGX(savecounterred13/10);
	display7SEGY(0);
}
void Save_led7GREEN_segment_run02(){
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
	display7SEGX(savecountergreen13/10);
	display7SEGY(0);
}
void Save_led7YELLOW_segment_run02(){
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
	display7SEGX(savecounteryellow13/10);
	display7SEGY(0);
}
void Save_led7RED_segment_run13(){
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	if(checkcounterred==0){
		savecounterred13=a;
		checkcounterred=1;
	}
	display7SEGX(savecounterred13%10);
	display7SEGY(2);
}
void Increase_Save_led7RED_segment_run13(){
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	if((savecounterred13)>=1&&(savecounterred13)<=98){
		        ++savecounterred13;
//		        if(((savecounterred13)%10)==0){
//		        	++counterred02;
//		        }
		   		display7SEGX(savecounterred13%10);
		   		display7SEGY(2);
	   }

}
void Save_led7GREEN_segment_run13(){
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	if(checkcountergreen==0){
		savecountergreen13=b;
		checkcountergreen=1;
	}
	display7SEGX(savecountergreen13%10);
	display7SEGY(3);
}
void Increase_Save_led7GREEN_segment_run13(){
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	if((savecountergreen13)>=1&&(savecountergreen13)<=98){
		        ++savecountergreen13;
//		        if(((savecountergreen13)%10)==0){
//		        	++counterred02;
//		        }
		   		display7SEGX(savecountergreen13%10);
		   		display7SEGY(3);
	   }
}
void Save_led7YELLOW_segment_run13(){
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	if(checkcounteryellow==0){
		savecounteryellow13=c;
		checkcounteryellow=1;
	}
	display7SEGX(savecounteryellow13%10);
	display7SEGY(4);
}
void Increase_Save_led7YELLOW_segment_run13(){
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	if((savecounteryellow13)>=1&&(savecounteryellow13)<=98){
		        ++savecounteryellow13;
//		        if(((savecounteryellow13)%10)==0){
//		        	++counterred02;
//		        }
		   		display7SEGX(savecounteryellow13%10);
		   		display7SEGY(4 );
	   }
}

void LED_RED_TEST(){
	HAL_GPIO_TogglePin(GPIOA, LED_RED1_Pin|LED_RED2_Pin);
}
void LED_GREEN_TEST(){
	HAL_GPIO_TogglePin(GPIOA, LED_GREEN1_Pin|LED_GREEN2_Pin);
}
void LED_YELLOW_TEST(){
	HAL_GPIO_TogglePin(GPIOA, LED_YELLOW1_Pin|LED_YELLOW2_Pin);
}



