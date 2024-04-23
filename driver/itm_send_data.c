/*
 * itm_send_data.h
 *
 *  Created on: Apr 22, 2024
 *      Author: Leein
 */
#include "itm_send_data.h"

void ITM_Init(){
	//enable DWT & ITM block
	DEMCR |= (1 << 24);

	//enable ITM port 0
	ITM_TER |= (1 << 0);
}

//send char via cortex ITM
void ITM_SendChar(uint8_t chr){


	while(!(ITM_STIMULUS_PORT0 & 1));

	ITM_STIMULUS_PORT0 = chr;
}
