/*************************************************************************/
/************************* Author : Moustafa mohammed Mostafa  **************/
/************************ Date : 24/10/2023               ****************/
/************************ Date : 24/10/2023               ****************/
/************************ Description : mapping program   ****************/
/*************************************************************************/

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_Types.h"
#include "Mapping_interface.h"

u16 Mapping_u16Map(u16 x,u16 x1,u16 x2,u16 y1,u16 y2){

	u16 y;

	y = ((u32)((x-x1)*(y2-y1))/(x2-x1))+y1;

	return y;
}
