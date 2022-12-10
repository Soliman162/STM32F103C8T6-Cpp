#ifndef IR_INFRARED_INTERFACE_HPP
#define IR_INFRARED_INTERFACE_HPP

#include "STD_TYPES.hpp"
#include "GPIO_interface.hpp"

enum EXISTENCE : u8
{
	EXIST = GPIO_LOW,
	NOT_EXIST = GPIO_HIGH
};

class IR_INFRARED : public GPIO_CONFIG_t
{
	public :
		IR_INFRARED(PORT Copy_enumPortID, PIN Copy_enumPin);
		EXISTENCE Check_voidExistance(void);
};



#endif