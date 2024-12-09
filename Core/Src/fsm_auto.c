/*
 * fsm_auto.c
 *
 *  Created on: Dec 6, 2022
 *      Author: Admin
 */


#include "fsm_auto.h"

int light_status = 0;
int RED_TIME = 5;
int GREEN_TIME = 3;
int YELLOW_TIME = 2;
void TrafficLightInit(){
	int light_status = 0;
	int RED_TIME = 5;
	int GREEN_TIME = 3;
	int YELLOW_TIME = 2;
}

void fsm_auto_run(){

	switch (light_status){
	case RED_GREEN:
		lcd_TrafficLight(0, RED);
		lcd_TrafficLight(1, GREEN);
		setTimer2(GREEN_TIME * 1000);
		break;
	case RED_YELLOW:
		lcd_TrafficLight(0, RED);
		lcd_TrafficLight(1, YELLOW);
		setTimer2(YELLOW_TIME * 1000);
		break;
	case GREEN_RED:
		lcd_TrafficLight(0, GREEN);
		lcd_TrafficLight(1, RED);
		setTimer2(GREEN_TIME * 1000);
		break;
	case YELLOW_RED:
		lcd_TrafficLight(0, YELLOW);
		lcd_TrafficLight(1, RED);
		setTimer2(YELLOW_TIME * 1000);
		break;
	default:
		break;
	}
}
