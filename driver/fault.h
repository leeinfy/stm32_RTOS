/*
 * fault.h
 *
 *  Created on: May 2, 2024
 *      Author: Leein
 */

#ifndef FAULT_H_
#define FAULT_H_

#include <stdio.h>
#include <stdint.h>
#define SHCSR_ADDR	0xE000ED24U

void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);

void enable_system_fault(void);


#endif /* FAULT_H_ */
