/*
 * PIB_led_code.c
 *
 * Created: 21-2-2023 15:11:47
 * Author : Johan
 */


#define F_CPU 16000000UL

#define	BUILD_FOR_AT90CAN	1
#define	SUPPORT_EXTENDED_CANID	1


#include <avr/io.h>
#include <stdint.h>


#include "at90can_private.h"
#include "config.h"
#include "can_private.h"
#include "can.h"
#include "utils.h"
#include "can_buffer.h"


int main(void)
{
   DDRC = 0xFF;
   
   at90can_init(4); 
   at90can_set_mode(NORMAL_MODE); 
    
   while (1) {
	   
	   uint8_t receivedMessage = at90can_check_message();
	   if (receivedMessage == true) {
		   DDRC = 1;
		   } else {
		   DDRC = 0;
		   }
   } 

}