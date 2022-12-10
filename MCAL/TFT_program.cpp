#include "STD_TYPES.hpp"
#include "BIT_MATH.hpp"
#include "STM32F103C8.hpp"

#include "..\include\GPIO_interface.h"
#include "..\include\SysTick_interface.h"
#include "..\include\SPI1_interface.h"

#include "..\include\TFT_interface.h"
#include "..\include\TFT_private.h"
#include "..\include\TFT_config.h"

GPIO_CONFIG_t  SPI1_SCK_PIN  = {GPIOA_PORT,PIN_5,ALTERNATE_FUNCTION_PUSH_PULL_OUTPUT_10MHZ};
GPIO_CONFIG_t  SPI1_MISO_PIN = {GPIOA_PORT,PIN_6,INPUT_FLOATING};
GPIO_CONFIG_t  SPI1_MOSI_PIN = {GPIOA_PORT,PIN_7,ALTERNATE_FUNCTION_PUSH_PULL_OUTPUT_10MHZ};

GPIO_CONFIG_t  TFT_RESET_PIN = {GPIOA_PORT,PIN_1,GENERAL_PURPOSE_OUTPUT_PUSH_PULL_10MHZ};
GPIO_CONFIG_t  TFT_A0_PIN    = {GPIOA_PORT,PIN_2,GENERAL_PURPOSE_OUTPUT_PUSH_PULL_10MHZ};

void TFT_voidInit(void)
{

    GPIO_enumSETPinMODE(&SPI1_SCK_PIN);   
    GPIO_enumSETPinMODE(&SPI1_MISO_PIN);
    GPIO_enumSETPinMODE(&SPI1_MOSI_PIN);

    GPIO_enumSETPinMODE(&TFT_RESET_PIN);
    GPIO_enumSETPinMODE(&TFT_A0_PIN);

    GPIO_enumSETPinValue(&TFT_RESET_PIN,GPIO_HIGH);
    STK_voidSetBusyWait(100);

    GPIO_enumSETPinValue(&TFT_RESET_PIN,GPIO_LOW);
    STK_voidSetBusyWait(1);

    GPIO_enumSETPinValue(&TFT_RESET_PIN,GPIO_HIGH);
    STK_voidSetBusyWait(100);

    GPIO_enumSETPinValue(&TFT_RESET_PIN,GPIO_LOW);
    STK_voidSetBusyWait(100);

    GPIO_enumSETPinValue(&TFT_RESET_PIN,GPIO_HIGH);
    STK_voidSetBusyWait(120000);

    TFT_voidWriteCommand(0x11);
    STK_voidSetBusyWait(150000);

    TFT_voidWriteCommand(0x3A);
    TFT_voidWriteData(0x05);
    TFT_voidWriteCommand(0x29);

}

ERROR_enumSTATE TFT_voidDisplay_Image(const u16 *Copy_u16PIC)
{
    ERROR_enumSTATE LOC_enumError_State = STD_TYPES_OK;
    if( Copy_u16PIC != NULL)
    {
        TFT_voidWriteCommand(0x2A);
        TFT_voidWriteData(0);
        TFT_voidWriteData(0);

        TFT_voidWriteData(0);
        TFT_voidWriteData(127);


        TFT_voidWriteCommand(0x2B);
        TFT_voidWriteData(0);
        TFT_voidWriteData(0);

        TFT_voidWriteData(0);
        TFT_voidWriteData(159);

        TFT_voidWriteCommand(0x2C);

        for(u16 i= 0;i<20480;i++)
        {
            TFT_voidWriteData( Copy_u16PIC[i]>>8 );
            TFT_voidWriteData( Copy_u16PIC[i] & 0xFF );
        }
    }else
    {
        LOC_enumError_State = STD_TYPES_NOK;
    }
    return LOC_enumError_State;
}
void TFT_voidWriteCommand(u8 Copy_u8Command)
{
    u16 LOC_R = 0;
    GPIO_enumSETPinValue(&TFT_A0_PIN,GPIO_LOW);
    SPI1_voidTransmite_Recieve(Copy_u8Command,&LOC_R);

}
void TFT_voidWriteData(u8 Copy_Data)
{
    u16 LOC_R = 0;
    GPIO_enumSETPinValue(&TFT_A0_PIN,GPIO_HIGH);
    SPI1_voidTransmite_Recieve(Copy_Data,&LOC_R);
    
}
