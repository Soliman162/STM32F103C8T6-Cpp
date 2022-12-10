#ifndef MOTOR_INTERFACE_HPP
#define MOTOR_INTERFACE_HPP

#include "STD_TYPES.hpp"
#include "GPIO_interface.hpp"

class DC_Motor : public GPIO_CONFIG_t
{
	private :
		PIN CCW_Pin;
	public :
		DC_Motor(PORT Copy_enumPORT, PIN Copy_enumCW_PIN, PIN Copy_enumCCW_PIN );
	  void DC_Motor_voidRotate_CW(void);
		void DC_Motor_voidRotate_CCW(void);
		void DC_Motor_voidSTOP(void);
};


#endif