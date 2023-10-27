/**********************************************************************/
/************************* Author : Moustafa mohammed Mostafa  **************/
/*                    Date: 20/10/2023                                */
/*                    Description: seven segment program              */
/**********************************************************************/

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "SEVSEG_private.h"
#include "SEVSEG_config.h"
#include "SEVSEG_interface.h"

void SEVSEG_voidInitialize(){
	DIO_voidSetPinDirection(SEVSEG_PORT,SEVSEG_PIN_A,PIN_OUTPUT);
	DIO_voidSetPinDirection(SEVSEG_PORT,SEVSEG_PIN_B,PIN_OUTPUT);
	DIO_voidSetPinDirection(SEVSEG_PORT,SEVSEG_PIN_C,PIN_OUTPUT);
	DIO_voidSetPinDirection(SEVSEG_PORT,SEVSEG_PIN_D,PIN_OUTPUT);

	DIO_voidSetPinDirection(SEVSEG_1_EN_PORT,SEVSEG_1_EN_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(SEVSEG_2_EN_PORT,SEVSEG_2_EN_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(SEVSEG_3_EN_PORT,SEVSEG_3_EN_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(SEVSEG_4_EN_PORT,SEVSEG_4_EN_PIN,PIN_OUTPUT);

	DIO_voidSetPinValue(SEVSEG_1_EN_PORT,SEVSEG_1_EN_PIN,PIN_HIGH);
	DIO_voidSetPinValue(SEVSEG_2_EN_PORT,SEVSEG_2_EN_PIN,PIN_HIGH);
	DIO_voidSetPinValue(SEVSEG_3_EN_PORT,SEVSEG_3_EN_PIN,PIN_HIGH);
	DIO_voidSetPinValue(SEVSEG_4_EN_PORT,SEVSEG_4_EN_PIN,PIN_HIGH);
}

void SEVSEG_voidEnableSegment(u8 Copy_u8SegmentNum){
	switch(Copy_u8SegmentNum){
	case SEVSEG_1:
		DIO_voidSetPinValue(SEVSEG_1_EN_PORT,SEVSEG_1_EN_PIN,PIN_LOW);
		break;
	case SEVSEG_2:
		DIO_voidSetPinValue(SEVSEG_2_EN_PORT,SEVSEG_2_EN_PIN,PIN_LOW);
		break;
	case SEVSEG_3:
		DIO_voidSetPinValue(SEVSEG_3_EN_PORT,SEVSEG_3_EN_PIN,PIN_LOW);
		break;
	case SEVSEG_4:
		DIO_voidSetPinValue(SEVSEG_4_EN_PORT,SEVSEG_4_EN_PIN,PIN_LOW);
		break;
	}

}

void SEVSEG_voidDisableSegment(u8 Copy_u8SegmentNum){
	switch(Copy_u8SegmentNum){
	case SEVSEG_1:
		DIO_voidSetPinValue(SEVSEG_1_EN_PORT,SEVSEG_1_EN_PIN,PIN_HIGH);
		break;
	case SEVSEG_2:
		DIO_voidSetPinValue(SEVSEG_2_EN_PORT,SEVSEG_2_EN_PIN,PIN_HIGH);
		break;
	case SEVSEG_3:
		DIO_voidSetPinValue(SEVSEG_3_EN_PORT,SEVSEG_3_EN_PIN,PIN_HIGH);
		break;
	case SEVSEG_4:
		DIO_voidSetPinValue(SEVSEG_4_EN_PORT,SEVSEG_4_EN_PIN,PIN_HIGH);
		break;
	}

}

void SEVSEG_voidWriteNumber(u8 Copy_u8Number){
	DIO_voidSetPinValue(SEVSEG_PORT,SEVSEG_PIN_A,GET_BIT(Copy_u8Number,0));
	DIO_voidSetPinValue(SEVSEG_PORT,SEVSEG_PIN_B,GET_BIT(Copy_u8Number,1));
	DIO_voidSetPinValue(SEVSEG_PORT,SEVSEG_PIN_C,GET_BIT(Copy_u8Number,2));
	DIO_voidSetPinValue(SEVSEG_PORT,SEVSEG_PIN_D,GET_BIT(Copy_u8Number,3));
}
