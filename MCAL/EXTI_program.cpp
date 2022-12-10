#include "STD_TYPES.hpp"
#include "BIT_MATH.hpp"
#include "STM32F103C8.hpp"

#include "EXTI_interface.hpp"
#include "EXTI_private.hpp"
#include "EXTI_config.hpp"

static void (*EXTI_addISR[16])(void) = {NULL};

EXTI_Def_t::EXTI_Def_t(PORT Copy_enumPort_ID, PIN Copy_enumPIN_num, TRIGGER_type Copy_enumTrigger_Type, void (*Copy_pfunc)(void))
	:GPIO_Pin(Copy_enumPort_ID,Copy_enumPIN_num),Trigger_Level(Copy_enumTrigger_Type),pfunc(Copy_pfunc)
{

}
void EXTI_Def_t::SET_voidPin_Mode(void)
{
   AFIO->EXTICR[static_cast<u8>(Pin_num)/4] &= (~(0b1111 << ((static_cast<u8>(Pin_num)%4)*4)));
   AFIO->EXTICR[static_cast<u8>(Pin_num)/4] |= ( static_cast<u8>(Port_ID) <<((static_cast<u8>(Pin_num)%4)*4) );

   switch (Trigger_Level)
   {
		 case TRIGGER_type::RISING_TRIGGER:
                  CLR_BIT(EXTI->FTSR , static_cast<u8>(Pin_num));
                  SET_BIT(EXTI->RTSR , static_cast<u8>(Pin_num));
                  break;
		 case TRIGGER_type::FALLING_TRIGGER:
                  CLR_BIT(EXTI->RTSR ,static_cast<u8>(Pin_num));
                  SET_BIT(EXTI->FTSR ,static_cast<u8>(Pin_num));
                  break;
   }
}
void EXTI_Def_t::EXTI_voidEnable_Interrupt( void )
{
  SET_BIT(EXTI->IMR , static_cast<u8>(Pin_num));
}

void EXTI_Def_t::EXTI_voidDisable_Interrupt( void )
{
  CLR_BIT(EXTI->IMR , static_cast<u8>(Pin_num));
}

void EXTI0_IRQHandler(void)
{
    if( EXTI_addISR[0] != NULL )
    {
        EXTI_addISR[0]();
    }
    SET_BIT(EXTI->PR ,0);
}
void EXTI1_IRQHandler(void)
{
    if( EXTI_addISR[1] != NULL)
    {
        EXTI_addISR[1]();
    }
    SET_BIT(EXTI->PR ,1);
}
void EXTI2_IRQHandler(void)
{
    if( EXTI_addISR[2] != NULL)
    {
        EXTI_addISR[2]();
    }
    SET_BIT(EXTI->PR ,2);
}
void EXTI3_IRQHandler(void)
{
    if( EXTI_addISR[3] != NULL)
    {
        EXTI_addISR[3]();
    }
    SET_BIT(EXTI->PR ,3);
}
void EXTI4_IRQHandler(void)
{
    if( EXTI_addISR[4] != NULL)
    {
        EXTI_addISR[4]();
    }
    SET_BIT(EXTI->PR ,4);
}
