/*
 * led7_segment.h
 *
 *  Created on: Nov 26, 2024
 *      Author: ADMIN
 */

#ifndef INC_LED7_SEGMENT_H_
#define INC_LED7_SEGMENT_H_

#include "main.h"

extern int index_led02;
extern int index_led13;
extern int counterred02;
extern int counteryellow02;
extern int countergreen02;
extern int counterred13;
extern int counteryellow13;
extern int countergreen13;
extern int savecounterred13;
extern int savecountergreen13;
extern int savecounteryellow13;
extern int a;
extern int b;
extern int c;
extern int idx_led13;
extern int idx_led02;
extern int counterred;
extern int countergreen;
extern int counteryellow;
extern int checkcounterred;
extern int checkcountergreen;
extern int checkcounteryellow;
//extern int checkcountergreen;
void set_led7_segement();
void display7SEGX(int num);
void display7SEGY(int num);
//void led7_segment_run13(int d);
void led7_segment_run13();
void led7_segment_run02();
void Save_led7RED_segment_run02();
void Save_led7GREEN_segment_run02();
void Save_led7YELLOW_segment_run02();
void Save_led7RED_segment_run13();
void Save_led7GREEN_segment_run13();
void Save_led7YELLOW_segment_run13();
void Increase_Save_led7RED_segment_run13();
void Increase_Save_led7GREEN_segment_run13();
void Increase_Save_led7YELLOW_segment_run13();
void LED_RED_TEST();
void LED_GREEN_TEST();
void LED_YELLOW_TEST();
#endif /* INC_LED7_SEGMENT_H_ */
