/*
 * command_parser.c
 *
 *  Created on: Dec 5, 2024
 *      Author: Acer
 */

#include "global.h"
#include "command_parser.h"
#include <string.h>


static CommandParserState state = CMD_IDLE;

void command_parser_init(void) {
    state = CMD_IDLE;
}

void command_parser_fsm(void) {
    switch (state) {
        case CMD_IDLE:
            if (buffer[index_buffer] == '!') {

                state = CMD_EXCLAMATION;
            } else if (buffer[index_buffer] == '\r' || buffer[index_buffer] == '\n') {
                // Ignore newline characters in IDLE state
                state = CMD_IDLE;
            }
            break;

        case CMD_EXCLAMATION:
            if (buffer[index_buffer] == 'R') {
                state = CMD_R;
            } else if (buffer[index_buffer] == 'O') {
                state = CMD_O;
            } else {
                state = CMD_IDLE; // Reset on invalid input
            }
            break;

        case CMD_R:
            if (buffer[index_buffer] == 'S') {
                state = CMD_S;
            } else {
                state = CMD_IDLE; // Reset on invalid input
            }
            break;

        case CMD_S:
            if (buffer[index_buffer] == 'T') {
                state = CMD_T;
            } else {
                state = CMD_IDLE; // Reset on invalid input
            }
            break;

        case CMD_T:
            if (buffer[index_buffer] == '#') {
                state = CMD_HASTAG_T;

            } else {
                state = CMD_IDLE; // Reset on invalid input
            }
            break;

        case CMD_O:
            if (buffer[index_buffer] == 'K') {
                state = CMD_K;
            } else {
                state = CMD_IDLE; // Reset on invalid input
            }
            break;

        case CMD_K:
            if (buffer[index_buffer] == '#') {
                state = CMD_HASTAG_K;
            } else {
                state = CMD_IDLE; // Reset on invalid input
            }
            break;

        case CMD_HASTAG_T:
        	 if (buffer[index_buffer] == '\r' || buffer[index_buffer] == '\n') {
				state = CMD_IDLE; // Final reset
				index_buffer = 0;
				isRST = 1;
			}
			break;
        case CMD_HASTAG_K:
            if (buffer[index_buffer] == '\r' || buffer[index_buffer] == '\n') {
                state = CMD_IDLE; // Final reset
                index_buffer = 0;
                isOK = 1;
            }
            break;

        default:
            state = CMD_IDLE; // Catch-all for unexpected states
            break;
    }
}

