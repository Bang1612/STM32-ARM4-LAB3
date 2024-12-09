/*
 * fsm_tuning.c
 *
 *  Created on: Dec 6, 2022
 *      Author: Admin
 */


#include "fsm_tuning.h"


int status= 0;
int light_freq=0;
void fsm_tuning_run(){
	switch (status) {
	case MODIFICATION_RED:
		int valRED = RED_TIME;
		lcd_Clear(WHITE);
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
		lcd_StrCenter(119, 15, "MODIFICATION RED", RED, BLUE, 12, 0);
		lcd_ShowIntNum(120, 60, valRED, 2, RED, WHITE, 16);

		if (button_count[1] != 0) {
			valRED++;
			if (valRED > 99)
				valRED = 1;
		}
		if (button_count[2] != 0) {
			RED_TIME = valRED;
		}
		break;
	case MODIFICATION_YELLOW:
		int valYEL = YELLOW_TIME;
		lcd_Clear(WHITE);
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
		lcd_StrCenter(119, 15, "MODIFICATION YELLOW", YELLOW, BLUE, 12, 0);
		lcd_ShowIntNum(120, 60, valYEL, 2, YELLOW, WHITE, 16);

		if (button_count[0] != 0) {
			valYEL++;
			if (valYEL > 99)
				valYEL = 1;
		}
		if (button_count[2] != 0) {
			YELLOW_TIME = valYEL;
		}
		break;
	case MODIFICATION_GREEN:
		int valGRE = GREEN_TIME;
		lcd_Clear(WHITE);
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
		lcd_StrCenter(119, 15, "MODIFICATION GREEN", GREEN, BLUE, 12, 0);
		lcd_ShowIntNum(120, 60, valGRE, 2, GREEN, WHITE, 16);

		if (button_count[1] != 0) {
			valGRE++;
			if (valGRE > 99)
				valGRE = 1;
		}
		if (button_count[2] != 0) {
			GREEN_TIME = valGRE;
		}
		break;
	case NORMAL:
		if(RED_TIME != GREEN_TIME + YELLOW_TIME){
			RED_TIME=5;
			GREEN_TIME=3;
			YELLOW_TIME=2;
		}
		fsm_auto_run();
		break;


		default:
			break;

	}
}
