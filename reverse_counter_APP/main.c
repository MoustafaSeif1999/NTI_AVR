/*
 * main.c
 *
 *  Created on: Oct 21, 2023
/* Author : Moustafa mohammed Mostafa 
 */

#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/DIO/DIO_interface.h"
#include "COTS/HAL/SevenSegment/SEVSEG_interface.h"
#include "avr/delay.h"

int main(){

	SEVSEG_voidInitialize();
	while(1){
		 for(u8 i=0;i<100;i++){
			 for(u8 j=0;j<40;j++){
				 SEVSEG_voidEnableSegment(SEVSEG_1);
				 SEVSEG_voidWriteNumber((99-i)/10);
				 _delay_ms(5);
				 SEVSEG_voidDisableSegment(SEVSEG_1);

				 SEVSEG_voidEnableSegment(SEVSEG_2);
				 SEVSEG_voidWriteNumber((99-i)%10);
				 _delay_ms(5);
				 SEVSEG_voidDisableSegment(SEVSEG_2);

				 SEVSEG_voidEnableSegment(SEVSEG_3);
				 SEVSEG_voidWriteNumber(i/10);
				 _delay_ms(5);
				 SEVSEG_voidDisableSegment(SEVSEG_3);

				 SEVSEG_voidEnableSegment(SEVSEG_4);
				 SEVSEG_voidWriteNumber(i%10);
				 _delay_ms(5);
				 SEVSEG_voidDisableSegment(SEVSEG_4);
			 }
			 _delay_ms(200);
		 }

		 for(u8 i=0;i<100;i++){
			 for(u8 j=0;j<40;j++){
				 SEVSEG_voidEnableSegment(SEVSEG_1);
				 SEVSEG_voidWriteNumber(i/10);
				 _delay_ms(5);
				 SEVSEG_voidDisableSegment(SEVSEG_1);

				 SEVSEG_voidEnableSegment(SEVSEG_2);
				 SEVSEG_voidWriteNumber(i%10);
				 _delay_ms(5);
				 SEVSEG_voidDisableSegment(SEVSEG_2);

				 SEVSEG_voidEnableSegment(SEVSEG_3);
				 SEVSEG_voidWriteNumber((99-i)/10);
				 _delay_ms(5);
				 SEVSEG_voidDisableSegment(SEVSEG_3);

				 SEVSEG_voidEnableSegment(SEVSEG_4);
				 SEVSEG_voidWriteNumber((99-i)%10);
				 _delay_ms(5);
				 SEVSEG_voidDisableSegment(SEVSEG_4);
			 }
			 _delay_ms(200);
		 }
	}
	return 0;
}