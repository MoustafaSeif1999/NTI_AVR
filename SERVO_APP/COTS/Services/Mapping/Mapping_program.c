/*************************************************************************/
/************************* Author : Moustafa mohammed Mostafa  **************/
/************************ Date : 24/10/2023               ****************/
/************************ Description : mapping program   ****************/
/*************************************************************************/

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_Types.h"
#include "Mapping_interface.h"

u32 Mapping_u16Map(u32 x,u32 x1,u32 x2,u32 y1,u32 y2){

	u32 y;

	y = (((u32)(x-x1)*(y2-y1))/(x2-x1))+y1;

	return y;
}
