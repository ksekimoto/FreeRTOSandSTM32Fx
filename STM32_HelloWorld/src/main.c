/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include <stdio.h>
#include "stm32f4xx.h"

#include "FreeRTOS.h"
#include "task.h"

TaskHandle_t xTaskHandle1 = NULL;
TaskHandle_t xTaskHandle2 = NULL;

// Task function prototype
void vTask1_handler(void *params);
void vTask2_handler(void *params);

// used for semihosting
extern void initialise_monitor_handles();

int main(void)
{
	initialise_monitor_handles();

	printf("This is hello world example program.\n");

	// 1. Reset RCC clock configuration to default reset state
	// HCI ON, PLL OFF, system clock = 16MHz, cpu clock = 16MHz
	RCC_DeInit();

	// 2. update the SystemCoreClock variable
	SystemCoreClockUpdate();

	// 3. let's create two tasks
	xTaskCreate(vTask1_handler, "Task-1", configMINIMAL_STACK_SIZE, NULL, 2, &xTaskHandle1);
	xTaskCreate(vTask2_handler, "Task-2", configMINIMAL_STACK_SIZE, NULL, 2, &xTaskHandle2);

	// 4. Start the scheduler
	vTaskStartScheduler();

	for(;;);
}

void vTask1_handler(void *params)
{
	while (1)
	{
		printf("Hello World: From Task-1\n");
	}
}

void vTask2_handler(void *params)
{
	while (1)
	{
		printf("Hello World: From Task-2\n");
	}

}
