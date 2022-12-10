#include "STD_TYPES.hpp"
#include "BIT_MATH.hpp"
#include "STM32F103C8.hpp"

#include "..\include\GPIO_interface.h"
#include "..\include\SysTick_interface.h"

#include "..\include\LEDMatrix_interface.h"
#include "..\include\LEDMatrix_private.h"
#include "..\include\LEDMatrix_config.h"

GPIO_CONFIG_t ROW[8];
GPIO_CONFIG_t COL[8];

void LEDMatrix_voidInit(void)
{
    u8 LOC_u8Iterator_1 = 0;

    STK_voidInit();

    for( LOC_u8Iterator_1=LEDMatrix_ROW_PIN_0 ;LOC_u8Iterator_1<=LEDMatrix_ROW_PIN_7 ;LOC_u8Iterator_1++)
    {
        ROW[LOC_u8Iterator_1].PORT_ID = LEDMatrix_ROW_PORT;
        ROW[LOC_u8Iterator_1].PIN_NUM = LOC_u8Iterator_1;
        ROW[LOC_u8Iterator_1].PIN_MODE =GENERAL_PURPOSE_OUTPUT_PUSH_PULL_2MHZ;
    }

    for( LOC_u8Iterator_1=LEDMatrix_COL_PIN_0 ;LOC_u8Iterator_1<=LEDMatrix_COL_PIN_7 ;LOC_u8Iterator_1++)
    {
        if( ( LOC_u8Iterator_1 == PIN_2 ) || ( LOC_u8Iterator_1 == PIN_3 ) || ( LOC_u8Iterator_1 == PIN_4 ) )
        {
            continue;
        }else{

            COL[LOC_u8Iterator_1].PORT_ID  = LEDMatrix_COL_PORT;
            COL[LOC_u8Iterator_1].PIN_NUM  = LOC_u8Iterator_1;
    		COL[LOC_u8Iterator_1].PIN_MODE = GENERAL_PURPOSE_OUTPUT_PUSH_PULL_2MHZ ;
        }

    }

    for( LOC_u8Iterator_1 = 0 ;LOC_u8Iterator_1 < 8 ;LOC_u8Iterator_1++)
    {
        GPIO_enumSETPinMODE( &ROW[LOC_u8Iterator_1] );
        GPIO_enumSETPinMODE( &COL[LOC_u8Iterator_1] );
    }

}

ERROR_enumSTATE LEDMatrix_voidDisplay( u8 *Copy_pu8Data )
{
    ERROR_enumSTATE LOC_enumError_State = STD_TYPES_OK ;

    u8 LOC_u8Iterator_1 = 0;
    u8 LOC_u8Iterator_2 = 0;
    u8 LOC_u8Iterator_3 = 0;
    u8 LOC_u8Data = 0;

    if( Copy_pu8Data != NULL )
    {

        for(LOC_u8Iterator_1 = 0;LOC_u8Iterator_1<8;LOC_u8Iterator_1++)
        {

            for( LOC_u8Iterator_3 = 0 ;LOC_u8Iterator_3 < 8 ;LOC_u8Iterator_3++)
            {
                GPIO_enumSETPinValue( &COL[LOC_u8Iterator_3] ,GPIO_HIGH );
            }

            for(LOC_u8Iterator_2 = 0;LOC_u8Iterator_2<8;LOC_u8Iterator_2++)
            {
                LOC_u8Data = GET_BIT(Copy_pu8Data[LOC_u8Iterator_1],LOC_u8Iterator_2);
                GPIO_enumSETPinValue( &ROW[LOC_u8Iterator_2] ,LOC_u8Data );
                GPIO_enumSETPinValue( &COL[LOC_u8Iterator_1] ,GPIO_LOW );
            }

            STK_voidSetBusyWait(2500);
        }

    }else{ LOC_enumError_State = STD_TYPES_NOK; }

    return LOC_enumError_State;

}
