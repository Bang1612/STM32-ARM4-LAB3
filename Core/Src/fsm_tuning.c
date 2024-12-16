/*
 * fsm_tuning.c
 *
 *  Created on: Dec 6, 2022
 *      Author: Admin
 */


#include "fsm_tuning.h"


int status= 0;
int light_freq=0;
int temp;
void fsm_tuning_run(){
	switch (status) {
	case MODIFICATION_RED:
//		int valRED = RED_TIME;
//		lcd_Clear(WHITE);
		lcd_DrawRectangle(10, 40, 59, 239, BLACK);
		lcd_DrawRectangle(180, 40, 229, 239, BLACK);
		if (light_freq) lcd_DrawCircle(35, 65, RED, 5, 1);
		else lcd_DrawCircle(35, 65, GRAY, 5, 1);
		lcd_DrawCircle(35, 90, GRAY, 5, 1);
		lcd_DrawCircle(35, 115, GRAY, 5, 1);


		if (light_freq) lcd_DrawCircle(205, 65, RED, 5, 1);
		else lcd_DrawCircle(205, 65, GRAY, 5, 1);
		lcd_DrawCircle(205, 90, GRAY, 5, 1);
		lcd_DrawCircle(205, 115, GRAY, 5, 1);
		lcd_StrCenter(10, 15, "MODIFICATION RED", RED, BLUE, 16, 0);


		if (button_count[1] == 1) {
			temp++;
			if (temp > 99)
				temp = 1;
		}
		if (button_count[2] == 1) {
			RED_TIME = temp;
		}
		lcd_ShowIntNum(120, 60, temp, 2, RED, WHITE, 16);
		break;
	case MODIFICATION_YELLOW:
//		int valYEL = YELLOW_TIME;
//		lcd_Clear(WHITE);
		lcd_DrawRectangle(10, 40, 59, 239, BLACK);
		lcd_DrawRectangle(180, 40, 229, 239, BLACK);
		lcd_DrawCircle(35, 65, GRAY, 5, 1);
		if (light_freq) lcd_DrawCircle(35, 90, YELLOW, 5, 1);
		else lcd_DrawCircle(35, 90, GRAY, 5, 1);
		lcd_DrawCircle(35, 115, GRAY, 5, 1);

		lcd_DrawCircle(205, 65, GRAY, 5, 1);
		if (light_freq) lcd_DrawCircle(205, 90, YELLOW, 5, 1);
		else lcd_DrawCircle(205, 90, GRAY, 5, 1);
		lcd_DrawCircle(205, 115, GRAY, 5, 1);
		lcd_StrCenter(10, 15, "MODIFICATION YELLOW", RED, BLUE, 16, 0);


		if (button_count[1] == 1) {
			temp++;
			if (temp > 99)
				temp = 1;
		}
		if (button_count[2] == 1) {
			YELLOW_TIME = temp;
		}
		lcd_ShowIntNum(120, 60, temp, 2, YELLOW, BLACK, 16);
		break;
	case MODIFICATION_GREEN:
//		int valGRE = GREEN_TIME;
//		lcd_Clear(WHITE);
		lcd_DrawRectangle(10, 40, 59, 239, BLACK);
		lcd_DrawRectangle(180, 40, 229, 239, BLACK);
		lcd_DrawCircle(35, 65, GRAY, 5, 1);
		lcd_DrawCircle(35, 90, GRAY, 5, 1);
		if (light_freq) lcd_DrawCircle(35, 115, GREEN, 5, 1);
		else lcd_DrawCircle(35, 115, GRAY, 5, 1);

		lcd_DrawCircle(205, 65, GRAY, 5, 1);
		lcd_DrawCircle(205, 90, GRAY, 5, 1);
		if (light_freq) lcd_DrawCircle(205, 115, GREEN, 5, 1);
		else lcd_DrawCircle(205, 115, GRAY, 5, 1);
		lcd_StrCenter(10, 15, "MODIFICATION GREEN", RED, BLUE, 16, 0);

		if (button_count[1] == 1) {
			temp++;
			if (temp > 99)
				temp = 1;
		}
		if (button_count[2] == 1) {
			GREEN_TIME = temp;
		}
		lcd_ShowIntNum(120, 60, temp, 2, GREEN, BLACK, 16);

		break;
	case NORMAL:
		if(RED_TIME != GREEN_TIME + YELLOW_TIME){
			RED_TIME=5;
			GREEN_TIME=3;
			YELLOW_TIME=2;
		}
//		fsm_auto_run();
		break;


		default:
			break;

	}
}
