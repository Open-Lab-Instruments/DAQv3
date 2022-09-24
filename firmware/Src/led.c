/*
 *******************************************************************************
 * File:			led.c
 * Date:			2022-04-09
 * Author:			Phillip Durdaut
 * Summary:			Functions for controlling the front LEDs
 * Notes:			-
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "led.h"

/* Private typedefs ----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Program code --------------------------------------------------------------*/

extern void LED_Init(void)
{
	/* Configure GPIO pins */
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	GPIO_InitStruct.Pin = LED_1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(LED_1_Port, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LED_2_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(LED_2_Port, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LED_3_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(LED_3_Port, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LED_4_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(LED_4_Port, &GPIO_InitStruct);

	/* Set standard voltage levels of output pins */
	HAL_GPIO_WritePin(LED_1_Port, LED_1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_2_Port, LED_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_3_Port, LED_3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_4_Port, LED_4_Pin, GPIO_PIN_RESET);
}

extern void LED_On(LED_t led)
{
	switch (led)
	{
		case LED_1:
			HAL_GPIO_WritePin(LED_1_Port, LED_1_Pin, GPIO_PIN_SET);
			break;
		case LED_2:
			HAL_GPIO_WritePin(LED_2_Port, LED_2_Pin, GPIO_PIN_SET);
			break;
		case LED_3:
			HAL_GPIO_WritePin(LED_3_Port, LED_3_Pin, GPIO_PIN_SET);
			break;
		case LED_4:
			HAL_GPIO_WritePin(LED_4_Port, LED_4_Pin, GPIO_PIN_SET);
			break;
	}
}

extern void LED_Off(LED_t led)
{
	switch (led)
	{
		case LED_1:
			HAL_GPIO_WritePin(LED_1_Port, LED_1_Pin, GPIO_PIN_RESET);
			break;
		case LED_2:
			HAL_GPIO_WritePin(LED_2_Port, LED_2_Pin, GPIO_PIN_RESET);
			break;
		case LED_3:
			HAL_GPIO_WritePin(LED_3_Port, LED_3_Pin, GPIO_PIN_RESET);
			break;
		case LED_4:
			HAL_GPIO_WritePin(LED_4_Port, LED_4_Pin, GPIO_PIN_RESET);
			break;
	}
}

extern void LED_Toggle(LED_t led)
{
	switch (led)
	{
		case LED_1:
			HAL_GPIO_TogglePin(LED_1_Port, LED_1_Pin);
			break;
		case LED_2:
			HAL_GPIO_TogglePin(LED_2_Port, LED_2_Pin);
			break;
		case LED_3:
			HAL_GPIO_TogglePin(LED_3_Port, LED_3_Pin);
			break;
		case LED_4:
			HAL_GPIO_TogglePin(LED_4_Port, LED_4_Pin);
			break;
	}
}
