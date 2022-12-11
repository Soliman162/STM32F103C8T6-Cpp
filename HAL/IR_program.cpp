#include "STD_TYPES.hpp"
#include "BIT_MATH.hpp"
#include "STM32F103C8.hpp"

#include "GPIO_interface.hpp"
#include "NVIC_interface.hpp"
#include "EXTI_interface.hpp"
#include "SysTick_interface.hpp"

#include "IR_interface.hpp"
#include "IR_private.hpp"
#include "IR_config.hpp"
/*
GPIO_CONFIG_t  IR(IR_PORT,IR_PIN,PIN_MODE::INPUT_FLOATING);
//EXTI_Def_t     IR_Int_PIN ;

volatile u8 LOC_u8Flag = 0;
volatile u32 LOC_u32Timer_Value[50] = {0}  ;
volatile u8 LOC_u8Iterator = 0;

IR::IR(PORT Copy_enumPortID, PIN Copy_enumPin)
:GPIO_CONFIG_t(Copy_enumPortID , Copy_enumPin, PIN_MODE::INPUT_FLOATING ),
EXTI_Def_t( Copy_enumPortID,  Copy_enumPin,  TRIGGER_type::FALLING_TRIGGER, IR_enumReceive_Signal )
{


}


void IR_voidInit(void)
{
	
    STK_voidInit();
    GPIO_enumSETPinMODE(&IR);
    NVIC_voidEnableIRQ(EXTI0_IR);
    Init_priority_field();
    NVIC_SetPriority(EXTI0_IR, Group_u8Priority_0, SUB_u8Priority_0);

    IR_Int_PIN.PORT_ID = IR_PORT;
    IR_Int_PIN.EXTI_PIN_NUM =IR_PIN;
    IR_Int_PIN.Trigger_Level =FALLING_TRIGGER;
    IR_Int_PIN.pfunc = IR_enumReceive_Signal;

    EXTI_enumInit_Interrupt(&IR_Int_PIN);
    EXTI_enumEnable_Interrupt(&IR_Int_PIN);
	
}

static void IR_enumReceive_Signal(void)
{
    if( LOC_u8Flag ==0 )
    {
        STK_enumSetIntervalSingle(500000,&Restart_voidTimer);
        LOC_u8Flag = 1;
    }else
    {
        STK_enumGetElapsedTime(&LOC_u32Timer_Value[LOC_u8Iterator++]);
        STK_voidStopTimer();
        STK_enumSetIntervalSingle(500000,&Restart_voidTimer);
				LOC_u8Flag = 0;
    }
}

static void Restart_voidTimer(void)
{
    if( LOC_u8Iterator >= 50 )
    {
        STK_voidStopTimer();
        LOC_u8Iterator = 0;
        //LOC_u8Flag = 0;
    }
}

void IR::IR_voidSave_Data(void)
{
	u8 LOC_u8Iterator = 0;
	if( (LOC_u32Timer_Value[0] >= 1000) && (LOC_u32Timer_Value[0] <= 14000) )
	{
		for(LOC_u8Iterator=0;LOC_u8Iterator<8;LOC_u8Iterator++)
		{
			if( (LOC_u32Timer_Value[LOC_u8Iterator+17] >=2000) && (LOC_u32Timer_Value[LOC_u8Iterator+17] <=2400)  )
			{
				TOG_BIT(Data_u8,LOC_u8Iterator);
			}
		}
	}

}

u8 IR::IR_voidGET_Data(void)
{
	return Data_u8;
}
*/
