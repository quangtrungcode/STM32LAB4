/*
 * button.h
 *
 *  Created on: Nov 26, 2024
 *      Author: ADMIN
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

void getKeyInput();
int isButtonPressed(int index);
void subKeyProcess(int index);

#endif /* INC_BUTTON_H_ */
