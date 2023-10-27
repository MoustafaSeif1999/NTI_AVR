/*
 * main.c
 *
 *  Created on: Oct 21, 2023
/* Author : Moustafa mohammed Mostafa  
 */

#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/DIO/DIO_interface.h"
#include "COTS/HAL/LCD/LCD_interface.h"
#include "avr/delay.h"

int main(){

	LCD_voidInitialize();

	LCD_voidGoToXY(0,0);
	LCD_voidWriteString((u8*)"Mostafa Mahmoud");
	LCD_voidGoToXY(1,7);
	LCD_voidWriteString((u8*)"Salem");
	LCD_voidGoToXY(2,6);
	LCD_voidWriteNumber(23);
	LCD_voidWriteString((u8*)" years old");
	LCD_voidGoToXY(3,6);
	LCD_voidWriteString((u8*)"Engineer!!");
	while(1){

	}
	return 0;
}
