#include"STD_TYPES.h"
#include"BitMath.h"
#include"GIE_Private.h"
#Include"GIE_Interface.h"
#include"GIE_Config.h"


void GIE_voidGlobalEnable()
{
	set_bit(STATUS_REG,GIE_INTERRUPT);
}

void GIE_voidGlobalDisable()
{
	clear_bit(STATUS_REG,GIE_INTERRUPT);
}
