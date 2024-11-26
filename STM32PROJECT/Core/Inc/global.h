/*
 * global.h
 *
 *  Created on: Nov 26, 2024
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

//#include "software_timer.h"
#include "button.h"
#include "main.h"
#include "traffic_light.h"
#include "led7_segment.h"
#include "fsm_automatic.h"
#include "fsm_manual.h"
#include "scheduler.h"
#define INIT 1
#define AUTO_RED1_GREEN2 2
#define AUTO_RED1_YELLOW2 3
#define AUTO_GREEN1_RED2 4
#define AUTO_YELLOW1_RED2 5

#define MAN_RED 12
#define MAN_GREEN 13
#define MAN_YELLOW 14
#define INCREASE_VALUE_LED_RED 15
#define SET_VALUE_LED_RED 16
#define SAVE_VALUE_LED_RED 17
#define INCREASE_VALUE_LED_GREEN 18
#define SET_VALUE_LED_GREEN 19
#define INCREASE_VALUE_LED_YELLOW 20
#define SET_VALUE_LED_YELLOW 21
#define CHECK_TIME 22
extern int status;
extern int before;
extern int after;
void status_transition_AUTO_RED1_GREEN2();

void status_transition_AUTO_RED1_YELLOW2();

void status_transition_AUTO_GREEN1_RED2();

void status_transition_AUTO_YELLOW1_RED2();
#endif /* INC_GLOBAL_H_ */
