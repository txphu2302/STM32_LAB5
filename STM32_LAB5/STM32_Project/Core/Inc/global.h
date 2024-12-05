/*
 * global.h
 *
 *  Created on: Dec 5, 2024
 *      Author: Acer
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"

#define MAX_BUFFER_SIZE 30

extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t buffer_flag;
extern uint8_t index_buffer;

extern int isOK;
extern int isRST;

#endif /* INC_GLOBAL_H_ */
