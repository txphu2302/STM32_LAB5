/*
 * software_timer.h
 *
 *  Created on: Dec 5, 2024
 *      Author: Acer
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer_flag;
extern int TIMER_CYCLE;

void setTimer(int duration);

void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
