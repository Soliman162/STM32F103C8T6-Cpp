#include "STD_TYPES.hPP"

//#include "RCC_interface.h"
#include "GPIO_interface.hPP"

#include "Motor_interface.hpp"
#include "Motor_config.hpp"
/*
DC_Motor::DC_Motor(PORT Copy_enumPORT, PIN Copy_enumCW_PIN, PIN Copy_enumCCW_PIN ) 
:GPIO_CONFIG_t(Copy_enumPORT,Copy_enumCW_PIN,MOTOR_OUTPUT_PINS_MODE), CCW_Pin(Copy_enumCCW_PIN)
{
	SET_voidPin_Mode();
	SET_voidPin_Mode(Copy_enumPORT,CCW_Pin,MOTOR_OUTPUT_PINS_MODE);

	GPIO_voidSETPinValue(  PIN_VALUE::GPIO_LOW );

  GPIO_voidSETPinValue(Port_ID, CCW_Pin, PIN_VALUE::GPIO_LOW );
}
void DC_Motor::DC_Motor_voidRotate_CW(void)
{
	
	
	GPIO_voidSETPinValue(  PIN_VALUE::GPIO_HIGH );

  GPIO_voidSETPinValue(Port_ID, CCW_Pin, PIN_VALUE::GPIO_LOW );
}
void DC_Motor::DC_Motor_voidRotate_CCW(void)
{

	GPIO_voidSETPinValue(  PIN_VALUE::GPIO_LOW );

  GPIO_voidSETPinValue(Port_ID, CCW_Pin, PIN_VALUE::GPIO_HIGH );
}
void DC_Motor::DC_Motor_voidSTOP(void)
{

	GPIO_voidSETPinValue(  PIN_VALUE::GPIO_LOW );

  GPIO_voidSETPinValue(Port_ID, CCW_Pin, PIN_VALUE::GPIO_LOW );
}	
	*/