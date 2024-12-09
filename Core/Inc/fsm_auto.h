/*
 * fsm_auto.h
 *
 *  Created on: Dec 6, 2022
 *      Author: Admin
 */

#ifndef INC_FSM_AUTO_H_
#define INC_FSM_AUTO_H_

//#include "global.h"
//#include "led_traffic.h"
#include "software_timer.h"
#include "lcd.h"
//#include "main.h"

extern int light_status;
//extern uint16_t status;
//extern uint16_t light_status;
extern int RED_TIME ;
extern int YELLOW_TIME ;
extern int GREEN_TIME ;

//green_duration
#define RED_GREEN 0
//yellow duration
#define RED_YELLOW 1
//green duration
#define GREEN_RED 2
//yellow duration
#define YELLOW_RED 3

void fsm_auto_run();
void TrafficLightInit();

#endif /* INC_FSM_AUTO_H_ */
