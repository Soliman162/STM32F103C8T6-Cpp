#ifndef EXTI_interface_H
#define EXTI_interface_H

#include "STD_TYPES.hpp"
/*
enum class EXTI_PORT_Config : u8
{

    EXTI_PORTA = 0b0000,    
    EXTI_PORTB = 0b0001,
    EXTI_PORTC = 0b0010,
    EXTI_PORTD = 0b0011,
    EXTI_PORTE = 0b0100,
    EXTI_PORTF = 0b0101,
    EXTI_PORTG = 0b0110

};

enum class EXTI_PIN_NUM_Config : u8
{
    EXTI_PIN_0=0,
    EXTI_PIN_1,
    EXTI_PIN_2,
    EXTI_PIN_3,
    EXTI_PIN_4,
    EXTI_PIN_5,
    EXTI_PIN_6,
    EXTI_PIN_7,
    EXTI_PIN_8,
    EXTI_PIN_9,
    EXTI_PIN_10,
    EXTI_PIN_11,
    EXTI_PIN_12,
    EXTI_PIN_13,
    EXTI_PIN_14,
    EXTI_PIN_15

};
*/
enum class TRIGGER_type : u8
{
    FALLING_TRIGGER,
    RISING_TRIGGER

};

class EXTI_Def_t : public GPIO_Pin
{
	private :
		
		//EXTI_PORT_Config        PORT_ID;
    //EXTI_PIN_NUM_Config     EXTI_PIN_NUM;
    TRIGGER_type            Trigger_Level;
    void (*pfunc) (void);
	public :
		
		EXTI_Def_t(PORT Copy_enumPort_ID, PIN Copy_enumPIN_num, TRIGGER_type Copy_enumTrigger_Type, void (*Copy_pfunc)(void));
		void SET_voidPin_Mode(void);	
		void EXTI_voidEnable_Interrupt  (void);
		void EXTI_voidDisable_Interrupt (void);
};

#endif