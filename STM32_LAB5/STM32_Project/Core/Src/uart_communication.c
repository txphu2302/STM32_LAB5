/*
 * uart_communication.c
 *
 *  Created on: Dec 5, 2024
 *      Author: Acer
 */

#include "uart_communication.h"
#include "command_parser.h"
#include "main.h"
#include "stdio.h"
#include "string.h"
#include "software_timer.h"
#include "global.h"

static UARTCommunicationState state = UART_WAIT;

void uart_communication_init(void) {
    state = UART_WAIT;
}

uint32_t ADC_value = 0;

void uart_communication_fsm(void) {
    char response[20];  // Declare the variable before the switch statement

    switch (state) {
    	case UART_WAIT:
    		if (isRST)
    		{
    			HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
    			state = UART_IDLE;
    			isRST = 0;
    		}
    		break;

        case UART_IDLE:
        	state = UART_SEND_RESPONSE;
            break;

        case UART_SEND_RESPONSE:
        	ADC_value = HAL_ADC_GetValue(&hadc1);
        	sprintf(response, "!ADC%ld#\r", ADC_value);
        	HAL_UART_Transmit(&huart2, (uint8_t *)response, strlen(response), 1000);
        	setTimer(3000);
            state = UART_END;
            break;

        case UART_END:
        	if(timer_flag == 1)
        		state = UART_FINAL;
        	break;

        case UART_FINAL:
        	if(isOK){
				sprintf(response, "END RST\r\n");
				HAL_UART_Transmit(&huart2, (void *)response, strlen(response), 1000);
				state = UART_WAIT;
				isOK = 0;
        	}
            break;
    }
}





