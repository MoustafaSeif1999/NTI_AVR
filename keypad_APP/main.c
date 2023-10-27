/*
 * main.c
 *
 *  Created on: Oct 22, 2023
/* Author : Moustafa mohammed Mostafa
 */
#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/DIO/DIO_interface.h"
#include "COTS/HAL/LCD/LCD_interface.h"
#include "COTS/HAL/KeyPad/KeyPad_interface.h"

int main(){

	KeyPad_voidInitialize();
	LCD_voidInitialize();
	u8 op1,op2,opr,res,flag=0;

	u8 data;

	while(1){

		data = KeyPad_u8GetPressedKey();

		if(data != 0xFF){

			LCD_voidWriteData(data);

			switch(data){
			case '+':
			case '-':
			case '*':
			case '/':
				opr = data;
				break;
			case '=':
				switch(opr){
				case '+':
					res = op1+op2;
					break;
				case '-':
					res = op1-op2;
					break;
				case '*':
					res = op1*op2;
					break;
				case '/':
					res = op1/op2;
					break;
				}
				LCD_voidWriteNumber(res);
				break;
			case '#':
				LCD_voidClearDisplay();
				break;
			default:
				if(!flag){
					op1 = (data - '0');
					flag = 1;
				}else{
					op2 = (data - '0');
					flag = 0;
				}
			}

		}
	}

	return 0;
}

