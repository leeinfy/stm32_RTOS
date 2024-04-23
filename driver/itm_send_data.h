/*
 * itm_send_data.h
 *
 *  Created on: Apr 22, 2024
 *      Author: Leein
 */

#ifndef ITM_SEND_DATA_H_
#define ITM_SEND_DATA_H_
#include <stdint.h>

#define ITM_STIMULUS_PORT_BASE_ADDR			0xE0000000u
#define ITM_STIMULUS_PORT_OFFSET			0X04


#define	ITM_STIMULUS_PORT0					(*(volatile uint32_t*)ITM_STIMULUS_PORT_BASE_ADDR)
#define ITM_TER								(*(volatile uint32_t*)0xE0000E00u)
#define DEMCR 								(*(volatile uint32_t*)0xE000EDFCu)

void ITM_Init();
void ITM_SendChar(uint8_t chr);

#endif /* ITM_SEND_DATA_H_ */
