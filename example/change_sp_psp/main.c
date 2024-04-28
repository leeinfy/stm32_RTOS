/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdio.h>
#include <stdint.h>
#include "itm_send_data.h"

#define SRAM_START_ADDR 	0x20000000u
#define SRAM_SIZE  			(128*1024)
#define SRAM_END_ADDR   	(SRAM_START + SRAM_SIZE)

#define STACK_MSP_SIZE				512

//ARM use full descending stack mode
#define STACK_START_ADDR			SRAM_END
#define STACK_MSP_START_ADDR		STACK_START_ADDR
#define STACK_MSP_END_ADDR			(STACK_START_ADDR - STACK_MSP_SIZE)
#define STACK_PSP_START_ADDR		STACK_MSP_END_ADDR

void delay(void){
	for(uint32_t i=0; i<500000; i++);
}

__attribute__((naked)) void change_to_psp(void){
	//load the stack psp start address to psp register
	__asm volatile(".equ psp_start, (0x20000000 + (128*1024) - 512)");
	__asm volatile("LDR R0, =psp_start");
	__asm volatile("MSR	PSP, R0");
	//change the SPSEL bit field of control register
	__asm volatile("MOV R0, #0x02");
	__asm volatile("MSR CONTROL, R0");
	__asm volatile("BX LR");
}

int main(void){
	//observe the change of sp from msp to psp
	change_to_psp();

    /* Loop forever */
	while(1){
	}
}