/*****************************************************************************/
/************************* Author : Moustafa mohammed Mostafa  **************/
/*********************** Date : 24/10/2023              **********************/
/*********************** Description : ACD program      **********************/
/*****************************************************************************/

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_Types.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_interface.h"

void (*ADC_GPfun)(void)=NULL;

void ADC_voidInitilize(){

	ADMUX->REFS = Voltage_source;
	ADMUX->ADLAR = ADC_Adjust_Result;

	ADCSRA->ADPS = PRE_SCALER;

	ADCSRA->ADATE = AUTO_TRIGGER_STATUS;
#if AUTO_TRIGGER_STATUS == AUTO_TRIGGER_ENABLE
	SFIOR->ADTS = Auto_Trigger_Source;
#endif

	ADCSRA->ADIE = ADC_INTERRUPT_STATUS;

	ADCSRA->ADEN = 1;
}

void ADC_voidSelectChannel(ADC_t Copy_ADCChannel){

	ADMUX->MUX = Copy_ADCChannel;
}

void ADC_voidStartConversion(){

	ADCSRA->ADSC = 1;
}

u16 ADC_u16ReadData(){

	while(ADCSRA->ADIF == 0);
	ADCSRA->ADIF = 1;

	return ADC;
}

void ADC_SetCallBack(void(*ptr)(void)){

	ADC_GPfun=ptr;
}

void __vector_16()__attribute__((signal));   // ADC
void __vector_16(){
	if(ADC_GPfun != NULL){
		ADC_GPfun();
	}
}
