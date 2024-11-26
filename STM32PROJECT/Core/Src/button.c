/*
 * button.c
 *
 *  Created on: Nov 26, 2024
 *      Author: ADMIN
 */
#include "button.h"

#define MAX_COUNTER 3
#define NUM_BUTTONS 3
int Button_flag[MAX_COUNTER]={0};
//int Button_counter[MAX_COUNTER];

int KeyReg0[NUM_BUTTONS]={NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg1[NUM_BUTTONS]={NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg2[NUM_BUTTONS]={NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg3[NUM_BUTTONS]={NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int TimerForKeyPress[NUM_BUTTONS]={200,200,200};
GPIO_TypeDef* Button_GPIO_Port[NUM_BUTTONS]={Button0_GPIO_Port,Button1_GPIO_Port,Button2_GPIO_Port};
uint16_t Button_Pin[NUM_BUTTONS]={Button0_Pin,Button1_Pin,Button2_Pin};
int isButtonPressed(int index){
	if(Button_flag[index]==1){
		Button_flag[index]=0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index){
	Button_flag[index]=1;
}

//void getKeyInput(){
//	KeyReg0=KeyReg1;
//	KeyReg1=KeyReg2;
//	KeyReg2=HAL_GPIO_ReadPin(Button0_GPIO_Port, Button0_Pin);
//	if((KeyReg0==KeyReg1)&&(KeyReg1==KeyReg2)){
//		if(KeyReg3!=KeyReg2){
//			KeyReg3=KeyReg2;
//			if(KeyReg2==PRESSED_STATE){
//				subKeyProcess();
//				TimerForKeyPress=200;
//			}
//		}
//		else{
//			TimerForKeyPress--;
//			if(TimerForKeyPress==0){
//				KeyReg3=NORMAL_STATE;
//			}
//		}
//	}
//}
void getKeyInput() {
	for (int i = 0; i < NUM_BUTTONS; i++) {
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		KeyReg2[i] = HAL_GPIO_ReadPin(Button_GPIO_Port[i], Button_Pin[i]); // Assuming GPIO ports/pins are in arrays

		if ((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])) {
			if (KeyReg3[i] != KeyReg2[i]) {
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg2[i] == PRESSED_STATE) {
					subKeyProcess(i);  // Assuming a modified subKeyProcess that accepts button index
					TimerForKeyPress[i] = 200;
				}
			} else {
				TimerForKeyPress[i]--;
				if (TimerForKeyPress[i] == 0) {
					KeyReg3[i] = NORMAL_STATE;
				}
			}
		}
	}
}

