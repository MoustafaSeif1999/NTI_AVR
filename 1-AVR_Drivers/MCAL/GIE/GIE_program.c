/**********************************************************************/
/************************* Author : Moustafa mohammed Mostafa  **************/
/*                    Date: 23/10/2023                                */
/*                    Description: GIE program                        */
/**********************************************************************/

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_Types.h"
#include "GIE_private.h"
#include "GIE_config.h"
#include "GIE_interface.h"

void GIE_voidEnable(){

	SET_BIT(SREG,I_BIT);
}
void GIE_voidDisable(){

	CLR_BIT(SREG,I_BIT);
}
