/*
 * main.c
 *
 *  Created on: Oct 25, 2023
/** Author : Moustafa mohammed Mostafa */
 */

#include "COTS/LIB/Bit_Math.h"
#include "COTS/LIB/STD_Types.h"
#include "COTS/MCAL/ADC/ADC_interface.h"
#include "COTS/HAL/LCD/LCD_interface.h"
#include "COTS/HAL/LM35/LM35_interface.h"
#include "COTS/Services/Mapping/Mapping_interface.h"
#include "avr/delay.h"

int main(){

	ADC_voidInitilize();
	ADC_voidSelectChannel(ADC0);

	LCD_voidInitialize();
	//LM35_voidInitialize(LM35_ADC0);

	u16 ADC_data,temp,light;

	while(1){

		ADC_voidStartConversion();
		ADC_data = ADC_u16ReadData();

		//temp = LM_35_u16GetTemperature();

		light = (u16)(((u32)ADC_data*5000*2)/(1023));

		LCD_voidClearDisplay();
		LCD_voidWriteNumber(light);

		_delay_ms(50);
	}

	return 0;
}
