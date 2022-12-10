#ifndef IR_INTERFACE_H
#define IR_INTERFACE_H

#include "STD_TYPES.hpp"
#include "GPIO_interface.hpp"
#include "EXTI_interface.hpp"

//()

class IR : public GPIO_CONFIG_t , public EXTI_Def_t
{
	private :
		
		u8 Data_u8 = 0;
	public :
		
		IR(PORT Copy_enumPortID, PIN Copy_enumPin);	
		void IR_voidInit(void);
		void IR_voidSave_Data(void);
		u8 IR_voidGET_Data(void);
	
};




#endif
