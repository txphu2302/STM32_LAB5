/*
 * uart_communication.h
 *
 *  Created on: Dec 5, 2024
 *      Author: Acer
 */

#ifndef INC_UART_COMMUNICATION_H_
#define INC_UART_COMMUNICATION_H_

#include <stdint.h>


typedef enum {
	UART_IDLE,
    UART_WAIT,
	UART_SEND_RESPONSE,
	UART_END,
	UART_FINAL

} UARTCommunicationState;


extern uint32_t ADC_value;

void uart_communication_init(void);
void uart_communication_fsm(void);

#endif /* INC_UART_COMMUNICATION_H_ */
