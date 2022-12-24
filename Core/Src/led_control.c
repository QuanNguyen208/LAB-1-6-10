/*
 * led_control.c
 *
 *  Created on: Nov 10, 2022
 *      Author: Admin
 */

#include "main.h"
#include "led_control.h"

uint8_t ledB[7] = {B1_Pin, B2_Pin, B3_Pin, B4_Pin, B5_Pin, B6_Pin, B7_Pin};
uint8_t ledA[5] = {A1_Pin, A2_Pin, A3_Pin, A4_Pin, A5_Pin};

void setAllClock() {
	// run all the LEDs at high Frequency
	for (int i = 0; i < 12; i++){
		setNumberOnClock(i);
		HAL_Delay(1);
	}
}
void clearAllClock(){
	for (int i = 0; i < 7; i++){
		HAL_GPIO_WritePin(GPIOB, ledB[i], 1);
	}
	for (int i = 0; i < 5; i++){
		HAL_GPIO_WritePin(GPIOA, ledA[i], 0);
	}
}

void setNumberOnClock(int num){
	if (num < 12) {
		// set up by turn off all
		clearAllClock();

		// turn on the appropriate LED
		if (num == 0 || num == 1 || num == 2){
			HAL_GPIO_WritePin(GPIOB, ledB[0], 0);
			HAL_GPIO_WritePin(GPIOA, ledA[num + 1], 1);
		}
		if (num == 3 || num == 4 || num == 5){
			HAL_GPIO_WritePin(GPIOA, ledA[4], 1);
			HAL_GPIO_WritePin(GPIOB, ledB[num - 1], 0);
		}
		if (num == 6 || num == 7 || num == 8){
			HAL_GPIO_WritePin(GPIOB, ledB[6], 0);
			HAL_GPIO_WritePin(GPIOA, ledA[9 - num], 1);
		}
		if (num == 9 || num == 10 || num == 11){
			HAL_GPIO_WritePin(GPIOA, ledA[0], 1);
			HAL_GPIO_WritePin(GPIOB, ledB[13 - num], 0);
		}
	}
}

void clearNumberOnClock(int num){
	if (num < 12) {
		if (num == 0 || num == 1 || num == 2){
			HAL_GPIO_WritePin(GPIOA, ledA[num + 1], 0);
		}
		if (num == 3 || num == 4 || num == 5){
			HAL_GPIO_WritePin(GPIOA, ledA[4], 1);
		}
		if (num == 6 || num == 7 || num == 8){
			HAL_GPIO_WritePin(GPIOA, ledA[9 - num], 0);
		}
		if (num == 9 || num == 10 || num == 11){
			HAL_GPIO_WritePin(GPIOA, ledA[0], 1);
		}
	}
}
