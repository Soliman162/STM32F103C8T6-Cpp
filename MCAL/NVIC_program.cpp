/*******************************************************************************/
/******************* Name : Ahmed Elsayed **************************************/
/******************* Date : 6/8/2021      **************************************/
/******************* Version : 1.0v       **************************************/ 
/******************* SWC : NVIC_program.c **************************************/ 
/*******************************************************************************/
#include "STD_TYPES.hpp"
#include "BIT_MATH.hpp"
#include "STM32F103C8.hpp"

#include "NVIC_interface.hpp"
#include "NVIC_private.hpp"
#include "NVIC_config.hpp"

#define SCB_u8_AIRCR_REG    *((volatile u32 *)(0xE000ED00 + 0x0C) )

void NVIC_voidEnableIRQ(IRQ_Type IRQn)
{
     NVIC->ISER[IRQn/32] = 1<<(IRQn%32);
}

void NVIC_voidDisableIRQ(IRQ_Type IRQn)
{
     NVIC->ICER[IRQn/32] = 1<<(IRQn%32);
}

void NVIC_voidSetPendingIRQ(IRQ_Type IRQn)
{
     NVIC->ISPR[IRQn/32] = 1<<(IRQn%32);
}

void NVIC_voidClearPendingIRQ(IRQ_Type IRQn)
{
     NVIC->ICPR[IRQn/32] = (1<<(IRQn%32));
}

IRQ_Check_State NVIC_enumGetPendingIRQ(IRQ_Type IRQn )
{
     return (static_cast<IRQ_Check_State>(GET_BIT( NVIC->ICPR[IRQn/32] ,IRQn%32 )));
}

IRQ_Check_State NVIC_enumGetActiveIRQ( IRQ_Type IRQn)
{
     return (static_cast<IRQ_Check_State>(GET_BIT( NVIC->IABR[IRQn/32] ,IRQn%32 )));
}

void NVIC_voidSetPriority(IRQ_Type IRQn, Group_priority_t GROUP_u8priority, SUB_Priority_t SUB_u8priority)
{
    NVIC->IPR[IRQn] = ( ( GROUP_u8priority << 6 ) | ( SUB_u8priority << 4) );
}
u8 NVIC_u8GetPriority(IRQ_Type IRQn)
{
     return( 0 | (NVIC->IPR[IRQn]) );
}

void Init_priority_field(void)
{   
    SCB_u8_AIRCR_REG = 0x05FA0500;
}
