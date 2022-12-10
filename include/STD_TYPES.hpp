/*******************************************************************************/
/******************* Name : Ahmed Elsayed **************************************/
/******************* Date : 6/8/2021      **************************************/
/******************* Version : 1.0v       **************************************/ 
/******************* SWC : STD_TYPES.h *****************************************/ 
/*******************************************************************************/
#ifndef STD_H
#define STD_H

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef unsigned long long int u64;
typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef signed long long int s64;
typedef float f32;
typedef double f64;

enum class PORT : u8
{

    GPIOA_PORT=0,
    GPIOB_PORT=1,
    GPIOC_PORT=2,
		GPIOD_PORT,
		GPIOE_PORT,
		GPIOF_PORT,
		GPIOG_PORT

};

enum class PIN : u8
{

    PIN_0=0,
    PIN_1,
    PIN_2,
    PIN_3,
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7,
    PIN_8,
    PIN_9,
    PIN_10,
    PIN_11,
    PIN_12,
    PIN_13,
    PIN_14,
    PIN_15

};

class GPIO_Pin
{
	private :
		PORT Port_ID;
		PIN  Pin_num;
	  friend class EXTI_Def_t;
	  friend class GPIO_CONFIG_t;
	public :
		GPIO_Pin(PORT Copy_enumport_id,PIN copy_enumPin_num): Port_ID(Copy_enumport_id),Pin_num(copy_enumPin_num){}
		virtual void SET_voidPin_Mode(void) = 0;
	
};

enum class ERROR_enumSTATE : u8
{
	
	STD_TYPES_NOK=0,
	STD_TYPES_OK
	
};

//#define NULL 	((void *)0)
#define NULL nullptr


#endif