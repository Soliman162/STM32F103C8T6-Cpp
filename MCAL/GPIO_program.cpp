#include "STD_TYPES.hpp"
#include "BIT_MATH.hpp"
#include "STM32F103C8.hpp"

#include "GPIO_interface.hpp"

static GPIO_REG_DEF_t * GPIO_PORT[5] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE};

GPIO_CONFIG_t::GPIO_CONFIG_t(PORT Copy_enumPortID, PIN Copy_enumPin, PIN_MODE Copy_Pin_Mode)
:GPIO_Pin(Copy_enumPortID,Copy_enumPin),Pin_Mode(Copy_Pin_Mode)
{
			  
}
void GPIO_CONFIG_t::SET_voidPin_Mode(void)
{
				u8 Copy_u8pinNUM = static_cast<u8>(Pin_num);
	
				if( Pin_Mode ==  PIN_MODE::INPUT_PULL_UP )
				{
					GPIO_PORT[static_cast<u8>(Port_ID)]->BSRR = (1<<static_cast<u8>(Pin_num));
					//Pin_Mode = (static_cast<PIN_MODE>(0b1000));

				}else if( Pin_Mode ==  PIN_MODE::INPUT_PULL_DOWN )
				{
					GPIO_PORT[static_cast<u8>(Port_ID)]->BRR = (1<<static_cast<u8>(Pin_num));
				}

				if( Pin_num <= PIN::PIN_7 )
				{
					(GPIO_PORT[static_cast<u8>(Port_ID)]->CRL) &=  (~(0b1111<<(static_cast<u8>(Pin_num) * 4) ) );
					(GPIO_PORT[static_cast<u8>(Port_ID)]->CRL) |=  ( static_cast<u8>(Pin_Mode) << ( static_cast<u8>(Pin_num) * 4 ) );

				}else if( Pin_num >= PIN::PIN_8 )
				{
					Copy_u8pinNUM -= 8;
					GPIO_PORT[static_cast<u8>(Port_ID)]->CRH &=  (~(0b1111<< (Copy_u8pinNUM * 4) ) ) ;
					GPIO_PORT[static_cast<u8>(Port_ID)]->CRH |=  ( static_cast<u8>(Pin_Mode) << (  Copy_u8pinNUM * 4) );
				}
				
}
void GPIO_CONFIG_t::SET_voidPin_Mode(PORT Copy_enumPortID, PIN Copy_enumPin, PIN_MODE Copy_Pin_Mode)
{
				u8 Copy_u8pinNUM = static_cast<u8>(Copy_enumPin);
	
				if( Copy_Pin_Mode ==  PIN_MODE::INPUT_PULL_UP )
				{
					GPIO_PORT[static_cast<u8>(Copy_enumPortID)]->BSRR = (1<<static_cast<u8>(Copy_enumPin));
					//Pin_Mode = (static_cast<PIN_MODE>(0b1000));

				}else if( Copy_Pin_Mode ==  PIN_MODE::INPUT_PULL_DOWN )
				{
					GPIO_PORT[static_cast<u8>(Copy_enumPortID)]->BRR = (1<<static_cast<u8>(Copy_enumPin));
				}

				if( Copy_enumPin <= PIN::PIN_7 )
				{
					(GPIO_PORT[static_cast<u8>(Copy_enumPortID)]->CRL) &=  (~(0b1111<<(static_cast<u8>(Copy_enumPin) * 4) ) );
					(GPIO_PORT[static_cast<u8>(Copy_enumPortID)]->CRL) |=  ( static_cast<u8>(Copy_Pin_Mode) << ( static_cast<u8>(Copy_enumPin)*4));

				}else if( Copy_enumPin >= PIN::PIN_8 )
				{
					Copy_u8pinNUM -= 8;
					
					GPIO_PORT[static_cast<u8>(Copy_enumPortID)]->CRH &=  (~(0b1111<< (Copy_u8pinNUM * 4) ) ) ;
					GPIO_PORT[static_cast<u8>(Copy_enumPortID)]->CRH |=  ( static_cast<u8>(Copy_Pin_Mode) << (Copy_u8pinNUM*4));
				}
}
void GPIO_CONFIG_t::GPIO_voidSETPinValue (PIN_VALUE Pin_u8Value )
{
			if( Pin_u8Value == PIN_VALUE::GPIO_HIGH )
			{
					GPIO_PORT[static_cast<u8>(Port_ID)]->BSRR = (1<<static_cast<u8>(Pin_num));

			}else if (Pin_u8Value == PIN_VALUE::GPIO_LOW )
			{
					GPIO_PORT[static_cast<u8>(Port_ID)]->BRR = (1<<static_cast<u8>(Pin_num));
			}
}
void GPIO_voidSETPinValue( PORT Copy_enumPortID, PIN Copy_enumPin,PIN_VALUE Pin_u8Value )
{
			if( Pin_u8Value == PIN_VALUE::GPIO_HIGH )
			{
					GPIO_PORT[static_cast<u8>(Copy_enumPortID)]->BSRR = (1<<static_cast<u8>(Copy_enumPin));

			}else if (Pin_u8Value == PIN_VALUE::GPIO_LOW )
			{
					GPIO_PORT[static_cast<u8>(Copy_enumPortID)]->BRR = (1<<static_cast<u8>(Copy_enumPin));
			}
}
PIN_VALUE GPIO_CONFIG_t::GPIO_enumGETPinValue (void)
{
	 return (static_cast<PIN_VALUE>(GET_BIT(GPIO_PORT[static_cast<u8>(Port_ID)]->IDR , static_cast<u8>(Pin_num))));
}
/*
ERROR_enumSTATE GPIO_enumSETPinMODE( const GPIO_CONFIG_t * Copy_ptru8PIN )
{

	ERROR_enumSTATE LOC_u8State = ERROR_enumSTATE::STD_TYPES_OK;
	u8 LOC_u8CopyMode ;
	u8 LOc_u8CopyPin_num;
	u8 LOC_u8CopyPort_ID;

	if(Copy_ptru8PIN != NULL){

		LOC_u8CopyMode = Copy_ptru8PIN->PIN_MODE;
		LOc_u8CopyPin_num = Copy_ptru8PIN->PIN_NUM;
		LOC_u8CopyPort_ID =Copy_ptru8PIN->PORT_ID;

		if(  LOC_u8CopyPort_ID <= GPIOC_PORT )
		{
			if( LOc_u8CopyPin_num<=PIN_15 )
			{
				if( LOC_u8CopyMode ==  INPUT_PULL_UP )
				{
					GPIO_PORT[LOC_u8CopyPort_ID]->BSRR = (1<<LOc_u8CopyPin_num);
					LOC_u8CopyMode = 0b1000;

				}else if( LOC_u8CopyMode ==  INPUT_PULL_DOWN )
				{
					GPIO_PORT[LOC_u8CopyPort_ID]->BRR = (1<<LOc_u8CopyPin_num);
				}

				if( LOc_u8CopyPin_num<=PIN_7 )
				{
					(GPIO_PORT[LOC_u8CopyPort_ID]->CRL) &=  (~(0b1111<<(LOc_u8CopyPin_num * 4) ) );
					(GPIO_PORT[LOC_u8CopyPort_ID]->CRL) |=  ( LOC_u8CopyMode << ( LOc_u8CopyPin_num * 4 ) );

				}else if( LOc_u8CopyPin_num>=PIN_8 )
				{
					LOc_u8CopyPin_num-=8;
					GPIO_PORT[LOC_u8CopyPort_ID]->CRH &=  (~(0b1111<< (LOc_u8CopyPin_num * 4) ) ) ;
					GPIO_PORT[LOC_u8CopyPort_ID]->CRH |=  ( LOC_u8CopyMode << (  LOc_u8CopyPin_num * 4) );
				}

				}else{LOC_u8State = ERROR_enumSTATE::STD_TYPES_NOK;}

				}else{ LOC_u8State = ERROR_enumSTATE::STD_TYPES_NOK; }

				}else{ LOC_u8State = ERROR_enumSTATE::STD_TYPES_NOK; }

	return LOC_u8State;
}


ERROR_enumSTATE GPIO_enumSETPinValue( const GPIO_CONFIG_t * Copy_ptru8PIN  , u8 Pin_u8Value )
{
	ERROR_enumSTATE LOC_u8State = ERROR_enumSTATE::STD_TYPES_OK;

	if( Copy_ptru8PIN !=NULL){

		if( Copy_ptru8PIN->PORT_ID<=GPIOC_PORT )
		{
			if( Copy_ptru8PIN->PIN_NUM<=PIN_15 )
			{
				if( Pin_u8Value == GPIO_HIGH )
				{
					GPIO_PORT[Copy_ptru8PIN->PORT_ID]->BSRR = (1<<Copy_ptru8PIN->PIN_NUM);

				}else if (Pin_u8Value == GPIO_LOW )
				{
					GPIO_PORT[Copy_ptru8PIN->PORT_ID]->BRR = (1<<Copy_ptru8PIN->PIN_NUM);
				}
				}else{ LOC_u8State = ERROR_enumSTATE::STD_TYPES_NOK; }

				}else{ LOC_u8State = ERROR_enumSTATE::STD_TYPES_NOK; }
	}
	return LOC_u8State;
}


ERROR_enumSTATE GPIO_enumGETPinValue( const GPIO_CONFIG_t * Copy_ptru8PIN  , u8 *Pin_ptru8Value )
{

	ERROR_enumSTATE LOC_u8State = ERROR_enumSTATE::STD_TYPES_OK;

	if( Copy_ptru8PIN !=NULL )
	{
		if( Pin_ptru8Value != NULL)
		{
			if( Copy_ptru8PIN->PORT_ID<=GPIOC_PORT )
			{
				if( Copy_ptru8PIN->PIN_NUM<=PIN_15 )
				{
					*Pin_ptru8Value = GET_BIT( GPIO_PORT[Copy_ptru8PIN->PORT_ID]->IDR , Copy_ptru8PIN->PIN_NUM );

					}else{ LOC_u8State = ERROR_enumSTATE::STD_TYPES_NOK; }

					}else{ LOC_u8State = ERROR_enumSTATE::STD_TYPES_NOK; }
		}
	}

	return LOC_u8State;
}
*/