/*
 * main.c
 *
 *  Created on: Oct 21, 2023
/** Author : Moustafa mohammed Mostafa  */
 */
#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/DIO/DIO_interface.h"
#include "COTS/HAL/SevenSegment/SEVSEG_interface.h"
#include "avr/delay.h"

int main(){

	DIO_voidSetPinDirection(PORTB,PIN7,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN4,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN5,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN6,PIN_OUTPUT);

	SEVSEG_voidInitialize();
	SEVSEG_voidEnableSegment(SEVSEG_4);

	while(1){
		for(u8 i=0;i<10;i++){
			SEVSEG_voidWriteNumber(i);

			DIO_voidSetPinValue(PORTB,PIN7,GET_BIT(i,0));
			DIO_voidSetPinValue(PORTA,PIN4,GET_BIT(i,1));
			DIO_voidSetPinValue(PORTA,PIN5,GET_BIT(i,2));
			DIO_voidSetPinValue(PORTA,PIN6,GET_BIT(i,3));

			_delay_ms(500);
		}
	}

	return 0;
}
