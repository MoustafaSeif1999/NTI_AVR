/********************************************************************/
/************************* Author : Moustafa mohammed Mostafa  **************/
/******************** Date  : 25/10/2023            *****************/
/******************** Description : LMC35 program   *****************/
/********************************************************************/

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/ADC/ADC_interface.h"
#include "../../Services/Mapping/Mapping_interface.h"
#include "LM35_private.h"
#include "LM35_config.h"
#include "LM35_interface.h"

void LM35_voidInitialize(LM35_ADC_t Copy_ADCChannel){

	ADC_voidInitilize();
	ADC_voidSelectChannel(Copy_ADCChannel);

	DIO_voidSetPinDirection(PORTA,Copy_ADCChannel,PIN_INPUT);
}

u16 LM_35_u16GetTemperature(){

	u16 Local_u16ADCData,Local_u16Temperature;

	ADC_voidStartConversion();

	Local_u16ADCData = ADC_u16ReadData();
	Local_u16Temperature = Mapping_u16Map(Local_u16ADCData,ADC_LOWER_LIMIT,ADC_UPPER_LIMIT,LM35_LOWER_LIMIT,LM35_UPPER_LIMIT);

	return Local_u16Temperature;
}
