/**********************************************************************/
/************************* Author : Moustafa mohammed Mostafa  **************/
/*                    Date: 23/10/2023                                */
/*                    Description: EXTI interface                     */
/**********************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

typedef enum{
	EXTI_0,
	EXTI_1,
	EXTI_2
}EXTI_t;

typedef enum{
	LOW_LEVEL_SENSE,
	LOGICL_CHANGE_SENSE,
	FALLING_EDGE_SENSE,
	RISING_EDGE_SENSE
}SENSE_t;

void EXTI_voidEnable(EXTI_t Copy_EXTILine);
void EXTI_voidDisable(EXTI_t Copy_EXTILine);
void EXTI_voidSetSenseCase(EXTI_t Copy_EXTILine,SENSE_t Copy_SenseCase);
u8 EXTI_u8GetInterruptFlag(EXTI_t Copy_EXTILine);
void EXTI_voidClearInterruptFlag(EXTI_t Copy_EXTILine);
void EXTI_voidSetInterruptFlag(EXTI_t Copy_EXTILine);
void EXTI_SetCallBack(EXTI_t Copy_EXTILine,void(*ptr)(void));

#endif // EXTI_INTERFACE_H
