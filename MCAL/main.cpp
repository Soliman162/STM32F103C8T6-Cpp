#include "STD_TYPES.hpp"
#include "BIT_MATH.hpp"
#include "STM32F103C8.hpp"

#include "RCC_interface.hpp"
#include "SysTick_interface.hpp"
#include "GPIO_interface.hpp"

#define Delay_Time	1000000000

int main (void)
{
	RCC_voidCLKInit();
	RCC_voidPeripheralCLKEnable( APB2_BUS ,IOPA_CLK);
	STK_voidInit();
	
	GPIO_CONFIG_t LED_1(PORT::GPIOA_PORT, PIN::PIN_0, PIN_MODE::GENERAL_PURPOSE_OUTPUT_OPEN_DRAIN_2MHZ);
	GPIO_CONFIG_t LED_2(PORT::GPIOA_PORT, PIN::PIN_1, PIN_MODE::GENERAL_PURPOSE_OUTPUT_OPEN_DRAIN_2MHZ);
	
	LED_1.SET_voidPin_Mode();
	LED_1.GPIO_voidSETPinValue(GPIO_LOW);
	
	LED_2.SET_voidPin_Mode(PORT::GPIOA_PORT, PIN::PIN_1, PIN_MODE::GENERAL_PURPOSE_OUTPUT_OPEN_DRAIN_2MHZ);
	LED_2.GPIO_voidSETPinValue(PORT::GPIOA_PORT, PIN::PIN_1, PIN_VALUE::GPIO_LOW);
	/*
			RCC 
				
					0x40021000 - 0x40021018
					0x40010800 - 0x40010814
	*/

	
	while(1)
	{
		LED_1.GPIO_voidSETPinValue(GPIO_HIGH);
		LED_2.GPIO_voidSETPinValue(PORT::GPIOA_PORT, PIN::PIN_1, PIN_VALUE::GPIO_HIGH);
		STK_voidSetBusyWait(Delay_Time);
		
		LED_1.GPIO_voidSETPinValue(GPIO_LOW);
		LED_2.GPIO_voidSETPinValue(PORT::GPIOA_PORT, PIN::PIN_1, PIN_VALUE::GPIO_LOW);
		STK_voidSetBusyWait(Delay_Time);

	}

	return 0;
}
