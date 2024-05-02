/*
 * fault.c
 *
 *  Created on: May 2, 2024
 *      Author: Leein
 */
#include "fault.h"

void HardFault_Handler(void){
	printf("Hard Fault\n");
	while(1);
}

void MemManage_Handler(void){
	printf("MemManage Fault\n");
	while(1);
}

void BusFault_Handler(void){
	printf("Bus Fault\n");
	while(1);
}

void enable_system_fault(void){
	uint32_t* pSHCSR = (uint32_t*) SHCSR_ADDR;
	*pSHCSR |= (0b111 << 16);
}


