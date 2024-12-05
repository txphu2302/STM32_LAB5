/*
 * command_parser.h
 *
 *  Created on: Dec 5, 2024
 *      Author: Acer
 */

#ifndef INC_COMMAND_PARSER_H_
#define INC_COMMAND_PARSER_H_

#include <stdint.h>


typedef enum {
    CMD_IDLE,
	CMD_EXCLAMATION,
	CMD_R,
	CMD_O,
	CMD_S,
	CMD_T,
	CMD_HASTAG_T,
	CMD_K,
	CMD_HASTAG_K
} CommandParserState;



void command_parser_init(void);
void command_parser_fsm(void);

#endif /* INC_COMMAND_PARSER_H_ */
