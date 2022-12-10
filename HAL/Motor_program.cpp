#include "STD_TYPES.hPP"

//#include "RCC_interface.h"
#include "GPIO_interface.hPP"

#include "Motor_interface.hpp"
#include "Motor_config.hpp"

DC_Motor::DC_Motor(PORT Copy_enumPORT, PIN Copy_enumCW_PIN, PIN Copy_enumCCW_PIN ) 
:GPIO_CONFIG_t(Copy_enumPORT,Copy_enumCW_PIN,MOTOR_OUTPUT_PINS_MODE), CCW_Pin(Copy_enumCCW_PIN)
{
	SET_voidPin_Mode();
	SET_voidPin_Mode(Copy_enumPORT,CCW_Pin,MOTOR_OUTPUT_PINS_MODE);
	/* Clk wise pin  low */
	GPIO_voidSETPinValue(  PIN_VALUE::GPIO_LOW );
	/* Counter clk wise pin high */
  GPIO_voidSETPinValue(Port_ID, CCW_Pin, PIN_VALUE::GPIO_LOW );
}
void DC_Motor::DC_Motor_voidRotate_CW(void)
{
	/* Clk wise pin  high */
	GPIO_voidSETPinValue(  PIN_VALUE::GPIO_HIGH );
	/* Counter clk wise pin low */
  GPIO_voidSETPinValue(Port_ID, CCW_Pin, PIN_VALUE::GPIO_LOW );
}
void DC_Motor::DC_Motor_voidRotate_CCW(void)
{
	/* Clk wise pin  low */
	GPIO_voidSETPinValue(  PIN_VALUE::GPIO_LOW );
	/* Counter clk wise pin high */
  GPIO_voidSETPinValue(Port_ID, CCW_Pin, PIN_VALUE::GPIO_HIGH );
}
void DC_Motor::DC_Motor_voidSTOP(void)
{
	/* Clk wise pin  low */
	GPIO_voidSETPinValue(  PIN_VALUE::GPIO_LOW );
	/* Counter clk wise pin high */
  GPIO_voidSETPinValue(Port_ID, CCW_Pin, PIN_VALUE::GPIO_LOW );
}	
	